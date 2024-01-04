package com.example.JournalArticles.controller;

import com.example.JournalArticles.model.DBConnection;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class IndexController extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String name = request.getParameter("name");
        try {
            DBConnection.connect();
        } catch(Exception e){
            System.out.println(e.getMessage());
        }
        if(name!=null){
            System.out.println(name);
            request.getSession().setAttribute("user", name);
            response.sendRedirect("home.jsp");
        }
    }
}
