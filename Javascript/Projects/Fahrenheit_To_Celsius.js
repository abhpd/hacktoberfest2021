function fToC(fahrenheit) 
{
  var fTemp = prompt("Enter In Fahrenheit:");
  var fToCel = (fTemp - 32) * 5 / 9;
  var message = fTemp+'\xB0F is ' + fToCel + '\xB0C.';
  alert(message);
} 
fToC();
