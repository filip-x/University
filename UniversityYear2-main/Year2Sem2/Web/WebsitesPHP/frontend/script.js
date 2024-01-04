
function showWebsites() {
    /*
    if (window.XMLHttpRequest) {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp = new XMLHttpRequest();
    } else {
        // code for IE6, IE5
        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
    xmlhttp.onreadystatechange = function() {
        if (this.readyState === 4 && this.status === 200) {
            document.getElementById("divA").innerHTML = this.responseText;
        }
    };
    xmlhttp.open('GET','../backend/getAllWebsites.php',true);
    xmlhttp.send();

     */
    $.get("../backend/getAllWebsites.php",
        function (data){
            $('#divA').html(data);
        });

}
function updateDocument(){
    var idU=document.getElementById('idU').value;
    var keywordU1=document.getElementById('keyword1U').value;
    var keywordU2=document.getElementById('keyword2U').value;
    var keywordU3=document.getElementById('keyword3U').value;
    var keywordU4=document.getElementById('keyword4U').value;
    var keywordU5=document.getElementById('keyword5U').value;
    /*
    if(window.XMLHttpRequest)
    {
        xmlhttp = new XMLHttpRequest();
    }
    else
    {
        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
    var allData = "id="+id+"&keyword1="+keyword1+"&keyword2="+keyword2+
        "&keyword3="+keyword3+"&keyword4="+keyword4+"&keyword5="+keyword5;
    //alert(allData);
    xmlhttp.open("POST","../backend/updateDocument.php",true);
    xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xmlhttp.send(allData);
    xmlhttp.onreadystatechange = function()
    {
        if(this.readyState===4 && this.status === 200)
        {
            alert(this.responseText);
        }
    }
    //location.href='index.html';
    */
    $.post("../backend/updateDocument.php", {id: idU, keyword1: keywordU1, keyword2: keywordU2, keyword3: keywordU3,
            keyword4: keywordU4, keyword5: keywordU5},
        function (data){
            alert(data);
        });
}
function searchDocuments(){
    var keywords=document.getElementById('keywords').value;
    /*
    if(window.XMLHttpRequest)
    {
        xmlhttp = new XMLHttpRequest();
    }
    else
    {
        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
    var allData = "keywords="+keywords;
    //alert(allData);
    xmlhttp.open("POST","../backend/searchDocuments.php",true);
    xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xmlhttp.send(allData);
    xmlhttp.onreadystatechange = function()
    {
        if(this.readyState===4 && this.status === 200)
        {
            document.getElementById("divB").innerHTML = this.responseText;
        }
    }
    //location.href='index.html';

    */
    $.post("../backend/searchDocuments.php", {keywords: keywords},
        function (data){
            $('#divB').html(data);
        });
}