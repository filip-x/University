<?php header('Access-Control-Allow-Origin: *'); ?>
<?php


function check_arg($arg)
{
    return str_replace("'",'`',$arg);
}


function connect()
{

$connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'Test');
if(!$connection)
{
    echo "nu merge";
    die('Could not connect:'.mysqli_error($connection));
    
}
echo "merge";

}

function addAction()
{
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'Test');
    if(!$connection)
    {
        die('Could not connect to database: '.mysqli_error(($connection)));
    }
    if(session_status()=== PHP_SESSION_NONE)
    {
        session_start();
        $username = $_SESSION["user"];
    }
    $date = date('Y-m-d H:i:s');
    $category = mysqli_real_escape_string($connection,$_POST['categoryid']);
    $description = mysqli_real_escape_string($connection,$_POST['description']);
    echo $username . " " . $category . " " . $description . " " . $date;
    $categoryid = (int)$category;
    $sql_statement = "insert into Auction(user,categoryID,description,date) values('$username',$categoryid, '$description','$date')";
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


function login()
{
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'Test');
    if(!$connection)
    {
        die('Could not connect to database: '.mysqli_error(($connection)));
    }

    $user=mysqli_real_escape_string($connection, $_POST['username']);

    if(session_status()===PHP_SESSION_NONE){
        session_start();
        $_SESSION['loggedIn']="true";
        $_SESSION['user']=$user;

        echo "OK";
    }
    else{
        echo "NOT OK";
    }


    mysqli_close($connection);


}


function updateAction()
{
    $connection = mysqli_connect('localhost:3306', 'test', 'fliperdaru2', 'Test');
    if(!$connection)
    {
        die('Could not connect to database: '.mysqli_error(($connection)));
    }

    if(session_status()=== PHP_SESSION_NONE)
    {
        session_start();
        $username = $_SESSION["user"];
    }
    $id = mysqli_real_escape_string($connection,$_POST['id']);
    $category = mysqli_real_escape_string($connection,$_POST['categoryid']);
    $description = mysqli_real_escape_string($connection,$_POST['description']);
    $date = date('Y-m-d H:i:s');
    $sql_statement = "update Auction set categoryID=?,description=?,date=? where id=? and user=?";
    $statement = mysqli_stmt_init($connection);
    if(mysqli_stmt_prepare($statement,$sql_statement))
    {
        mysqli_stmt_bind_param($statement,"issis",$category,$description,$date,$id,$username);
        mysqli_stmt_execute($statement);
        
    }
    else{
        echo "Error: ".$sql_statement. ":- ".mysqli_error($connection);
    }

    mysqli_close($connection);

}






if (!empty($_POST)) {
    if (isset($_POST["action"])) {
        switch ($_POST["action"]) {
            case "add":
                addAction();
                 break;
            case "login":
                login();
                break;
            case "update":
                updateAction();
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
            case "merge":
               connect();
                break;
            default:
                die("The action doesn't exist!");    
        }
    }
    exit();
}


?>