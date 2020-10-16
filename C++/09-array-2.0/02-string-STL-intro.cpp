#include <iostream>
#include <cstring> // string class
#include <algorithm> // all algorithms like sorting and searching
using namespace std;

bool compare1(string s1, string s2){
   return s1>s2; // char scii comparion
}

bool compare2(string s1, string s2){
   return s1.length()>s2.length(); // string length comarision
}

bool compare3(string s1, string s2){
   return s1<s2; // char comparion
}



int main() {
   string s1("Hello world");
   cout<<s1<<s1.length()<<endl;

   string s2 = "Second String!";
   cout<<s2<<s2.length()<<endl;

   // input string
   string s3;
   getline(cin, s3);
   cout<<s3<<s3.length()<<endl;
   
   // string array
   string arr[] = {"Apple","Appoooo", "Pineappleeeee", "Guavaaaa"};
   for(int i=0; i<4; i++){
      cout<<arr[i]<<s1.length()<<", ";
   }
   cout<<endl;
   //default
   sort(arr,arr+4);
   for(int i=0; i<4; i++){
      cout<<arr[i]<<s1.length()<<", ";
   }
   cout<<endl;
   //compare1
   sort(arr,arr+4,compare1);
   for(int i=0; i<4; i++){
      cout<<arr[i]<<s1.length()<<", ";
   }
   cout<<endl;
   //compare2
   sort(arr,arr+4,compare2);
   for(int i=0; i<4; i++){
      cout<<arr[i]<<s1.length()<<", ";
   }
   cout<<endl;
   //compare3
   sort(arr,arr+4,compare3);
   for(int i=0; i<4; i++){
      cout<<arr[i]<<s1.length()<<", ";
   }
   cout<<endl;

   return 0;
}


/*


*/