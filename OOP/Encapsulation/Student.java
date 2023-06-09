package Encapsulation;

public class Student{
    //private data member
    private String name;

    public Student() {
        super();
    }

    public Student(String name) {
        this.name = name;
    }

    //getter method for name
    public String getName(){
        return name;
    }
    //setter method for name
    public void setName(String name){
        this.name=name;
    }
}