var initialcost = document.querySelector("#initial_val");
var quantity = document.querySelector("#quantity");
var currentcost = document.querySelector("#current_val");
var btn = document.querySelector("#btn");
var output = document.querySelector("#output");
var container = document.querySelector(".container");
function checkProfitLoss(initialcost, quantity, currentcost) {
  currentcost = currentcost * quantity;
  initialcost = initialcost * quantity;
  //console.log(currentcost, initialcost);
  if (currentcost > initialcost) {
    var profit = currentcost - initialcost;
    var profitPercentage = ((profit / initialcost) * 100).toFixed(2);
    console.log(profit, profitPercentage);

    container.style.background = "rgb(116, 216, 184)";
    output.style.color = "green";
    output.innerHTML = `Your total profit is ₹${profit} and profit percentage ${profitPercentage}%. `;
  } else {
    var loss = initialcost - currentcost;
    var lossPercentage = ((loss / initialcost) * 100).toFixed(2);
    output.style.color = "red";
    container.style.background = "rgb(255, 169, 169)";
    output.innerHTML = `Your total loss is ₹${loss} and loss percentage ${lossPercentage}%. `;
    console.log(loss, lossPercentage);
  }
}

function clickHandler() {
  let ic = Number(initialcost.value);
  let qn = Number(quantity.value);
  let curr = Number(currentcost.value);
  console.log(ic, qn, curr);
  if (qn === 0 || ic === 0 || curr === 0) {
    console.log("All the fields are mandatory, please enter all the values!");
    output.innerHTML =
      "All the fields are mandatory, please enter all the values!";
  } else if (ic == curr) {
    output.innerHTML = "Neither profit nor loss";
  } else {
    checkProfitLoss(ic, qn, curr);
  }

  //console.log("ccc", Number(currentcost.value), Number(initialcost.value));
}
btn.addEventListener("click", clickHandler);
