# This File contains all the sql functions required in the project including a) Create Account b) Transaction option with Bank -> Bank, Bank-> Customer, Customer -> Bank, c) Transaction History, d) Delete Account
import mysql.connector
from datetime import date, datetime
from date_verifier import date_input
from credentials import Credentials
from prettytable import from_db_cursor, PrettyTable

query1 = "Update user set transid = %s where account = %s"
query2 = "insert into amount values(%s,%s,%s)"
query3 = "delete from user where account = %s"
query4 = "select transid, sender, beneficiary, date, sender_amount from trans natural join amount where trans.transid = %s and sender = %s"
query5 = "select transid, sender, beneficiary, date, sender_amount from trans natural join amount where sender = %s and Date between %s and %s"
query6 = "select transid, sender, beneficiary, date, beneficiary_amount from trans natural join amount where Date between %s and %s and beneficiary = %s"
query7 = "select transid, sender, beneficiary, date, beneficiary_amount from trans natural join amount where Date = %s and beneficiary = %s"

Date = date.today().strftime('%Y/%m/%d')
mydb = mysql.connector.connect(**Credentials)
mycursor = mydb.cursor(buffered=True)
mycursor1 = mydb.cursor(buffered=True)
mycursor.execute('create table if not exists user(account char(17) Primary Key, name Varchar(20) Not Null, Phone char(11) Not Null,email varchar(35) Unique Not Null, Balance int(16) check(Balance >-1) Not Null, transid varchar(25) not null, TOA varchar(10) Not Null, DOC date Not Null)')
mycursor.execute('create table if not exists trans(Sender char(17) references user(account), Beneficiary char(17) references user(account), transid varchar(25) not null, date date not null, amount varchar(16))')
mycursor.execute('create table if not exists amount(transid varchar(25) not null Primary Key,Sender_amount int(16), Beneficiary_amount int(16) )')

def check_details(email):
    mycursor.execute('Select email from user where email = %s',(email,))
    if(mycursor.rowcount !=0):
        return (False, 'Email Already Exists in database kindly enter other Email')
    return (True,)

def new_user(name, phone, email):
    if not(phone.isdigit() and len(phone) == 10):
        return (False, "Please Enter Digits in Mobile number and/or Enter mobile number without country code\n")
    if not(check_details(email)[0]):
        return check_details(email)
    if(len(name) >= 20):
        return(False, "Kindly Enter Name within 20 Characters\n")
    if(len(email) >= 35):
        return(False, "Kindly Enter Email within 35 characters\n")
    elif(email.count('@') != 1):
        return(False, "Kindly Enter 1 '@' in email\n")
    elif(email[0] == '@'):
        return(False, "Kindly enter your username of email before entering '@'\n")

    account = datetime.today().strftime('%Y%m%d%H%M%S%f')[:16]
    mycursor.execute("Insert into user values(%s,%s,%s,%s,%s,%s,%s,%s)",
                     (account, name, phone, email, 1000, account+'1', "savings", Date))
    mycursor.execute("Insert into trans values('Self', %s, %s, %s, %s)",
                     (account, account+'1', Date, 1000))
    mycursor.execute("Insert into amount values(%s,%s,%s)",
                     (account+'1', None, 1000))
    mydb.commit()
    return (True, "Successfully new Account Created with account number - "+account+"\nFirst Transaction id is " + account+'1')

def account_details(receiver):
    mycursor.execute("Select account, name, email, Balance, DOC from user where account = %s", (receiver,))
    print(from_db_cursor(mycursor))

def check_balance(account):
    mycursor.execute("select balance from user where account = %s", (account,))
    for i in mycursor:
        for j in i:
            return str(j)

def account_number(name):
    mycursor.execute('select account, name from user where name like %s', ('%'+name+'%',))
    return mycursor.fetchall()

def transid(account):
    mycursor.execute("select transid from user where account = %s", (account,))
    for i in mycursor:
        return (account + str(int(i[0][16:])+1))

def trans(amount, mode, account, receiver='Self'):
    if(mode == 1):
        if(int(check_balance(account))-1000 >= int(amount)):
            if(amount < 1):
                return "Please Enter Valid Amount"
            mycursor.execute("Select account, name, email from user where account = %s", (receiver,))
            print(from_db_cursor(mycursor))
            a = input('Press Y if the above details about the receiver are correct\n').lower()
            if(a == 'y'):
                tid = transid(account)
                mycursor.execute("insert into trans values(%s,%s,%s,%s,%s)", (
                    account, receiver, tid, date.today().strftime('%Y/%m/%d'), amount))
                mydb.commit()
                mycursor.execute(query2, (tid, int(check_balance(
                    str(account))) - int(amount), int(check_balance(str(receiver))) + int(amount)))
                mydb.commit()
                mycursor.execute("Update user set balance = balance - %s, transid = %s where account = %s", (int(amount), tid, account))
                mydb.commit()
                mycursor.execute("Update user set balance = balance + %s where account = %s", (int(amount), receiver))
                mycursor.execute(query1, (tid, account))
                mydb.commit()
                return f"{amount} Rs has been transferred from {account} to {receiver} with transaction id {tid}"
            return "Transaction is Aborted"
        return "Insufficient Balance"

    if(mode == 2):
        tid = transid(account)
        if(int(check_balance(str(account)))-1000 >= int(amount)):
            mycursor.execute("insert into trans values(%s,'self',%s,%s,%s)",
                             (account, tid, date.today().strftime('%Y/%m/%d'), amount))
            mydb.commit()
            mycursor.execute(query2,(tid, int(check_balance(account))-int(amount), None))
            mydb.commit()
            mycursor.execute(
                "update user set balance = balance - %s, transid = %s where account = %s", (int(amount), tid, account))
            mydb.commit()
            mycursor.execute(query1, (tid, account))
            mydb.commit()
            return f"{amount} Rs has been withdrawn from {account} with transaction id = {tid}"
        return "Insufficient Balance"

    if(mode == 3):
        tid = str(int(transid(account))+1)
        mycursor.execute("insert into trans values('self', %s, %s, %s,%s)",
                         (account, tid, date.today().strftime('%Y/%m/%d'), amount))
        mydb.commit()
        mycursor.execute(query2,(tid, None, int(check_balance(str(account)))+int(amount)))
        mydb.commit()
        mycursor.execute("update user set balance = %s where account = %s", (int(check_balance(account))+int(amount), account))
        mydb.commit()
        mycursor.execute("update user set transid = %s where account = %s", (tid, account))
        mydb.commit()
        return f'{amount} rs has been credited to {account} with transaction id = {tid}'

    if(mode == 4):
        tid = str(int(transid(account))+1)
        mycursor.execute("insert into trans values(%s,'self',%s,%s,%s)", (account,
                                                                          tid, date.today().strftime('%Y/%m/%d'), int(check_balance(str(account)))))
        mydb.commit()
        mycursor.execute(
            query2, (tid, 0, None))
        mydb.commit()
        mycursor.execute(query3, (account,))
        mydb.commit()
        mycursor.execute(
            "update user set balance = balance +%s, transid = %s where account = %s", (amount, tid, receiver))
        mydb.commit()
        return str(amount) + " Rs has been withdrawn from " + account + " with transid "+tid+" and Account Has been Closed"

