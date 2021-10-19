package Inheritance;

public class Teacher extends Person {
    private String subject;

    public Teacher(String subject) {
        this.subject = subject;
    }

    public Teacher(String firstName, String lastName, String address, String subject) {
        super(firstName, lastName, address);
        this.subject = subject;
    }

    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    @Override
    public String print() {
        return "Dear Students, I am your "+ subject+ " teacher.";
    }
}
