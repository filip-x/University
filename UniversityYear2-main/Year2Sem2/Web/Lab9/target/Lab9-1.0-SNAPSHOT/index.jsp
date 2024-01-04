<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix = "c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix = "app" tagdir = "/WEB-INF/tags" %>

<app:back>
    <jsp:attribute name="title">
        Make a Forum
    </jsp:attribute>
    <jsp:body>
        <jsp:useBean id="databaseBean" class = "com.example.Lab9.BazaDeDate"/>

        <div id = "table-container">
            <table>
                <thead>
                <tr>
                    <th>Topic</th>
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
        <div id="addTopicdiv">
            <label for = "addTopic">Add Topic: </label>
            <input type = "text" id = "addTopic" />
            <button id = "addTopicButton" onclick = "handleAddTopic(this)"> Add </button>
        </div>
    </jsp:body>
</app:back>

<style>
    #table_body tr:hover {
        cursor: pointer;
    }
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

    #route {
        width: 80%;
        height: 500px;
        margin-left: 10%;
        overflow-x: auto;
        overflow-y: hidden;
        white-space: nowrap;
    }
    #addTopicdiv
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

    #addTopicButton{
        width: 50px;
        height: 50px;
        margin-top: 5px;
    }
</style>

<script>
    function loadTopics() {
        $.post('server.jsp', {
            action: "load_topics",
        }, (data, status) => {
            if (status === "success") {
                let information = data.split('\n');
                for(let i =0;i<information.length-1;i+=2){
                    let element = $("#table_body").get(0);
                    let row = document.createElement("tr");
                    row.innerText = information[i+1];
                    row.value = information[i];
                    $(row).on('click', onRowClick);
                    element.appendChild(row);
                }
            }
        });
    }
    function handleAddTopic() {
        let topicName = $("#addTopic").val();
        if (topicName.length > 0) {
            $.post('server.jsp', {
                action: "add_topic",
                topic_name: topicName
            }, (data, status) => {
                if (status === "success") {
                    location.reload();
                }
            });
        }
    }

    function onRowClick(event) {
        let target = event.target;
        location.href = 'message.jsp?topicId=' + target.value;
    }

    loadTopics();
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