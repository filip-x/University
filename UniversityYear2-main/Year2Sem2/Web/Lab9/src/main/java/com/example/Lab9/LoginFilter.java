package com.example.Lab9;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebFilter("/*")
public class LoginFilter implements Filter {
    @Override
    public void init(FilterConfig config) {
        System.out.println("Filter initializing!!");
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain filterChain) throws IOException, ServletException {

        HttpServletRequest httpRequest = (HttpServletRequest) request;
        String requestURI = httpRequest.getRequestURI();

        System.out.println("Trying to connect");
        System.out.println(requestURI);

        if (requestURI.endsWith("server.jsp") || (!requestURI.endsWith(".jsp") && !requestURI.equals("/Lab9-1.0-SNAPSHOT/"))) {
            filterChain.doFilter(request, response);
            return;
        }
        int connectedUserId = -1;
        HttpServletRequest hRequest = (HttpServletRequest) request;
        if (hRequest.getSession().getAttribute("LOGGED_IN") != null) {
            System.out.println(hRequest.getSession().getAttribute("LOGGED_IN") );
            BazaDeDate databaseBean = new BazaDeDate();
            connectedUserId = databaseBean.getUserIdFromUsername((String) hRequest.getSession().getAttribute("LOGGED_IN"));
        }
        if (requestURI.endsWith("login.jsp")) {
            if (connectedUserId != -1) {
                HttpServletResponse httpResponse = (HttpServletResponse) response;
                httpResponse.sendRedirect("index.jsp");
                return;
            }
        }
        else if (connectedUserId == -1) {
            HttpServletResponse httpResponse = (HttpServletResponse) response;
            httpResponse.sendRedirect("login.jsp");
            return;
        }
        filterChain.doFilter(request, response);
    }

    @Override
    public void destroy() {
    }

}