def istransid(account, transid):
    mycursor.execute(
        "Select transid from trans where sender = %s or beneficiary = %s", (account, account))
    for i in mycursor.fetchall():
        if i[0] == transid:
            return True
    return False

def history(account):
    a = input("Enter \n1. For only Transid Searched Transaction \n2. For Transaction between Specific Date Range \n3. For Transaction Made on a day\nElse press any key to main menu\n")
    if(a in '1 2 3'):
        a = int(a)
        if(a == 1):
            transid = input("Enter transid\n")
            if(istransid(account, transid)):
                mycursor.execute( query4, (transid, account))
                if(mycursor.rowcount != 0):
                    mycursor.execute(query4, (transid, account))
                    print(from_db_cursor(mycursor))
                mycursor1.execute(
                    "select transid, sender, beneficiary, date, Beneficiary_amount from trans natural join amount where trans.transid = %s and beneficiary = %s", (transid, account))
                if(mycursor1.rowcount != 0):
                    mycursor.execute(query4, (transid, account))
                    print(from_db_cursor(mycursor1))
                return(True,)
            return(False, "Incorrect transaction Id Provided")
        if(a == 2):
            b = date_input()
            if(b[0] is True):
                print('Enter Second Date')
                c = date_input()
                if(c[0]):
                    mycursor.execute(query5, (str(account), b[1], c[1]))
                    mycursor1.execute(query6, (b[1], c[1], account))
                    if(mycursor.rowcount == 0 and mycursor1.rowcount == 0):
                        print("No record Founded")
                    else:
                        mycursor.execute(query5, (str(account), b[1], c[1]))
                        mycursor1.execute( query6, (b[1], c[1], account))
                        if(mycursor.rowcount != 0):
                            mycursor.execute(query5, (str(account), b[1], c[1]))
                            print(from_db_cursor(mycursor))
                        if(mycursor1.rowcount != 0):
                            mycursor1.execute(query6, (b[1], c[1], account))
                            print(from_db_cursor(mycursor1))
                    return (True,)
                return (False, c[1])
            return (False, b[1])
        b = date_input()
        if(b[0] is True):
            k = 0
            mycursor.execute(
                "select transid, sender, beneficiary, date, sender_amount from trans natural join amount where Date = %s and sender = %s", (b[1], account))
            if(mycursor.rowcount != 0):
                mycursor.execute(
                "select transid, sender, beneficiary, date, sender_amount from trans natural join amount where Date = %s and sender = %s", (b[1], account))
                print(from_db_cursor(mycursor))
                k+=1
            mycursor.execute(query7, (b[1], account))
            if(mycursor.rowcount != 0):
                mycursor.execute(query7, (b[1], account))
                print(from_db_cursor(mycursor))
                k+=1
            if(k==0):
                print("No Record Available\n")
            return (True,)
        return (False, b[1])
    return(False, "\n")

def close_account(account):
    k = input("Are you Sure to delete Account, Press Y to continue, Else press any key to exit\n").lower()
    if(k != 'y'):
        return "Operation Cancelled\n"
    balance = check_balance(str(account))
    trans(check_balance(account), 4, account)
    mycursor.execute(query3, (account,))
    mydb.commit()
    return f"Account deleted succesfully and Rs {balance} will be returned to you as cash\n"

def select_account(name):
    k, j = 0, []
    mycursor.execute('select name, account from user where name like %s', (name,))
    table = PrettyTable()
    table.field_names = ['Sr. No.', 'Name', 'Account Number']
    for i in mycursor.fetchall():
        j.append([k+1,i[0], i[1]])
        k += 1
    if(k == 0):
        return (False, "Account Does't Exsist\n")
    table.add_rows(j)
    print(table)
    while(True):
        a = input("\nEnter Serial number\n")
        if(a.isdigit()):
            a = int(a)
            if(a > 0 and a < k+1):
                return (True, j[int(a)-1][2])
            print("Please Select from given\n")
        else:
            print("Please enter digits only\n")