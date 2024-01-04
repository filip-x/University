package com.example.Lab9;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;
import java.util.Random;
import java.util.stream.Collectors;

@WebServlet("/server.jsp")
public class Server extends HttpServlet {
    private String message;

    public void init() {
        message = "Test Servlet!";
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");

        // Hello
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }



    public int getConnectedUser(HttpServletRequest request) {
        if (request.getSession().getAttribute("LOGGED_IN") == null) {
            return -1;
        } else {
            BazaDeDate databaseBean = new BazaDeDate();
            return databaseBean.getUserIdFromUsername((String) request.getSession().getAttribute("LOGGED_IN"));
        }
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        String action = request.getParameter("action");
        BazaDeDate databaseBean = new BazaDeDate();
        int connectedUserId;
        switch (action) {
            case "signup": {
                String username = request.getParameter("username");
                String password = request.getParameter("password");

                response.getWriter().println(databaseBean.register(username, password));
                break;
            }
            case "login": {
                String username = request.getParameter("username");
                String password = request.getParameter("password");

                List<String> information = databaseBean.login(username, password);
                //if (information.get(0).equals("0")) {
                if (information.get(0).equals("0") && request.getSession().getAttribute("LOGGED_IN") == null) {
                    information.set(1, "Successfully logged in! <br> Redirecting...");
                    request.getSession().setAttribute("LOGGED_IN", username);
                }
                response.getWriter().println(information.get(0));
                response.getWriter().println(information.get(1));
                break;
            }
            case "logout":
                if (request.getSession().getAttribute("LOGGED_IN") != null) {
                    request.getSession().setAttribute("LOGGED_IN", null);
                    response.getWriter().println("0");
                    response.getWriter().println("Successfully logged off! <br> Redirecting...");
                } else {
                    response.getWriter().println("1");
                    response.getWriter().println("Could not log out!");
                }
                break;
            case "add_topic":
                connectedUserId = getConnectedUser(request);
                if (connectedUserId != -1) {
                    String newTopic = request.getParameter("topic_name");
                    databaseBean.addTopic(newTopic);
                }
                break;
            case "add_message":
                connectedUserId = getConnectedUser(request);
                if (connectedUserId != -1) {
                    String newMessage = request.getParameter("message_name");
                    String topicId = request.getParameter("topic_id");
                    databaseBean.addMessage(newMessage, Integer.parseInt(topicId), connectedUserId);
                }
                break;
            case "load_topics":
                connectedUserId = getConnectedUser(request);
                if (connectedUserId != -1) {
                    List<String> topics = databaseBean.loadTopics();
                    response.getWriter().println(String.join("\n", topics));
                }
                break;
            case "load_messages":
                connectedUserId = getConnectedUser(request);
                if (connectedUserId != -1) {
                    String topic = request.getParameter("topic_id");
                    List<String> messages = databaseBean.loadMessages(Integer.parseInt(topic));
                    response.getWriter().println(String.join("\n",messages));
                }
                break;
            case "remove_message":
                connectedUserId = getConnectedUser(request);
                if (connectedUserId != -1) {
                    String messageId = request.getParameter("message_id");
                    databaseBean.removeMessage(Integer.parseInt(messageId), connectedUserId);
                }
                break;

        }
    }

    public void destroy() {
    }
}
