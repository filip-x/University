<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix = "c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<html>
<head>
    <title>Home</title>
    <script src="jquery-2.0.3.js"></script>
</head>
<body>
<div>
    <table>
        <tr>
            <td>Journal name:</td>
            <td><input type="text" id="journalName"></td>
        </tr>
        <tr>
            <td>
                <button type="button" id="get-articles" >Get Articles</button>
            </td>
            <td></td>
    </table>
</div>

<br>
<div id="articles"></div>
<br>

<div>
    <table>
        <tr>
            <td>Summary: </td>
            <td><input type="text" id="summary"> </td>
        </tr>
        <tr>
            <td>
                <button type="button" id="add-article">Add Article</button>
            </td>
            <td></td>
        </tr>
    </table>
</div>

<script>
    function showArticles(articles){
        var content = "";
        for(let i=0; i<articles.length; i++){
            content += "<br>" + articles[i]["user"] + " " + articles[i]["journalid"] + " " + articles[i]["summary"] + " " + articles[i]["date"];
        }
        $('#articles').html(content);
    }

    function countArticles(articles){
        var newArt = {nr:0};
        setTimeout(function(){}, 500);
        noArticles(newArt);
        if(newArt["nr"] != articles["nr"]){
            articles["nr"]=newArt["nr"];
            alert("One has been added"+newArt["nr"]+" "+articles["nr"]);
        }

        //setTimeout(function(){countArticles(articles)}, 3000);
    }

    //can write all the functions here so we don't have other files with functions
    function getArticles(journalName)
    {
        $.post("server-rest",
            {
                action:"getArticles", journalName:journalName},
            function(data){
            var a = JSON.parse(data);
            showArticles(a["articles"]);
            }
        );
    }

    function addArticle(journalName,summary)
    {

        $.post("server-rest",
            {
                action: "addArticle",journalName:journalName,summary:summary
            },
            function (data){}
        );
    }
    function noArticles()
    {
        $.getJSON(
            "ServerRest",
            {action: "noArticles"},
            function (data){
                return data["number"];
            }
        )
    }

    $(document).ready(function(){
        var currentData  = {nr: 0};
        var rez=noArticles();
        setTimeout(function(){}, 300);

        $('#get-articles').click(function (){
            getArticles($('#journalName').val());
        });
        $('#add-article').click(function (){
            if($('#journalName').val().length>0){
                addArticle($('#journalName').val(), $('#summary').val());
            }
        });



        //setTimeout(function(){}, 500);
        //countArticles(currentData);


    });
</script>

</body>
</html>

