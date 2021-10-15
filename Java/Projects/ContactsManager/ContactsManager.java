/**
 * A program that stores contact's information and outputs a given searched contact when querried.
 */
public class ContactsManager {

    //Fields: for the contact manager class
    Contact[] myFriends;
    int friendsCount;

    // Constructor
    public ContactsManager() {
        this.friendsCount = 0;
        this.myFriends = new Contact[15];
    }

    //Add Contact and update the count
    public void addContact(Contact contact) {
        myFriends[friendsCount] = contact;
        friendsCount++;
    }
    //Search for contact in the list and return the name
    public Contact searchContact(String searchName) {
        for (int i = 0; i < friendsCount; i++) {
            if (myFriends[i].name.equals(searchName)) {
                return myFriends[i];
            }
        }
        return null;
    }
}