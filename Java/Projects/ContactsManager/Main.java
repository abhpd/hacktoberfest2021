public class Main {

    /**
     * Main class to execute the program
     */
    public static void main(String[] args) throws NullPointerException{

        ContactsManager myContactManager = new ContactsManager();

        //Create a new Contact object for James
        Contact info0 = new Contact();

        //set the contact's fields
        info0.name = "James Lolly";
        info0.phoneNumber = "0823456784";
        info0.email = "jameslolly@mail.com";

        //adding the contact to ContactManager
        myContactManager.addContact(info0);

        //Create a new Contact Object for Tobz
        Contact info1 = new Contact();
        //set the fields
        info1.name = "Tobz Green";
        info1.phoneNumber = "058666445";
        info1.email = "tobz@mail.com";

        //adding the Contact to the ContactManager
        myContactManager.addContact(info1);

        //Create a new Contact Object for Stones
        Contact info2 = new Contact();
        //set the fields
        info2.name = "Stones Mandy";
        info2.phoneNumber = "0998776553";
        info2.email = "stonesmandy@mail.com";

        //adding the Contact to the ContactManager
        myContactManager.addContact(info2);

        //Search for the name in the list and print its details such as name, number or mail
        Contact result = myContactManager.searchContact("Stones Mandy");
        System.out.println("Name: " + result.name + ", Number: " + result.phoneNumber);
    }
}