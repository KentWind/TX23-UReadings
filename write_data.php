<?php
  $servername = "localhost";
  $username = "arduino";
  $password = "arduinotest";
  $db_name = "kent_wind";

  // Create connection
  $conn = mysqli_connect($servername, $username, $password);
  $db = mysqli_select_db ( $conn, $db_name );

    // Check connection
  if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
  }
  echo "Connected successfully";


  //if(!mysqli_query($conn, "SELECT * FROM live_data WHERE SensorID=1")){
    $sql_insert = "UPDATE live_data SET Speed='".$_GET["Speed"]."', Direction='".$_GET["Direction"]."', Time=CURRENT_TIME() WHERE SensorID='".$_GET["SensorID"]."'";
  //}
  //else if(mysqli_query($conn, "SELECT * FROM live_data WHERE SensorID=1")){
    //$sql_insert = "INSERT INTO live_data (SensorID, Speed, Direction) VALUES ('".$_GET["SensorID"]."', '".$_GET["Speed"]."', '".$_GET["Direction"]."')";
  //}
  if(mysqli_query($conn,$sql_insert))
  {
  echo "Done";
  mysqli_close($conn);
  }
  else
  {
  echo "error is ".mysqli_error($conn);
  }
?>
