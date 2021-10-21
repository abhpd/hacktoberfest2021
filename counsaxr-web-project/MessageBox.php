<?php 
if(session_id() == ''){
    session_start();
}
	if( !(isset($_SESSION["userid"])) ){
		header("location: Home.php");
		exit();
	}
	if(!@include_once('Includes/sendMessage.inc.php')) {
		include_once("Includes/sendMessage.inc.php");
}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">

	<link rel="stylesheet" href="css/bootstrap.css">
	<link rel="stylesheet" href="css/MessageBox.css">
	<link rel="stylesheet" href="css/login/abc.css">

	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<title>CounsaXR |Chat</title>
</head>
<body>
	<div class="container">
		<div class="row no-gutters">
			<div class=" col-md-4 border-right">
				<div class="settings-tray">
					<img class="profile-image" src="images/avatar.jpg" alt="Profile image">
					<span class="settings-tray--right float-end">
						<i class="fas fa-home" onclick="window.location.href = 'Home.php';"></i>
					</span>
				</div>
				<div class="search-box-message">
					<div class="input-wrapper">
						<i class="fas fa-search"></i>
						<input type="text" placeholder="Search here">
					</div>
				</div>
				<!--message categories-->
				<!--1-->
				<?php include_once('Includes/getChatList.inc.php'); ?>
				<!--2-->
				

				<!--end of message categories-->			
			</div>

			<div class="col-md-8">
				<div class="settings-tray mt-3">
				<?php
					if(!@include_once('Includes/showReciverCard.inc.php')) {
						include_once("Includes/showReciverCard.inc.php");
					}
				?>
				</div>
				<?php
					if(!@include_once('Includes/getAllMessages.inc.php')) {
						include_once("Includes/getAllMessages.inc.php");
					}
				?>
				<div class="chat-panel">
				</div>
				<div class="row">
						<div class="col-12">
							<div class="chat-box-tray">
								<i class="far fa-laugh"></i>
									<input type="text" name="message" placeholder="Type youe message here..." id="messageBox" >
								<i class="fas fa-share-square" style="cursor:pointer;" onclick="sendMessage()"></i>
							</div>
						</div>
				</div>
			</div>
		</div>
	</div>
	</div>
	<script src="js/MessageBox.js"></script>
	<script src="js/jquery.min.js"></script>
</body>
</html>