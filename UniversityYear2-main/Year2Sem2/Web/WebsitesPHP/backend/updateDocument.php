<?php
require 'dbConn.php';


if(!$conn) {
    die('Could not connect to database:' . mysqli_error($conn));
}

//take variables from the post array
$id=mysqli_real_escape_string($conn, $_POST['id']);
$keyword1=mysqli_real_escape_string($conn, $_POST['keyword1']);
$keyword2=mysqli_real_escape_string($conn, $_POST['keyword2']);
$keyword3=mysqli_real_escape_string($conn, $_POST['keyword3']);
$keyword4=mysqli_real_escape_string($conn, $_POST['keyword4']);
$keyword5=mysqli_real_escape_string($conn, $_POST['keyword5']);
$id=(int)$id;

//prepare the sql statement
$sql="UPDATE document SET keyword1=?,keyword2=?,keyword3=?,keyword4=?,keyword5=? WHERE id=?;";
$stmt=mysqli_stmt_init($conn);

if(mysqli_stmt_prepare($stmt,$sql)){
    //echo "Car has been updated successfully!";

    //bind the data to the prepared statement and execute it
    mysqli_stmt_bind_param($stmt,"sssssi",$keyword1,$keyword2,$keyword3,$keyword4,$keyword5,$id);
    mysqli_stmt_execute($stmt);
} else {
    echo "Error: " . $sql . ":-" . mysqli_error($conn);
}

mysqli_close($conn);

?>