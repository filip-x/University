package com.example.Lab9;


import java.io.Serializable;
import java.sql.*;
import java.util.Properties;

import java.util.*;
import java.util.function.Supplier;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import com.fasterxml.jackson.*;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ArrayNode;

public class BazaDeDate implements Serializable{
    private Connection  jdbcConnection;
    public BazaDeDate()
    {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String jdbcUrl  = "jdbc:mysql://localhost:3306/Lab9?useSSL=false&allowPublicKeyRetrieval=true";
            Properties properties = new Properties();
            properties.put("user","Lab9user");
            properties.put("password","123456");
            jdbcConnection = DriverManager.getConnection(jdbcUrl,properties);
        }
        catch (ClassNotFoundException | SQLException e)
        {
            e.printStackTrace();
        }
    }
     public String register(String username,String password){
        try{
            PreparedStatement statement = jdbcConnection.prepareStatement("INSERT INTO User (name, password) VALUES (?, ?)");
            statement.setString(1,username);
            statement.setString(2,password);
            statement.executeUpdate();
            return "Success Register";
        } catch (SQLException throwables) {
            throwables.printStackTrace();
            return "Failed Register";
        }
     }

     public List<String> login(String username,String password){

        try {
            PreparedStatement statement = jdbcConnection.prepareStatement("SELECT COUNT(*) FROM User WHERE name = ? AND password = ?");
            statement.setString(1,username);
            statement.setString(2,password);
            ResultSet resultSet = statement.executeQuery();
            resultSet.next();
            int count = resultSet.getInt(1);
            if(count == 1){
                return Arrays.asList("0", "");
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        return Arrays.asList("1","Failed to connect!");
     }




    public int getUserIdFromUsername(String username) {
        try {
            PreparedStatement statement = jdbcConnection.prepareStatement("SELECT id_user FROM User WHERE name = ?");
            statement.setString(1, username);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next())
                return resultSet.getInt("id_user");
            else return -1;
        } catch (SQLException throwable) {
            throwable.printStackTrace();
        }
        return -1;
    }

    public List<String> loadTopics() {
        try {
            ArrayList<String> topics = new ArrayList<>();
            PreparedStatement statement = jdbcConnection.prepareStatement("SELECT * FROM Topic");
            ResultSet resultSet = statement.executeQuery();
            while(resultSet.next()) {
                topics.add(resultSet.getString(1));
                topics.add(resultSet.getString(2));
            }
            return topics;
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        return null;
    }

    public void addTopic(String name )
    {
        try{
            PreparedStatement statement = jdbcConnection.prepareStatement("INSERT INTO Topic (name) VALUES (?)");
            statement.setString(1,name);
            statement.executeUpdate();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }
    public List<String> loadMessages(int topicId) {
        try {
            ArrayList<String> topics = new ArrayList<>();
            PreparedStatement statement = jdbcConnection.prepareStatement("SELECT text, id_message, id_user FROM Message WHERE id_topic = ?");
            statement.setInt(1, topicId);
            ResultSet resultSet = statement.executeQuery();
            while(resultSet.next()) {
                topics.add(resultSet.getString(1));
                topics.add(resultSet.getString(2));
                topics.add(resultSet.getString(3));
            }
            return topics;
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        return null;
    }

    public void addMessage(String newMessage, int topicId, int userId) {
        try{
            PreparedStatement statement = jdbcConnection.prepareStatement("INSERT INTO Message (id_topic,id_user,text) VALUES (?,?,?)");
            statement.setInt(1,topicId);
            statement.setInt(2,userId);
            statement.setString(3,newMessage);
            statement.executeUpdate();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }

    public void removeMessage(int id_message, int id_user) {
        try{
            PreparedStatement statement = jdbcConnection.prepareStatement("DELETE FROM Message WHERE id_message =? and id_user =? ");
            statement.setInt(1, id_message);
            statement.setInt(2, id_user);
            statement.executeUpdate();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }
}