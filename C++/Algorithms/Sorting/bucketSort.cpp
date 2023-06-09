//C++ IMPLEMENTATION FOR BUCKET SORT
//Let us assume we need to sort a data having students' marks and names 
#include<iostream>
#include<vector>
using namespace std;
class student{
    public:
    int marks;
    string name;
};
//bucket sort to sort an array of students
void bucket_sort(student s[],int n){
    //assuming marks are in range 0-100
    vector<student> v[101];

    //this will take O(N) time
    for(int i=0 ; i<n ; i++){
        int m = s[i].marks;
        v[m].push_back(s[i]);
    }

    //Iterate over the vector and print the students
    cout<<"\nThe sorted list is : \n";
    for(int i=100 ; i>=0 ; i--){
        for(vector<student>::iterator it = v[i].begin() ; it!=v[i].end(); it++){
            cout<<(*it).marks<<" "<<(*it).name<<endl;
        }
    }
}
int main(){
    student s[1000];
    //enter the number of students
    int n;
    cin>>n;
    //loop to take input of the data
    for(int i=0 ; i<n ; i++){
        cin>>s[i].marks>>s[i].name;
    }
    bucket_sort(s,n);
    return 0;
}
//OUTPUT :
/*
5
10 A
40 B
10 C
68 D
24 R
The sorted list is :
68 D
40 B
24 R
10 A
10 C
*/