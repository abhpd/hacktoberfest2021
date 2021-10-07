<?php
  define("HOST", "your_host");
  define("USER", "your_username");
  define("PASSWORD", "your_password");
  define("DATABASE", "your_db");
    $mysqli = new mysqli(HOST,USER,PASSWORD,DATABASE);
    $result = $mysqli->query("SELECT * FROM your_table");
    echo "<table>";
    while($row = $result->fetch_assoc()){
        echo "<tr>";
        echo "<td>" . $row["id"] . "<td>";
        echo "<td>" . $row["name"] . "<td>";
        echo "<td>" . $row["password"] . "<td>";
        echo "</tr>";
    }
    echo "</table>";
