<?php header('Access-Control-Allow-Origin: *'); ?>
<?php

function check_arg($arg)
{
    return str_replace("'",'`',$arg);
}

function getWebsites()
{
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'Web2');
    if(!$connection)
    {
        die('Could not connect:'.mysqli_error($connection));
    }
    //first query
    $sql_query = "select * from Website";
    $result = mysqli_query($connection,$sql_query);
    //second query
    $sql_query2 = "select idWebSite,count(*) as noW from Documents group by idWebSite;";
    $result2 = mysqli_query($connection,$sql_query2);

    echo "<table>
    <thead>
    <tr>
    <th scope='col''>#</th>
	<th scope='col'>id</th>
	<th scope='col'>URL</th>
	<th scope='col'>Documents</th>
	</tr></thead><tbody>";


    $ct=1;
    $websitesList = array();
    $idOfWebsite =array();
    $nrOfDoc = array();
    while($row2 = mysqli_fetch_array($result2))
    {
        array_push($idOfWebsite,$row2['idWebSite']);
        array_push($nrOfDoc,$row2['noW']);
    }

    while($row = mysqli_fetch_array($result))
    {
        echo "<tr>";
        echo "<th scope='row'>$ct</th>";
        echo "<td>" . $row['id'] . "</td>";
        echo "<td>" . $row['URL'] . "</td>";
        $sem =0;
        for($i =0;$i<count($idOfWebsite);++$i)
        {
            if($idOfWebsite[$i] ==$row['id'])
            {
                $sem=1;
                echo "<td>" .$nrOfDoc[$i]."</td>";

            }
        }
        if($sem == 0)
            echo "<td>" . "0" . "</td>";
        echo "</tr>";
        $ct+=1;
    }
    echo "</tbody></table>";

    echo json_encode($websitesList);
    mysqli_close($connection);
}

function updateDocuments()
{
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'Weeb2');
    if(!$connection)
    {
        die('Could not connect to database: '.mysqli_error(($connection)));
    }

    $id = mysqli_real_escape_string($connection,$_POST['id']);
    $keyword1 = mysqli_real_escape_string($connection,$_POST['keyword1']);
    $keyword2 = mysqli_real_escape_string($connection,$_POST['keyword2']);
    $keyword3 = mysqli_real_escape_string($connection,$_POST['keyword3']);
    $keyword4 = mysqli_real_escape_string($connection,$_POST['keyword4']);
    $keyword5 = mysqli_real_escape_string($connection,$_POST['keyword5']);
    $id = (int)$id;
    
    $sql_statement = "update Documents set keyword1=?,keyword2=?,keyword3=?,keyword4=?,keyword5=? where id=?";
    $statement = mysqli_stmt_init($connection);
    if(mysqli_stmt_prepare($statement,$sql_statement))
    {
        mysqli_stmt_bind_param($statement,"sssssi",$keyword1,$keyword2,$keyword3,$keyword4,$keyword5,$id);
        mysqli_stmt_execute($statement);
        
    }
    else{
        echo "Error: ".$sql_statement. ":- ".mysqli_error($connection);
    }

    mysqli_close($connection);

}

function addDocument()
{

    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'Web2');
    if(!$connection)
    {
        die('Could not connect to database: '.mysqli_error(($connection)));
    }
    $name = mysqli_real_escape_string($connection,$_POST['name']);
    $content = mysqli_real_escape_string($connection,$_POST['content']);
    
    $sql_statement = "insert into Documents(name,contents) values('$name', '$content')";
    $result = mysqli_query($connection,$sql_statement);
    if($result)
    {
        echo "added";
    }
    else
    {
        echo"fail";
    }
    mysqli_close($connection);
}



function documentsWithAuthors()
{
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'Web2');
    if(!$connection)
    {
        die('Could not connect to database: '.mysqli_error(($connection)));
    }

    $sql="SELECT * FROM author;";
    $result = mysqli_query($connection,$sql);
    $arr=[];
    while($row = mysqli_fetch_array($result))
    {
        $docs = $row["documentList"];
        $docArr =explode(" ",$docs);
        foreach($docArr as $el)
        {
            array_push($arr,$el);
        }
    }
    $counts = array_count_values($arr);
    arsort($counts);
    $list = array_keys($counts);
    $statement = $connection->prepare("select* from Documents where name=?");
    $statement->bind_param("s",$list[0]);
    $statement->execute();
    $result = $statement->get_result();

    if($row = mysqli_fetch_array($result)){
        $response=$row['id'] . " " . $row['name'] . " " . $row['contents'];
        echo $response;

    mysqli_close($connection);

}

if (!empty($_POST)) {
    echo "1";
    if (isset($_POST["action"])) {
        echo "2";
        switch ($_POST["action"]) {
            
            case "add":
                addDocument();
                break;
            
            default:
                die("The action doesn't exist!");
            
            
                
        }
    }
    exit();
}


if (!empty($_GET)) {
    if (isset($_GET["action"])) {
        switch ($_GET["action"]) {
            case "show":
                documentsWithAuthors();
                break;
            default:
                die("The action doesn't exist!");
                   
        }
    }
    exit();
}


?>