<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix = "c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>


<!DOCTYPE html>
<html>
<head>
    <title>Journal</title>

</head>
<body>
<h1><%= "Welcome to journal!" %></h1>
<br>
<h3><%= "Please insert your name" %></h3>

<form action="server-rest" method="post">
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

<script>


</script>
