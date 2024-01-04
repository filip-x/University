package com.example.TestJSP;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

@WebServlet(name = "ServerRest", value = "/server-rest")
public class ServerRest extends HttpServlet {
   @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
       String action = request.getParameter("action");
       System.out.println(action);
       if(action!= null && action.equals("getArticles"))
       {
           JSONArray jsonAssets = new JSONArray();
           PrintWriter out = new PrintWriter(response.getOutputStream());

           String user = (String) request.getSession().getAttribute("user");
           String journal = request.getParameter("journalName");
           System.out.println(user+journal);
           ArrayList<Article> articles  = BazaDeDate.getAllArticles(journal,user);
           JSONObject answer = new JSONObject();
           for(Article a: articles)
           {
               JSONObject jsonObject = new JSONObject();
               jsonObject.put("id", a.getId());
               jsonObject.put("user", a.getUser());
               jsonObject.put("journalid", a.getJournalid());
               jsonObject.put("summary", a.getSummary());
               jsonObject.put("date", a.getDate().toString());

               jsonAssets.add(jsonObject);

           }
           answer.put("articles",jsonAssets);
           out.println(answer);
           out.flush();
       }
       if(action != null && action.equals("addArticle"))
       {
           String user =(String) request.getSession().getAttribute("user");
           String journal = request.getParameter("journalName");
           String summary = request.getParameter("summary");
           System.out.println(user+" "+journal+" "+summary);
           Article article = BazaDeDate.addArticle(journal, summary,user);
           if(article!= null)
           {
               System.out.println("Nice");
           }
           else
           {
               System.out.println("Sheeeeet");
           }
       }
       response.sendRedirect("home.jsp");
   }
    @Override
    protected  void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String action = request.getParameter("action");
        System.out.println(action);
        if((action!= null) && action.equals("noArticles"))
        {
            PrintWriter out = new PrintWriter(response.getOutputStream());
            JSONObject answer = new JSONObject();
            int noArticle = BazaDeDate.countArticles();
            answer.put("number",noArticle);
            out.println(answer);
            out.flush();
        }
    }
}
