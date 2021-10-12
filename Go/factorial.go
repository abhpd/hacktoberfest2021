// This program outputs the factorial of a number.
package main
import "fmt"


var fact uint64 = 1 

var i int = 1
var n int


func factorial(n int) uint64 {   
    if(n < 0){
        fmt.Print("Factorial of negative number doesn't exist.")    
    }else{        
        for i:=1; i<=n; i++ {
            fact *= uint64(i)  
        }

    }    
    return fact  
}

func main(){    
    fmt.Print("Enter a positive integer: ")
    fmt.Scan(&n)   
    fmt.Print("Factorial is: ",factorial(n))
}
