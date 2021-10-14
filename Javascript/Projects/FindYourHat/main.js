const prompt = require("prompt-sync")({ sigint: true });

const hat = "^";
const hole = "O";
const fieldCharacter = "░";
const pathCharacter = "*";

class Field {
  constructor(arr) {
    this._field = arr;
  }
  print() {
    console.log(this._field.join("\n").replace(/,/gi, ""));
  }
}
const myField = new Field([
  ["*", "░", "O"],
  ["░", "O", "░"],
  ["░", "^", "░"],
]);
myField.print();
flag = true;
let arr = myField._field.reduce((acc, val) => acc.concat(val), []);
let index = arr.indexOf(pathCharacter);
while (flag == true) {
  const way = prompt("Which way?");
  if (way == "l") {
    if (index == 0 || index == 3 || index == 6) {
      console.log("you have stepped out of bounds you lose");
      flag = false;
      return;
    } else if (arr[index - 1] == hat) {
      console.log("you won");
      flag = false;
      return;
    } else if (arr[index - 1] == hole) {
      console.log("you have fallen in a hole there is no escaping bye!");
      flag = false;
      return;
    } else {
      arr[index] = fieldCharacter;
      arr[index - 1] = pathCharacter;
    }
  }
  if (way == "r") {
    if (index == 2 || index == 5 || index == 8) {
      console.log("you have stepped out of bounds you lose");
      flag = false;
      return;
    } else if (arr[index + 1] == hat) {
      console.log("you won");
      flag = false;
      return;
    } else if (arr[index + 1] == hole) {
      console.log("you have fallen in a hole there is no escaping bye!");
      flag = false;
      return;
    } else {
      arr[index] = fieldCharacter;
      arr[index + 1] = pathCharacter;
    }
  }
  if (way == "d") {
    if (index >= 6) {
      console.log("you have stepped out of bounds you lose");
      flag = false;
      return;
    } else if (arr[index + 3] == hat) {
      console.log("you won");
      flag = false;
      return;
    } else if (arr[index + 3] == hole) {
      console.log("you have fallen in a hole there is no escaping bye!");
      flag = false;
      return;
    } else {
      arr[index] = fieldCharacter;
      arr[index + 3] = pathCharacter;
    }
  }
  if (way == "u") {
    if (index <= 2) {
      console.log("you have stepped out of bounds you lose");
      flag = false;
      return;
    } else if (arr[index - 3] == hat) {
      console.log("you won");
      flag = false;
      return;
    } else if (arr[index - 3] == hole) {
      console.log("you have fallen in a hole there is no escaping bye!");
      flag = false;
      return;
    } else {
      arr[index] = fieldCharacter;
      arr[index - 3] = pathCharacter;
    }
  }
  let newStr = "";
  for (let i = 0; i < arr.length; i++) {
    newStr += arr[i];
    if (i == 2 || i == 5) {
      newStr += "\n";
    }
  }

  console.log(newStr);
  index = arr.indexOf(pathCharacter);
}
