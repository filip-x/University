<%@ page import="com.example.Lab9.BazaDeDate" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix = "c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix = "app" tagdir = "/WEB-INF/tags" %>

<app:back>
    <jsp:attribute name="title">
        Message
    </jsp:attribute>
    <jsp:body>
        <jsp:useBean id="databaseBean" class = "com.example.Lab9.BazaDeDate"/>

        <div id = "table-container">
            <table>
                <thead>
                <tr>
                    <th>Messages</th>
                    <th class = "no-border"></th>
                </tr>
                </thead>
                <tbody id = "table_body">
                </tbody>
            </table>
        </div>
        <br>
        <br>
        <div id = "comments">

        </div>
        <div id="addMessagediv">
            <label for = "addMessagediv">Add Message: </label>
            <input type = "text" id = "addMessage" />
            <button id = "addMessageButton" onclick = "handleAddMessage(this)"> Add </button>
        </div>

    </jsp:body>
</app:back>

<style>
    #table-container {
        position: relative;
        width: 80%;
        height: 70%;
        top: 10%;
        margin-left: 10%;
        overflow-y: auto;
    }

    #table-container th, #table-container td {
        border: 2px solid black;
        width: 100%;
        font-size: 14px;
    }

    #table-container td span {
    }

    #table-container td button {
        height: 100%;
        width: 500px;

    }

    .no-border {
        border: hidden !important;
    }

    #addMessagediv
    {
        position: absolute;
        right: 20%;
    }
    label{
        height: 25px;
        width: 30px;
    }
    #finish-button {
        position: absolute;
        right: 10%;
        width: 50px;
        height: 50px;
        margin-top: 5px;
    }

    #addMessageButton{
        width: 50px;
        height: 50px;
        margin-top: 5px;
    }
</style>

<script>
    <%
        BazaDeDate databaseBean2 = new BazaDeDate();
    %>
    let userId = <%= databaseBean2.getUserIdFromUsername((String) request.getSession().getAttribute("LOGGED_IN")) %>
    function loadMessage(topicId) {
        console.log(topicId);
        $.post('server.jsp', {
            action: "load_messages",
            topic_id: topicId
        }, (data, status) => {
            if (status === "success") {
                let information = data.split('\n');
                for(let i =0;i<information.length-1;i+=3)
                {
                    let element = $("#table_body").get(0);
                    let row = document.createElement("tr");
                    let cell = document.createElement("td");
                    cell.innerText = information[i];
                    cell.value = information[i+1];
                    cell["data-owner"] = information[i+2];
                    let cell2 = document.createElement("td");
                    let b = document.createElement("button");
                    b.innerText = "Delete";
                    b.style.width = "75px";
                    b.value = information[i+1];// am pus valoare in button
                    $(b).on("click",handleRemoveMessage)
                    if (userId !== parseInt(information[i+2]))
                        b.disabled = true;
                    cell2.appendChild(b);
                    row.appendChild(cell);
                    row.appendChild(cell2);
                    element.appendChild(row);
                }
            }
        });
    }
    function handleAddMessage() {
        let messageText = $("#addMessage").val();
        if (messageText.length > 0) {
            $.post('server.jsp', {
                action: "add_message",
                message_name: messageText,
                topic_id: <%= request.getParameter("topicId") %>
            }, (data, status) => {
                if (status === "success") {
                    location.reload();
                }
            });
        }
    }
    function handleRemoveMessage(event) {
        let button = event.target;
        let messageId = button.value;
        $.post('server.jsp', {
            action: "remove_message",
            message_id: messageId
        }, (data, status) => {
            if (status === "success") {
                location.reload();
            }
        });

    }
    loadMessage(<%= request.getParameter("topicId") %>);
</script>
<!--

sign-up & log-in
topics
-list
-add
-comment-to a topic
- see comments
- delete own comment

!>