/* In order to start learning React one should have basic knowledge of 
below operations and how to use them.*/

// Spread Operator
 arr = [1,2,3,4]

 function sum(a,b,c){
    return a+b+c;
 }

 let ans = sum(...arr);
 console.log(ans);

let a = [...arr]
console.log(a)

let obj = {
   name1: "abc",
   lang: "Java"
}

let obj2 = {...obj}
console.log(obj2)

let obj2 = {...obj,lang: "JavaScript"}
console.log(obj2)

let {name1,lang} = obj;
console.log(name1)


//async 

console.log("Hello1")
setTimeout(() => {
   console.log("Hello2")
}, 5000);
console.log("hello3")


//Promises and Callbacks

let fs = require("fs");
let fs = require("fs/promises");

fs.readFile("important.txt","utf8",(err,data)=>{
   console.log(err,data)
})

console.log("THis is waiting")

let a = fs.readFile("important.txt","utf8");
a.then(
   (data)=>{
      console.log(data);
   }
)

// async & await 

const readThree = async (f1,f2,f3) =>{
   let a1 = fs.readFile(f1,"utf8");
   let a2 = fs.readFile(f2,"utf8");
   let a3 = fs.readFile(f3,"utf8");
   let c1 = await a1;
   console.log(c1);
   let c2 = await a2;
   console.log(c2);
   let c3 = await a3;
   console.log(c3);
}

readThree("important.txt","TreeTraversal.txt","BillingAmbutrack.txt");

// Map, filter & reduce

let a2 = arr.map((val)=>{
   return val+5;
})

console.log(a2);

let a3 = arr.filter((val)=> {
   return val < 3;
})

console.log(a3)

let a4 = arr.reduce((val1,val2,val3)=> {
   return val1+val2+val3;
})

console.log(a4)