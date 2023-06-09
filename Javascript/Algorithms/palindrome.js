function palindrome(str) {
    len = str.length
    for (var i = 0; i < len / 2; i++) {
        if (str[i] !== str[len - 1 - i]) {
            return false
        }
    }
    return true
}

palindrome("abcba") //true
palindrome("abcde") //false