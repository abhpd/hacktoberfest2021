//Create by hhelsinki on HacktoberFest2021
var e = document.getElementById("second");
var f = document.getElementById("first");

var output = document.getElementById("currency-output_display");
var input_display = document.getElementById("currency-input_display");
var currency_switching = document.getElementById("currency-switching");
var input = document.querySelector('#input');
input.addEventListener('input', normal, false);

var usd_left, euro_left, usd_right, euro_right;
usd_left = document.getElementById("usd_left");
euro_left = document.getElementById("euro_left");
usd_right = document.getElementById("usd_right");
euro_right = document.getElementById("euro_right");
var clickMe = document.getElementById("clickMe");

let choiceI = () => {
	usd_left.innerText = "USD";
	euro_left.innerText = "EURO";
	usd_right.innerText = "USD";
	euro_right.innerText = "EURO";
}
let choiceII = () => {
	usd_left.innerText = "EURO";
  	euro_left.innerText = "USD";
  	usd_right.innerText = "EURO";
  	euro_right.innerText = "USD";
}
//test
let showService = () => {
	clickMe.style.visibility = "visible";
}
let hideService = () => {
	clickMe.style.visibility = "hidden";
}

let onCalculate_usd2usd = () => {
	output.innerText = input.value + " us dollar";	
}
let onCalculate_euro2euro = () => {
	output.innerText = input.value + " euro";
}
let onCalculate_usd2euro = () => {
	output.innerText = input.value * .86 + " euro";
}
let onCalculate_euro2usd = () => {
	output.innerText = input.value * 1.16 + " us dollar";
}

//CURRENCY SELECT
function normal() {
const values = e.options[e.selectedIndex].value;
const text = e.options[e.selectedIndex].text;
const valuess = f.options[f.selectedIndex].value;
const textt = f.options[f.selectedIndex].text;
 
  var currency_switching = document.getElementById("currency-switching");
  
  console.log(values, text);
  console.log(valuess, textt);
  
  if (isNaN(input.valueAsNumber)) {
  		output.innerText = "Must be number";
  		return false;
  		}

  switch (values) {
  	case "1":
	
  		switch (valuess) {
  			case "1":
  			onCalculate_usd2euro();
  			showService();
  			console.log('normal 1-1');
  			break;
  			
  			case "2":
  			onCalculate_usd2usd();
  			hideService();
  			console.log('normal 1-2');
  			break;
  			default:
  			console.log("unknow");
  		}
  		input_display.innerText = "USD ";
  		choiceI();
  	break;
  	
  	case "2":
  		switch (valuess) {
  			case "1":
  			onCalculate_euro2euro();
  			hideService();
  			console.log('normal 2-1');

  			break;
  			case "2":
  			onCalculate_euro2usd();
  			showService();
  			console.log('normal 2-2');
  			break;
  			default:
  			console.log("unknow");
  		}
  		input_display.innerText = "EURO ";
  		choiceI();
  	break;
  	
  	default:
  	console.log("unknow");
  	break;
  	
  }
}

function abnormal() {
const values = e.options[e.selectedIndex].value;
const text = e.options[e.selectedIndex].text;
const valuess = f.options[f.selectedIndex].value;
const textt = f.options[f.selectedIndex].text;
  var currency_switching = document.getElementById("currency-switching");

  console.log(values, text);
  console.log(valuess, textt);
  
  if (isNaN(input.valueAsNumber)) {
  		output.innerText = "Must be number";
  		return false;
  		}

  switch (values) {
  	case "1":
  	
  		switch (valuess) {
  			case "1":
  			onCalculate_euro2usd();
  			showService();
  			console.log('inverse 1-1');
  			
  			break;
  			case "2":
  			onCalculate_euro2euro();
  			hideService();
  			console.log('inverse 1-2');
  			
  			break;
  			default:
  			console.log("unknow");
  		}
		input_display.innerText = "EURO ";
		choiceII();
  	break;
  	
  	case "2":
  		switch (valuess) {
  			case "1":
  			onCalculate_usd2usd();
  			hideService();
  			console.log('inverse 2-1');
  			break;
  			
  			case "2":
  			onCalculate_usd2euro();
  			showService();
  			console.log('inverse 2-2');
  			break;
  			default:
  			console.log("unknow");
  		}
  		input_display.innerText = "USD ";
		choiceII();
  	break;
  	
  	default:
  	console.log("unknow");
  	break;
  }
}

e.onchange=normal;
f.onchange=normal;
normal();

//trigger
var click = 0;

function trigger() {
	click += 1;
	if (click % 2 == 1) {
		abnormal();
		console.log('abnormal_odd');
		e.onchange=abnormal;
		f.onchange=abnormal;
	} else { 
		normal();
		console.log('normal_even');
		e.onchange=normal;
		f.onchange=normal;
		}
}

var clickMe = document.getElementById("clickMe");
clickMe.addEventListener('click', trigger, false);
//Create by hhelsinki on HacktoberFest2021