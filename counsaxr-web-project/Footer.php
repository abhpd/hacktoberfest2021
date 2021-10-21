<!-- Footer-->
<section id="footer1">
<footer class="bg-grey py-5">
<div class="container">
   <div class="row">
      <div class="col-md-6 col-sm-12">
         <div class="row">
            <div class="col-md-6 ">
               <div class="logo-part">
                  <img src="" class="w-50 logo-footer" ><h4 class="pt-3 logotext">CounsaXR</h4>
                  <p class="pt-5">Future of Online Surveillence.</p>
                  <p class="pb-3">10+ k followers with high ratings.</p>
               </div>
            </div>
            <div class="col-md-6 px-4">
               <h6> About Us</h6>
               <p>Contact- 047 4 549 754</p>
               <p>Fax- 047 4 549 753</p>
               <p>Email- counsaxr@info.lk</p>
               <a href="#" class="btn-footer"> Team </a><br>
               <a href="#" class="btn-footer"> Explore Now</a>
            </div>
         </div>
      </div>
      <div class="col-md-6 ">
         <div class="row">
            <div class="col-md-6 px-4">
               <h6> Qucik Link</h6>
               <div class="row ">
                  <div class="col-md-6">
                     <ul>
                     <?php if( (basename($_SERVER['PHP_SELF']) == "home.php" ) or (($_SERVER['PHP_SELF']) == "Home.php") or (($_SERVER['PHP_SELF']) == "") ) {?>
                        <li> <a href="#"> Services</a> </li>
                        <li> <a href="#"> Join</a> </li>
                        <li> <a href="#"> SignIn</a> </li>
                     <?php } else {?>
                        <li> <a href="Home.php"> Home</a> </li>
                        <li> <a href="#"> Notifications</a> </li>
                        <li> <a href="#"> Messages</a> </li>
                        <li> <a href="#"> SignOut</a> </li>
                     <?php } ?>
                     </ul>
                  </div>
               </div>
            </div>
            <div class="col-md-6 ">
               <h6> Connect via</h6>
               <div class="social">
                  <a href="#"><i class="fab fa-twitter"></i></a>
                  <a href="#"><i class="fab fa-linkedin-in"></i></a>
                  <a href="#"><i class="fab fa-google-plus-g"></i></a>
                  <a href="#"><i class="fab fa-facebook-square"></i></a>
                  <a href="#"><i class="fab fa-youtube"></i></a>
                  <a href=""><i class="fab fa-instagram"></i></a>
               </div>
           		
            </div><p class="text-center pt-3" style="font-size: 15px;">Copyright © 2021, All Right Reserved CounsaXR.</p>
         </div>
      </div>
   </div>
</div>
</footer>
</section>