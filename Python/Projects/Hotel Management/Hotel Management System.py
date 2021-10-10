"""
GUIDE :
Functionalities provided by the system :

Booking
No of rooms available (Shows the number of vacant rooms in the hotel)
No of rooms reserved (Shows the number of booked rooms in the hotel)
Make a booking (Book a room)

Enquiry
Searching with name of customer (Shows the details of the customer)
Searching with room number (Shows the details of the customer occupying that specific room)
Check Room availability (Shows the number of rooms that are presently vacant)

Edit booking details
Edit (Edit the booking details of the customer)
Delete (Delete the booking details of the customer)
"""

#Class to implement hotel details
class hotel:
    def __init__(self,rooms_avail,rooms_reserved,room_no):
        self.rooms_avail=rooms_avail
        self.rooms_reserved=rooms_reserved
        self.room_no=room_no
        
        #Function to update count of vacant and reserved rooms after each booking
    def update_hotel_details(self,rooms):
        self.rooms_avail=self.rooms_avail- rooms
        self.rooms_reserved=self.rooms_reserved + rooms

#Assuming there are 100 vacant rooms in the hotel initially and room no. of first room is 1
#Creating a hotel class object
h=hotel(100,0,1)

#####################################

#Dictionary to store the booking details of the customers
database={}

#Class to implement Customer Details
class customer(hotel):
    def __init__(self,name,contact,rooms,duration):
        self.name=name
        self.contact=contact
        self.rooms=rooms
        self.duration=duration
   
    #Function to fill the data into dictionary
    def fill_data(self):
        key=self.name
        rooms_alloted=generate_roomnum(self.rooms)
        database[key]=[self.contact,self.rooms,self.duration,rooms_alloted]
        h.update_hotel_details(self.rooms)

#####################################

#Function to generate room numbers to be allotted to the customer
def generate_roomnum(num):
    rooms=[]
    for i in range(h.room_no,h.room_no+num):
        rooms.append(i)
    h.room_no=h.room_no+num
    return rooms # returns a list of room numbers to be allotted to that particular customer

#####################################


#Function for Booking Menu
def booking():
    while True:
        print("\nBooking Menu:")
        print("1. No. of rooms available")
        print("2. No. of rooms reserved")
        print("3. Make a Booking")
        print("4. Go to previous menu")
        choice=int(input("Enter Your Choice : "))
        if(choice==1):
            print("--> No. of rooms available are ",h.rooms_avail,"\n")
        elif(choice==2):
            print("--> No. of rooms reserved are ",h.rooms_reserved,"\n")
        elif(choice==3):
            book_rooms()
        elif(choice==4):
            return
        else:
            print("Please Enter Valid Input.")
    
#Function to take in booking details and book rooms
def book_rooms():
    print("Please Enter Your Details :")
    name=input("Customer Name : ")
    contact=input("Contact No. : ")
    rooms=int(input("No. of Rooms you want to book : "))
    duration = int(input("Duration of your stay(in days) : "))
    c=customer(name,contact,rooms,duration) #Making a customer class object
    c.fill_data() #populating data

#Function for Enquiry Menu
def enquiry():
    while True:
        print("\nEnquiry Menu:")
        print("1. Search by name of customer")
        print("2. Search by room number")
        print("3. Check for room availability")
        print("4. Go to previous menu")
        choice=int(input("Enter Your Choice : "))
        if(choice==1):
            searchByCustomerName()
        elif(choice==2):
            searchByRoomNo()
        elif(choice==3):
            print(f"There are {h.rooms_avail} rooms available for booking.")
        elif(choice==4):
            return
        else:
            print("Please enter valid input")

#Function to search booking details by customer name
def searchByCustomerName():
    name=input("\nEnter Name of Customer : ")
    if name in database.keys():
        print("Record Found !")
        print(f"Name : {name} , Contact No. : {database[name][0]} , Rooms Booked : {database[name][1]} , Stay Duration : {database[name][2]} days.")
        print("Rooms Alloted : ",database[name][3])
        
    else:
        print("Record Not Found.")
        return


#Function to Search booking details by room no.
def searchByRoomNo():
    num=int(input("\nEnter Room No. of Customer : "))
    flag=0
    for i in database.keys():
        if num in database[i][3]:
            print("Record Found ! This Room has been booked by :")
            print(f"Name : {i} , Contact No. : {database[i][0]} , Rooms Booked : {database[i][1]} , Stay Duration : {database[i][2]} days.")
            flag=1
            return
    if flag==0:
        print("Room is unbooked!")
        return


#Function for edit menu
def edit_menu():
    choice=input("\nHave you made a booking yet ? (y/n) :") #proceed to edit only if a booking is made by the customer
    if choice=='n':
        return
    else:
        print("\nWhat would you like to do ?")
        print("1. Edit booking")
        print("2. Delete booking")
        print("3. Go to previous menu")
        while True:
            ch=int(input("Enter Your Choice : "))
            if ch==1:
                edit()
            elif ch==2:
                delete()
            elif ch==3:
                return
            else:
                print("Please enter valid input")

#Function to delete booking record
def delete():
    name=input("Enter Name of Customer : ")
    h.rooms_avail+=database[name][1] #adjusting count of rooms when record will be deleted
    h.rooms_reserved-=database[name][1]
    del database[name]

    print("Your booking has been deleted !")

#function to edit booking record details
def edit():
    name=input("Enter Name of Customer : ")
    contact=input("Enter new contact number : ")
    duration = input("Enter new duration(in days) : ")
    database[name][0]=contact
    database[name][2]=duration
    
    print("Booking details updated")

#driver function
def start():
   
    while True:
        print("\nHome Menu :")
        print("1. Booking")
        print("2. Enquiry")
        print("3. Edit booking details")
        print("4. Exit")
        choice=int(input("Enter Your Choice : "))
        if(choice==1):
            booking()
        elif(choice==2):
            enquiry()
        elif(choice==3):
            edit_menu()
        elif(choice==4):
            print("\nThank you for using the hotel management system!")
            break
        else:
            print("Please enter valid input.")

start()

