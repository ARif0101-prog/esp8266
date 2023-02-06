<?php

$servername = "localhost";

// REPLACE with your Database name
$dbname = "coba";
// REPLACE with Database user
$username = "root";
// REPLACE with Database user password
$password = "";
	 $conn = new mysqli($servername, $username, $password, $dbname);
    //include_once('inc.inc');
    $device_name    =   $_GET['device_name'];
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    
    $sql        =   "SELECT device_status FROM devices_status WHERE device_name='$device_name' LIMIT 1";
    $result     =   $conn->query($sql);
    
    if ($result->num_rows > 0) {
    
    while ($row = $result->fetch_assoc())
    {
        echo $row['device_status'];
    }
        
    } else {
        echo "Error:" . $sql . "<br>" . $conn->error;
    }
    
    $conn->close();
?>