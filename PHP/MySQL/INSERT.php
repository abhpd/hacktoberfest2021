<?php
    define("HOST", "your_host");
    define("USER", "your_username");
    define("PASSWORD", "your_password");
    define("DATABASE", "your_db");
    $mysqli = new mysqli(HOST,USER,PASSWORD,DATABASE);
    $stmt = $mysqli->prepare("INSERT INTO your_table(name, password) VALUES (?, ?)");
    $name = "username";
    $password = "12345";
    $stmt->bind_param("ss", $name, $password);
    $stmt->execute();
?>