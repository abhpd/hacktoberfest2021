package Inheritance;

public class Test {
    public void main(String[] args){
        Person teacher1 = new Teacher("John", "Tarbet", "Sri Lanka", "Science");
        Person teacher2 = new Teacher("Ann", "Tarbet", "Australia", "Maths");

        Person student1 = new Student("Nimal", "Jackson", "Sri Lanka", "Mason", true);
        Person student2 = new Student("Kamal", "Jackson", "Australia", "Avery", false);

        System.out.println(teacher1.print());
        System.out.println(teacher2.print());
        System.out.println(student1.print());
        System.out.println(student2.print());
    }
}
