package com.example.JournalArticles.model;

import com.example.JournalArticles.domain.Article;

import java.sql.*;
import java.util.*;
import java.util.Date;

public class DBConnection {
    private static Connection connection;

    public static void connect(){
        if (connection == null){
            String url="jdbc:mysql://127.0.0.1:3306/jspDatabase";
            try{
                Class.forName("com.mysql.cj.jdbc.Driver");
                connection = DriverManager.getConnection(url, "test", "fliperdaru2");
            }
            catch (Exception e){
                e.printStackTrace();
            }
        }
    }

    public static void disconnect() {
        try {
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        connection = null;
    }

    public static Connection getConnection() {
        if(connection == null)
            connect();
        return connection;
    }

    public static ArrayList<Article> getAllArticles(String journal, String user){
        ArrayList<Article> articles = new ArrayList<>();
        ResultSet resultSet;
        try{

            connect();
            Statement statement =connection.createStatement();
            resultSet=statement.executeQuery("select * from journal where name = '" + journal + "'");
            if(resultSet.next()){
                int journalID=resultSet.getInt("id");
                resultSet= statement.executeQuery("select * from article where journalid = "+journalID+" and user = '" + user + "'");
                while(resultSet.next()){
                    Article article = new Article(resultSet.getInt("id"), resultSet.getString("user"),
                            resultSet.getInt("journalid"), resultSet.getString("summary"), resultSet.getTimestamp("date"));
                    System.out.println(article);
                    articles.add(article);
                }
            }

        } catch (SQLException e){
            e.printStackTrace();
        }

        return articles;
    }

    public static Article addArticle(String journalName, String summary, String user){
        ResultSet resultSet;
        int journalID = 0;
        Date date= new Date();
        long time = date.getTime();
        Timestamp ts = new Timestamp(time);
        try{
            connect();
            Statement statement1 =connection.createStatement();
            resultSet=statement1.executeQuery("select * from journal where name = '" + journalName + "'");
            if(resultSet.next()) {
                journalID = resultSet.getInt("id");
            }
            else{
                PreparedStatement preparedStatement1 = connection.prepareStatement("insert into journal (name) values (?)",
                        Statement.RETURN_GENERATED_KEYS);
                preparedStatement1.setString(1, journalName);
                int affectedRows = preparedStatement1.executeUpdate();

                resultSet=statement1.executeQuery("select * from journal where name = '" + journalName + "'");
                if(resultSet.next() && affectedRows > 0) {
                    journalID = resultSet.getInt("id");
                }
                else
                    return null;
            }
            PreparedStatement preparedStatement = connection.prepareStatement("insert into article (user, journalid, summary, date) values (?,?,?,?)",
                    Statement.RETURN_GENERATED_KEYS);
            preparedStatement.setString(1, user);
            preparedStatement.setInt(2, journalID);
            preparedStatement.setString(3, summary);
            preparedStatement.setTimestamp(4, ts);

            int affectedRows = preparedStatement.executeUpdate();
            if (affectedRows > 0){
                ResultSet generatedKeys = preparedStatement.getGeneratedKeys();
                if(generatedKeys.next()) {
                    return new Article(0, user, journalID, summary, ts);
                }
                else
                    return null;
            }
        }catch (SQLException e){
            e.printStackTrace();
        }

        return null;
    }

    public static int countArticles(){
        ResultSet resultSet;
        int noArticles=0;
        try{
            connect();
            Statement statement1 =connection.createStatement();
            resultSet=statement1.executeQuery("select count(*) as nrA from article");
            if(resultSet.next()) {
                noArticles = resultSet.getInt("nrA");

                return noArticles;
            }
        }catch (SQLException e){
            e.printStackTrace();
        }

        return noArticles;
    }
}
