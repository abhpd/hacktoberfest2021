function genPassword(NOfChar) {
  let PassWord = "";

  for (i = 0; i < NOfChar; ) {
    let stringTester = /^[0-9a-zA-Z]+$/;
    let TempString = String.fromCharCode(Math.floor(Math.random() * 92) + 33);

    if (TempString.match(stringTester)) {
      PassWord += TempString;
      i++;
    }
  }

  return PassWord;
}

console.log(genPassword(6));
