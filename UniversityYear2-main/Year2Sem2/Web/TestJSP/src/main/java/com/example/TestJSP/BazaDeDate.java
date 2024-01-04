package com.example.TestJSP;

import java.io.Serializable;
import java.sql.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Properties;

import java.util.Date;
public class BazaDeDate implements Serializable {

    private  static Connection jdbcConnection;

    public BazaDeDate()
    {
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            String jdbcUrl = "jdbc:mysql://localhost:3306/jspDatabase?useSSL=false&allowPublicKeyRetrieval=true";
            Properties properties = new Properties();
            properties.put("user","test");
            properties.put("password","fliperdaru2");
            jdbcConnection = DriverManager.getConnection(jdbcUrl,properties);
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }

    /*
    public void connect()
    {
        if(jdbcConnection == null)
        {
            String jdbcUrl = "jdbc:mysql://localhost:3306/jspDatabase?useSSL=false&allowPublicKeyRetrieval=true";
            try
            {
                Class.forName("com.mysql.cj.jdbc.Driver");
                Properties properties = new Properties();
                properties.put("user","test");
                properties.put("password","fliperdaru2");
                jdbcConnection = DriverManager.getConnection(jdbcUrl,properties);

            } catch (ClassNotFoundException | SQLException e) {
                e.printStackTrace();
            }
        }
    }
     */

    public static ArrayList<Article> getAllArticles(String journal,String user)
    {
        ArrayList<Article> articles = new ArrayList<>();
        ResultSet resultSet;
        try{
            PreparedStatement statement = jdbcConnection.prepareStatement("select * from Journal where name = ?");
            statement.setString(1,journal);
            resultSet = statement.executeQuery();
            if(resultSet.next())
            {
                int journalID =resultSet.getInt("id");
                resultSet = statement.executeQuery("select* from article where journalid ="+journalID+"and user"+user+"");
                while (resultSet.next())
                {
                    Article article = new Article(resultSet.getInt("id"), resultSet.getString("user"),
                            resultSet.getInt("journalid"), resultSet.getString("summary"), resultSet.getTimestamp("date"));
                    System.out.println(article);
                    articles.add(article);
                }
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        return articles;
    }
    public static Article addArticle(String journalName, String summary, String user){
        ResultSet resultSet;
        int journalID = 0;
        Date date = new Date();
        long time = date.getTime();
        Timestamp ts = new Timestamp(time);
        try{

            Statement statement1 =jdbcConnection.createStatement();
            resultSet=statement1.executeQuery("select * from journal where name = '" + journalName + "'");
            if(resultSet.next()) {
                journalID = resultSet.getInt("id");
            }
            else{
                PreparedStatement preparedStatement1 = jdbcConnection.prepareStatement("insert into journal (name) values (?)",
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
            PreparedStatement preparedStatement = jdbcConnection.prepareStatement("insert into article (user, journalid, summary, date) values (?,?,?,?)",
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

    public static int countArticles() {
        ResultSet resultSet;
        int noArticles = 0;
        try {

            Statement statement1 = jdbcConnection.createStatement();
            resultSet = statement1.executeQuery("select count(*) as nrA from article");
            if (resultSet.next()) {
                noArticles = resultSet.getInt("nrA");

                return noArticles;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return noArticles;
    }

}
