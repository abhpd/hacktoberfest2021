package main  
  
import "fmt"  
  
func main() {  
 var operator string  
 var number1, number2 int  
 fmt.Print("Please enter First number: ")  
 fmt.Scanln(&number1)  
 fmt.Print("Please enter Second number: ")  
 fmt.Scanln(&number2)  
 fmt.Print("Please enter Operator (+,-,/,%,*):")  
 fmt.Scanln(&operator)  
 output := 0  
 switch operator {  
 case "+":  
  output = number1 + number2  
  break  
 case "-":  
  output = number1 - number2  
 case "*":  
  output = number1 * number2  
 case "/":  
  output = number1 / number2  
 case "%":  
  output = number1 % number2  
 default:  
  fmt.Println("Invalid Operation")  
 }  
 fmt.Printf("%d %s %d = %d", number1, operator, number2, output)  
}  
