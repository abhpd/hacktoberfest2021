package Inheritance;

public class Student extends Person {
    private String ownerName;
    private boolean isAtHostel;

    public Student(String ownerName, boolean isAtHostel) {
        this.ownerName = ownerName;
        this.isAtHostel = isAtHostel;
    }

    public Student(String firstName, String lastName, String address, String ownerName, boolean isAtHostel) {
        super(firstName, lastName, address);
        this.ownerName = ownerName;
        this.isAtHostel = isAtHostel;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public boolean isAtHostel() {
        return isAtHostel;
    }

    public void setAtHostel(boolean atHostel) {
        isAtHostel = atHostel;
    }

    @Override
    public String print() {
        return "Dear Teacher, my father is "+ ownerName+".";
    }
}
