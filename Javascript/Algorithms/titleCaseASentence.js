
/*

titleCase("I'm a little tea pot")

should return I'm A Little Tea Pot
*/
function titleCase(str) {
    // makes str become lowercase
    return str.toLowerCase().split(" ").map(e => {
        // the first character of word to upperCase 
        return e[0].toUpperCase() + e.substr(1)
    }).join(" ");
}

console.log(titleCase("I'm a little tea pot"));
