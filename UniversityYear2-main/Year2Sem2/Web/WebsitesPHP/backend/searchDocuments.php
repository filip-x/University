<?php
require 'dbConn.php';


if(!$conn) {
    die('Could not connect to database:' . mysqli_error($conn));
}

//take variables from the post array
$keywords=mysqli_real_escape_string($conn, $_POST['keywords']);

$arr=explode(" ", $keywords);
//echo $arr;

$sql="SELECT * FROM document;";
$result = mysqli_query($conn,$sql);

echo "<table>
    <thead>
    <tr>
    <th scope='col''>#</th>
	<th scope='col'>id</th>
	<th scope='col'>idwebsite</th>
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
        echo "<td>" . $row['idwebsite'] . "</td>";
        echo "<td>" . $row['name'] . "</td>";
        echo "</tr>";
        $ct += 1;
    }
}

echo "</tbody></table>";

mysqli_close($conn);

?>