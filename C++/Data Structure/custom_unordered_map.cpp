// using custom classes as keys for unordered maps

//  Need to do 2 things mainly:
//      1. create our own HASH FUNCTION as for inbuilt types' wont work
//      2. overload the "==" operator to tell STL class how to compare objects 

#include<iostream>
#include<unordered_map>
using namespace std;


class Student
{
public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string no)
    {
        firstname = f;
        lastname = l;
        rollno = no;
    }

    // your class should have this operator overloaded inside so STL can work
    bool operator==(const Student &s) const
    {
        return rollno == s.rollno; // checks if given student is same as current
    }
};

// HASH FUNCTION THAT WE NEED TO DEFINE
class HashFN
{
    public:
        // you NEED to have this inside the custom has function
        size_t operator() (const Student &s) const
        {
            // very simple hash function based on the length of names combined
            return s.firstname.length() + s.lastname.length();
        }
};

int main()
{
    // SUPPLY IN YOUR HASH FUNCTION HERE!
    unordered_map<Student, int, HashFN> student_map;


    Student s1("Prateek", "Narang", "010");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Prateek", "Gupta", "030");
    Student s4("Rahul", "Kumar", "120");
    
    // adding to our unorderedmap object
    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 11;
    student_map[s4] = 45;
    
    // checking the output
    for (auto s: student_map)
    {
        // this 's' consists of the pair datatype
        cout << s.first.firstname << " " << s.first.rollno << endl;
    }

    return 0;
}
