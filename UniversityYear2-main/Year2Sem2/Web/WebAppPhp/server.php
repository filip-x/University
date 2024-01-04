<?php header('Access-Control-Allow-Origin: *'); ?>
<?php

function check_arg($arg)
{
    return str_replace("'",'`',$arg);
}


function getWebsites()
{
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'WebApp');
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
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'WebApp');
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

function searchDocuments()
{
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'WebApp');
    if(!$connection)
    {
        die('Could not connect to database: '.mysqli_error(($connection)));
    }

    $keywords = mysqli_real_escape_string($connection,$_POST["keywords"]);
    $arr = explode(" ",$keywords);
    
    $statement = "select * from Documents";
    $result = mysqli_query($connection,$statement);

    echo "<table>
    <thead>
    <tr>
    <th scope='col''>#</th>
	<th scope='col'>id</th>
	<th scope='col'>idWebSite</th>
	<th scope='col'>name</th>
	</tr></thead><tbody>";

    $ct=1;
    while($row=mysqli_fetch_array($result)){
        $sem=0;
        foreach($arr as &$term){
            if($term == $row['keyword1'] || $term == $row['keyword2'] || $term == $row['keyword3']
                    || $term == $row['keyword4'] || $term == $row['keyword5'])
                $sem+=1;
        }

        if($sem==3) {
            echo "<tr>";
            echo "<th scope='row'>$ct</th>";
            echo "<td>" . $row['id'] . "</td>";
            echo "<td>" . $row['idWebSite'] . "</td>";
            echo "<td>" . $row['name'] . "</td>";
            echo "</tr>";
            $ct += 1;
        }
    }
    echo "</tbody></table>";
    mysqli_close($connection);
}


if (!empty($_POST)) {
    if (isset($_POST["action"])) {
        switch ($_POST["action"]) {
            case "update":
                updateDocuments();
                break;
            case "search":
                searchDocuments();
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
            case "getWebsite":
                getWebsites();
                break;
            default:
                die("The action doesn't exist!");
            
            
                
        }
    }
    exit();
}


?>
