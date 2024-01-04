
function getArticles(journalName){
    $.post(
        "JournalController",
        {action: "getArticles", journalName: journalName},
        function(data){
            var a = JSON.parse(data);
            showArticles(a["articles"]);
        }
    );
}

function addArticle(journalName, summary){
    $.post(
        "JournalController",
        {action: "addArticle", journalName: journalName, summary: summary},
        function (data){}
    );
}

function noArticles(){
    $.getJSON(
        "JournalController",
        {action: "noArticles"},
        function(data){
            //alert(data["number"]);
            return data["number"];
        }
    )
}