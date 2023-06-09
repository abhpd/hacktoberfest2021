/*
username : yusril86
name : Yusril

 Palindrome Text
*/


fun FizzBuzz(num: Int): Int {

    // code goes here
    for(i in 1..num){
        if(i % 3 == 0 &&  i % 5 == 0  ){
            println("Fizz Buzz")
        }else if( i % 3 == 0){
            println("Fizz")
        }else if( i % 5 == 0 ){
            println("Buzz")
        }else{
            println(i)
        }
    }
    return num;

}

fun main() {
    //set value numbers
    println(FizzBuzz(5))
}