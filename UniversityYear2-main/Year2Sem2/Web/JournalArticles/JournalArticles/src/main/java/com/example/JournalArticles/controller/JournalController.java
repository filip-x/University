package com.example.JournalArticles.controller;

import com.example.JournalArticles.domain.Article;
import com.example.JournalArticles.model.DBConnection;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class JournalController extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String action = request.getParameter("action");
        System.out.println(action);

        if(action!=null && action.equals("getArticles")){
            JSONArray jsonAssets = new JSONArray();
            PrintWriter out = new PrintWriter(response.getOutputStream());

            String user = (String) request.getSession().getAttribute("user");
            String journal = request.getParameter("journalName");
            System.out.println(user+" "+journal);
            ArrayList<Article> articles = DBConnection.getAllArticles(journal, user);

            JSONObject answer = new JSONObject();
            for(Article a : articles){
                JSONObject jsonObject = new JSONObject();
                jsonObject.put("id", a.getId());
                jsonObject.put("user", a.getUser());
                jsonObject.put("journalid", a.getJournalid());
                jsonObject.put("summary", a.getSummary());
                jsonObject.put("date", a.getDate().toString());

                jsonAssets.add(jsonObject);
            }
            answer.put("articles", jsonAssets);
            out.println(answer);
            out.flush();
        }


        if(action!=null && action.equals("addArticle")){
            String user = (String) request.getSession().getAttribute("user");
            String journal = request.getParameter("journalName");
            String summary = request.getParameter("summary");

            System.out.println(user +" "+journal+" "+summary);
            Article article = DBConnection.addArticle(journal, summary, user);
            if(article != null){
                System.out.println("yay");
            }
            else{
                System.out.println("ohno");
            }
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String action = request.getParameter("action");
        System.out.println(action);
        if ((action != null) && action.equals("noArticles")) {
            PrintWriter out = new PrintWriter(response.getOutputStream());
            JSONObject answer = new JSONObject();

            int noArticles = DBConnection.countArticles();

            answer.put("number", noArticles);
            out.println(answer);
            out.flush();
        }
    }
}
