let chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
  plainText = "",
  cipherText = "";
function encrpyt(textChar, keyChar) {
  let modVal = (chars.indexOf(keyChar) + chars.indexOf(textChar)) % 26;
  return chars[modVal];
}
function decrpyt(textChar, keyChar) {
  let modVal = (chars.indexOf(textChar) - chars.indexOf(keyChar)) % 26;
  if (modVal < 0) {
    modVal += 26;
  }
  return chars[modVal];
}
function vigenereE(text, key) {
  key = key.toUpperCase();
  text = text.split(" ").join("").toUpperCase();
  console.log("\nPlain Text:", text);
  let textArr = text.split("").reverse();
  let i = 0;
  while (i <= key.length) {
    if (i === key.length) i = 0;
    cipherText += encrpyt(textArr.pop(), key[i]);
    if (textArr.length === 0) break;
    i++;
  }
  return "Cipher Text: " + cipherText;
}
function vigenereD(ctext, key) {
  key = key.toUpperCase();
  ctext = ctext.split(" ").join("").toUpperCase();
  console.log("\nCipher Text:", ctext);
  let textArr = ctext.split("").reverse();
  let i = 0;
  while (i <= key.length) {
    if (i === key.length) i = 0;
    plainText += decrpyt(textArr.pop(), key[i]);
    if (textArr.length === 0) break;
    i++;
  }
  return "Plain Text: " + plainText;
}
console.log(vigenereE("go to left and click right button", "krishna"));
console.log(vigenereD("QFBGSRFDRVVJYIMBZANUTLLBLVA", "krishna"));
