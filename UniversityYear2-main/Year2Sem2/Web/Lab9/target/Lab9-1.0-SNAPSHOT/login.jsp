<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix = "c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<jsp:directive.page contentType = "text/html" pageEncoding = "UTF-8"/>
<%@ taglib prefix = "app" tagdir = "/WEB-INF/tags" %>




<app:back>
    <jsp:attribute name="title">
        Login
    </jsp:attribute>
    <jsp:body>
        <jsp:useBean id="databaseBean" class = "com.example.Lab9.BazaDeDate"/>
        <br>
        <form autocomplete = "off">
            <label for = "login_username">Username: </label>
            <input type = "text" id = "login_username" name = "false_username" autocomplete = "false"/>
            <label for = "login_password">Password: </label>
            <input type = "password" id = "login_password" name = "false_password" autocomplete = "false"/>
            <button type = "button" id = "log-in">Log in</button>
            <br>
            <span>Or sign up...</span>
            <label for = "signup_username">Username: </label>
            <input type = "text" id = "signup_username" name = "signup_username" autocomplete = "off"/>
            <label for = "signup_password">Password: </label>
            <input type = "password" id = "signup_password" name = "signup_password" autocomplete = "false"/>
            <button type = "button" id = "sign-up">Sign up</button>
        </form>
    </jsp:body>
</app:back>

<style>
    form {
        display: flex;
        flex-direction: column;
        width: 40%;
        margin: 0 auto;
    }

    form label, input {
        font-size: 14px;
    }
    form label {
        margin-top: 10px;
    }

    form input {
        height: 20px;

    }
    form button {
        height: 35px;
        margin: 10px;
        font-size: 14px;
        width: 33%;
    }
</style>

<script>
    $('#sign-up').on('click', () => {
        $.post('server.jsp', {
            action: "signup",
            username: $('#signup_username').val(),
            password: $('#signup_password').val()
        }, (data, status) => {
            if (status === "success") {
                console.log(status);
                showMessage(data);
            }
        });
    });

    $('#log-in').on('click', () => {
        $.post('server.jsp', {
            action: "login",
            username: $('#login_username').val(),
            password: $('#login_password').val()
        }, (data, status) => {
            if (status === "success") {
                let information = data.split('\n');
                showMessage(information[1]);
                console.log(information);
                if (parseInt(information[0]) === 0) {
                    setTimeout(() => {
                        location.reload();
                    }, 1000);
                }
            }
        });
    });
</script>