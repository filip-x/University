<jsp:directive.tag description = "Page template"/>
<jsp:directive.attribute name = "title" fragment = "true"/>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
<html>
<head>
    <link rel = "stylesheet" href = "${pageContext.request.contextPath}/style.css" />
    <title>
        Transportation Route - <jsp:invoke fragment = "title"/>
    </title>
</head>
<body>
<img id = "background" src = "${pageContext.request.contextPath}/forum-back.jpg" alt = "Background">
<div id = "message-box">
            <span>
                Enter a message here...
            </span>
    <button onclick = "$(this).parent().toggleClass('msg-show');">
        Ok
    </button>
</div>
<div id = "container">
    <header>
        <span><jsp:invoke fragment = "title"/></span>
    </header>
    <main>
        <jsp:doBody/>
    </main>
    <footer>
        <a href = "javascript:void(0)" onclick = "__logOut()">Log out</a>
    </footer>
</div>
</body>
</html>
<script>
    function showMessage(text) {
        $("#message-box").toggleClass("msg-show", true);
        $("#message-box span").html(text);
    }

    function __logOut() {
        $.ajax({
            type: 'POST',
            url: 'server.jsp',
            data: {
                action: 'logout'
            },
            success: (data, status) => {
                if (status === "success") {
                    let information = data.split('\n');
                    showMessage(information[1]);
                    if (parseInt(information[0]) === 0) {
                        setTimeout(() => {
                            location.reload();
                        }, 1000);
                    }

                }
            },
            xhrFields: {
                withCredentials: true
            }
        });
    }

    if (window.location.href.endsWith("login.jsp")) {
        $("#container footer a").remove();
    }
</script>