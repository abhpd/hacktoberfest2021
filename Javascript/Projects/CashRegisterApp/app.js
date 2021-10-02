var billAmount = document.querySelector("#billAmount");
let cashGiven = document.getElementById("cashGiven");
let button = document.getElementById("tenderChange");
let ul = document.createElement("ul");
let output = document.querySelector(".output");
let error = document.querySelector(".error");

button.addEventListener("click", tenderChangeHandler);

let currencies = [1, 5, 10, 20, 100, 500, 2000];
let denominations = {};

function tenderChangeHandler() {
  ul.innerHTML = "";
  if (billAmount.value === "" || cashGiven.value === "") {
    error.innerText = "Please Enter Both the Fields";
    setTimeout(() => {
      error.innerText = "";
    }, 3000);
  } else if (cashGiven.value < billAmount.value) {
    console.log("Cash given is less than the Bill Amount");
    error.innerText =
      "Cash given is less than the Bill Amount, Please Enter Again";
    setTimeout(() => {
      error.innerText = "";
      billAmount.value = "";
      cashGiven.value = "";
    }, 3000);
  } else if (cashGiven.value === billAmount.value) {
    error.className = "green";
    error.innerText = "Thanks for giving the exact Amount";
    setTimeout(() => {
      error.innerText = "";
      error.className = "error";
      billAmount.value = "";
      cashGiven.value = "";
    }, 3000);
  } else {
    let change = cashGiven.value - billAmount.value;
    console.log(change);

    for (let i = currencies.length - 1; i >= 0; i--) {
      let counter = 0;
      while (currencies[i] <= change) {
        change -= currencies[i];
        console.log(change);
        counter++;
        denominations[`${currencies[i]}`] = counter;
      }
    }
    console.log(denominations);

    for (let currency of Object.keys(denominations)) {
      let li = document.createElement("li");
      li.innerText = `Rs ${currency} = ${denominations[currency]} denomination`;
      ul.appendChild(li);
    }
    output.appendChild(ul);
    denominations = {};
    setTimeout(() => {
      billAmount.value = "";
      cashGiven.value = "";
    }, 3000);
  }
}
