<header>

<?php 
session_start(); 
?>

<!-- navbar-->
<nav class="navbar navbar-expand-sm navbar-dark  fixed-top navex">
  <div class="container">
    <a class="navbar-brand" href="#">CounsaXR</a>
    <button class="navbar-toggler" type="button" id="btn1" onclick="openFunction()">
     <img id="toga" src="images/toggle.gif"></i>
    </button>

    <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav ms-auto mb-2 mb-lg-0 float-end">
        <?php if( (basename($_SERVER['PHP_SELF']) == "home.php" ) or (($_SERVER['PHP_SELF']) == "Home.php") or (($_SERVER['PHP_SELF']) == "") ) {?>
          <li class="nav-item">
            <a class="nav-link ms-3 active" href="#" >Home</a></li>
          <li class="nav-item">
            <a class="nav-link ms-3" href="#">Services</a></li>
          <li class="nav-item">
            <a class="nav-link ms-3" href="#">ContactUs</a></li>
        <?php } ?>

<?php if( (!isset($_SESSION["userid"])) ) { ?>
        <li class="nav-item">
          <a class="nav-link ms-3" href="Register/Register.html">Join</a></li>
        <li class="nav-item">
          <a class="nav-link ms-3" href="login/login.html">SignIn</a></li>
<?php } else { 
      if( basename($_SERVER['PHP_SELF']) == "CounselorPage.php" ) { ?>
        <li class="nav-item">
          <a class="nav-link ms-3" href="#" data-bs-toggle="offcanvas" data-bs-target="#offcanvasExample" aria-controls="offcanvasExample"><i class="fa fa-edit xx1 pr-3" ></i></a></li>
        <li class="nav-item">
          <a class="nav-link ms-3" href="editProfile.php"><i class="fa fa-user-circle xx1 pr-3" ></i></a></li>
<?php } else{ 
  if( !(basename($_SERVER['PHP_SELF']) == "PatientPage.php" )) {
    if( $_SESSION['usertype'] == 'CN'){ ?>
        <li class="nav-item">
          <a class="nav-link ms-3" href="CounselorPage.php"><i class="fas fa-address-card xx1 pr-3"></i></a></li>
<?php }else if ( $_SESSION['usertype'] == 'PT'){ ?>
        <li class="nav-item">
          <a class="nav-link ms-3" href="PatientPage.php"><i class="fas fa-address-card xx1 pr-3"></i></a></li>
<?php }
  } else { ?>
        <li class="nav-item">
          <a class="nav-link ms-3" href="editProfile.php"><i class="fa fa-user-circle xx1 pr-3" ></i></a></li>

<?php
  }
   } ?>
        <li class="nav-item">
          <a class="icon nav-link ms-3" onclick="toggleMsg()" ><i class="fas fa-envelope xx1 pr-3" ></i><?php include_once "Includes/getMessageCount.inc.php"; ?></a></li>
          <div class="notifi-box" id="box2">
            <?php include_once "Includes/getUnreadMessage.inc.php"; ?> 
          </div>
        <li class="nav-item">
            <a class="icon nav-link ms-3" onclick="toggleNotifi()" ><i class="fas fa-bell xx1 pr-3" ></i> <?php include_once "Includes/getNotificationCount.inc.php"; ?> </a></li>
            <div class="notifi-box" id="box">
              <?php include_once "Includes/getUnreadNotification.inc.php"; ?> 
            </div>
        <li class="nav-item">
            <a class="nav-link ms-3" href="Includes/logout.inc.php"><i class="fad fa-sign-out xx1 pr-3"></i></a></li>
<?php } ?>
      </ul>  
  </div>
</nav>

  <!--toogle navbar-->
	<div class="sidemenu" id="menu">     
          <a  href="#">Home</a></li>        
          <a  href="#">Services</a></li>               
          <a  href="Register/Register.html">Join</a></li>
          <a  href="Login/login.html">Login</a></li>
          <a  class="closebtn" onclick="closeFunction()">&times;</a>
  </div>