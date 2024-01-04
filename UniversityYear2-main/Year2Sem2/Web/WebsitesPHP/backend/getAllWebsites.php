<?php
require 'dbConn.php';

if(!$conn) {
    die('Could not connect to database:' . mysqli_error($conn));
}

$sql="SELECT * FROM website;";
$result = mysqli_query($conn,$sql);

$sql2="SELECT count(*) as noW, idwebsite FROM document group by idwebsite;";
$result2 = mysqli_query($conn,$sql2);

echo "<table>
    <thead>
    <tr>
    <th scope='col''>#</th>
	<th scope='col'>id</th>
	<th scope='col'>URL</th>
	<th scope='col'>Documents</th>
	</tr></thead><tbody>";

$ct=1;
$ids=array();
$nrs=array();
while($row2=mysqli_fetch_array($result2)) {
    array_push($ids, $row2['idwebsite']);
    array_push($nrs, $row2['noW']);
}
while($row=mysqli_fetch_array($result)){
    echo "<tr>";
    echo "<th scope='row'>$ct</th>";
    echo "<td>" . $row['id'] . "</td>";
    echo "<td>" . $row['URL'] . "</td>";
    $sem=0;
    for ($i = 0; $i < count($ids); ++$i) {
        if($ids[$i] == $row['id']) {
            $sem=1;
            echo "<td>" . $nrs[$i] . "</td>";
        }
    }
    if($sem == 0)
        echo "<td>" . "0" . "</td>";

    echo "</tr>";
    $ct+=1;
}

echo "</tbody></table>";

mysqli_close($conn);

?>