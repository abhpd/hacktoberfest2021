let letters = "abcdefghijklmnopqrstuvwxyz"
function getVal(char, key){
    return {
        getDecryptVal: (letters.indexOf(char) - key) % 26,
        getEncryptVal: (letters.indexOf(char) + key) % 26,
    }
}
function encrptCeaser(){
    function ceaser(text, key){
        console.log("Plain Text:",text.toUpperCase())
        let cipher = ""
        for (let i = 0; i < text.length; i++) {
            cipher+=letters.charAt(getVal(text[i], key).getEncryptVal)
        }
        return cipher.toUpperCase()
    }
console.log("Encryted:", ceaser("gowithplanb", 4))
}
encrptCeaser()
function decrptCeaser(){
    function ceaser(cipher, key){
        console.log("Cipher Text:",cipher.toUpperCase())
        let text = ""
        for (let i = 0; i < cipher.length; i++) {
            let charIdx = getVal(cipher[i], key).getDecryptVal
            if(charIdx<0){
                text+=letters.slice(charIdx,charIdx+1)
            } else{
                text+=letters.charAt(charIdx)
            }
        }
        return text.toUpperCase()
    }
console.log("Decryted:",ceaser("ksamxltperf", 4))
}
decrptCeaser()