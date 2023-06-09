// Takes a space separated binary string 
// Return an English translated sentence of the passed binary string

function binaryAgent(str) {
    let convertedString = ""
    let binaryArray = str.split(" ")
    for (let i = 0; i < binaryArray.length; i++) {
      let asciiCode = 0
      let positionFromLeft = 0
      for (let j = binaryArray[i].length - 1; j >= 0; j--) {
        if (binaryArray[i][j] === "1") {
          asciiCode += 2 ** positionFromLeft
        }
        positionFromLeft++;
      }
      convertedString += String.fromCharCode(asciiCode)
    }
    return convertedString
  }
  
  // Sample
  // const result = binaryAgent("01000001 01110010 01100101 01101110 00100111 01110100 00100000 01100010 01101111 01101110 01100110 01101001 01110010 01100101 01110011 00100000 01100110 01110101 01101110 00100001 00111111");
  
  // console.log(result)