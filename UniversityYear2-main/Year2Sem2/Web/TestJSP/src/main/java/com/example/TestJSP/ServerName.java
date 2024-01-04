package com.example.TestJSP;

import javax.servlet.annotation.WebFilter;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
@WebFilter("/*")
public class ServerName extends HttpServlet {

    public void init()
    {
        String message = "Test Servlet";

    }
    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String name = request.getParameter("name");
        try
        {
            BazaDeDate databaseBean = new BazaDeDate();

        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
        if(name!=null)
        {
            System.out.println(name);
            request.getSession().setAttribute("user",name);
            response.sendRedirect("home.jsp");
        }

    }
    public void destroy()
    {

    }
}
