
// Evaluate Function
function eva() {
  var  a= ""
  var  b= ""
    a=document.getElementById("ok").value;
     b=eval(a);
      document.getElementById("ok").value = b;
}

// Clear function
function c(){
  var c=document.getElementById("ok").value = ""
}
  