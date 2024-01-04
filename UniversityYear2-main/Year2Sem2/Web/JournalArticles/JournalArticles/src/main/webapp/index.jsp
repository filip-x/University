<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Journal</title>
    <script src="js/jquery-2.0.3.js"></script>
    <script src="js/ajax-utils.js"></script>
</head>
<body>
<h1><%= "Welcome to journal!" %></h1>
<br>
<h3><%= "Please insert your name" %></h3>

<form action="IndexController" method="post">
    <table>
        <tr>
            <td>Name: </td>
            <td><input type="text" name="name"> </td>
        </tr>
        <tr>
            <td><input type="submit" value="Proceed"> </td>
            <td></td>
        </tr>
    </table>
</form>
</body>
</html>