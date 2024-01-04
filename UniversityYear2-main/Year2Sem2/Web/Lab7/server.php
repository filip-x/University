<?php header('Access-Control-Allow-Origin: *'); ?>
<?php
function check_arg($arg) {
    return str_replace("'", '`', $arg);
}
function addBook() {
    if (!isset($_GET["author"]) || !isset($_GET["title"])
        || !isset($_GET["comment"]) || !isset($_GET["date"])) {
        die('Missing parameters.');
    }
    $connection = mysqli_connect('localhost:3306', 'lab7', '1234ABcd', 'Lab7');
    if (!$connection) {
        die('Could not connect: ' . mysqli_error($connection));
    }
    $author = check_arg($_GET["author"]);
    $title = check_arg($_GET["title"]);
    $comment = check_arg($_GET["comment"]);
    $date = check_arg($_GET["date"]);
    $sql_query = "INSERT INTO Books (Author, Title,Comment,Date) VALUES " .
        "('$author','$title','$comment', '$date')";
    $result = mysqli_query($connection, $sql_query);
    if ($result) {
        echo "ended";
    } else {
        trigger_error("Could not insert!", E_USER_ERROR);
    }
    mysqli_close($connection);
}
function get_author() {
    $connection = mysqli_connect('localhost:3306', 'lab7', '1234ABcd', 'Lab7');
    if (!$connection) {
        die('Could not connect: ' . mysqli_error($connection));
    }
    $sql_query = "SELECT DISTINCT Author FROM Books";
    $result = mysqli_query($connection, $sql_query);
    $author_list = array();
    while ($row = mysqli_fetch_array($result)) {
        array_push($author_list, $row["Author"]);
    }
    echo json_encode($author_list);
    mysqli_close($connection);
}
function get_title() {
    $connection = mysqli_connect('localhost:3306', 'lab7', '1234ABcd', 'Lab7');
    if (!$connection) {
        die('Could not connect: ' . mysqli_error($connection));
    }
    $sql_query = "SELECT DISTINCT Title FROM Books";
    $result = mysqli_query($connection, $sql_query);
    $title_list = array();
    while ($row = mysqli_fetch_array($result)) {
        array_push($title_list, $row["Title"]);
    }
    echo json_encode($title_list);
    mysqli_close($connection);
}
function load_browse() {
    if (!isset($_GET["pageSize"]) || !isset($_GET["page"]) || !isset($_GET["Title"]) || !isset($_GET["Author"])) {
        die('Missing parameters.');
    }
    $connection = mysqli_connect('localhost:3306', 'lab7', '1234ABcd', 'Lab7');
    if (!$connection) {
        die('Could not connect: ' . mysqli_error($connection));
    }
    $page_size = intval($_GET["pageSize"]);
    $page = intval($_GET["page"]);
    $title = check_arg($_GET["Title"]);
    $author = check_arg($_GET["Author"]);
    $limit_start = ($page - 1) * $page_size;
    $sql_query = "SELECT * FROM Books WHERE Title = '$title' AND Author = '$author' LIMIT $limit_start, $page_size";
    $result = mysqli_query($connection, $sql_query);
    $result_array = array();
    while ($row = mysqli_fetch_array($result)) {
        $linear_row = array();
        array_push($linear_row, $row["id"], $row["Author"], $row["Title"], $row["Comment"], $row["Date"]);
        array_push($result_array, $linear_row);
    }
    $sql_query = "SELECT COUNT(*) AS 'Count' FROM Books WHERE Title = '$title' AND Author = '$author'";
    $result = mysqli_query($connection, $sql_query);
    $result = mysqli_fetch_assoc($result);
    $result = intdiv($result["Count"] - 1, $page_size);
    $final_result = array(
        "page_count" => $result,
        "page_content" => $result_array
    );
    echo json_encode($final_result);
    mysqli_close($connection);
}

function delete_id() {
    if (!isset($_GET["id"])) {
        die('Missing parameters.');
    }
    $connection = mysqli_connect('localhost:3306', 'lab7', '1234ABcd', 'Lab7');
    if (!$connection) {
        die('Could not connect: ' . mysqli_error($connection));
    }
    $id = check_arg($_GET["id"]);
    $sql_query = "SELECT COUNT(*) AS 'Count' FROM Books WHERE id = '$id'";
    $result = mysqli_query($connection, $sql_query);
    $row = mysqli_fetch_array($result);
    if ($row["Count"] == 0) {
        echo "1Could not find a Book with this Id!";
    } else {
        $sql_query = "DELETE FROM Books WHERE id = '$id'";
        mysqli_query($connection, $sql_query);
        $sql_query = "SELECT COUNT(*) AS 'Count' FROM Books WHERE Id = '$id'";
        $result = mysqli_query($connection, $sql_query);
        $row = mysqli_fetch_array($result);
        if ($row["Count"] != 0) {
            echo "1The Book has not been removed!";
        } else {
            echo "0The Book has been successfully removed!";
        }
    }
    mysqli_close($connection);
}
function modifyBook() {
    if (!isset($_GET["id"]) || !isset($_GET["author"]) || !isset($_GET["title"])
        || !isset($_GET["comment"]) || !isset($_GET["date"])) {
        die('Missing parameters.');
    }
    $connection = mysqli_connect('localhost:3306', 'lab7', '1234ABcd', 'Lab7');
    if (!$connection) {
        die('Could not connect: ' . mysqli_error($connection));
    }
    $id = check_arg($_GET["id"]);
    $author = check_arg($_GET["author"]);
    $title = check_arg($_GET["title"]);
    $comment = check_arg($_GET["comment"]);
    $date = check_arg($_GET["date"]);
    $sql_query = "UPDATE Books SET Author = '$author', Title = '$title', Comment = '$comment', " .
        "Date = '$date' WHERE id = '$id'";
    $result = mysqli_query($connection, $sql_query);
    if ($result) {
        echo "ended";
    } else {
        trigger_error("Could not modify!" . mysqli_error($connection), E_USER_ERROR);
    }
    mysqli_close($connection);
}
function load_id() {
    if (!isset($_GET["id"])) {
        die('Missing parameters.');
    }
    $connection = mysqli_connect('localhost:3306', 'lab7', '1234ABcd', 'Lab7');
    if (!$connection) {
        die('Could not connect: ' . mysqli_error($connection));
    }
    $id = check_arg($_GET["id"]);
    $sql_query = "SELECT COUNT(*) AS 'Count' FROM Books WHERE id = '$id' ";
    $result = mysqli_query($connection, $sql_query);
    $result = mysqli_fetch_array($result);
    $result = $result["Count"];
    if ($result > 0) {
        $sql_query = "SELECT * FROM Books WHERE id = '$id' ";
        $result = mysqli_query($connection, $sql_query);
        $resultRow = array();
        $row = mysqli_fetch_array($result);
        array_push($resultRow, $row["Author"], $row["Title"], $row["Comment"], $row["Date"]);
        echo json_encode($resultRow);
    } else {
        echo `false`;
    }
    mysqli_close($connection);
}
if (!empty($_GET)) {
    if (isset($_GET["action"])) {
        switch ($_GET["action"]) {
            case "add":
                addBook();
                break;
            case "delete":
                delete_id();
                break;
            case "load":
                load_id();
                break;
            case "modify":
                modifyBook();
                break;
            case "getAuthor":
                get_author();
                break;
            case "getTitle":
                get_title();
                break;
            case "loadBrowse":
                load_browse();
                break;
            default:
                die("The action doesn't exist!");
        }
    }
    exit();
}
?>