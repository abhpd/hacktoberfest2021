package main
import (
    "fmt"
    "strings"  
)
func main(){
    var a int
    times := 0
    number := []int64{1,1}
    fmt.Print("Enter a Input:")
    fmt.Scan(&a)
    fmt.Println("1\n1 1")
    for times <= a {
        newnumlis := []int64{1}
        for i := 0;i<=len(number)-2;i++{
            newnum := number[i] + number[i+1]
            newnumlis = append(newnumlis,newnum)
            }
        newnumlis = append(newnumlis,1)
        times +=1
        number = newnumlis
        fmt.Println(strings.Trim(fmt.Sprint(number), "[]"))
    }
}
