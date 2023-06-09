import Employee_end as Ee

query1 = '\nPress y to do again else press any key to main menu\n'
query2 = "\nEnter Amount in Rupees to transfer\n"
query3 = "\nPlease Enter amount in digits only\n"

while(True):
    a = input('''Main Menu\n
        1 - New User
        2 - User Details
        3 - Transaction
        4 - Transaction History
        5 - Close Account
        Else press any key to exit\n''')
    if a not in "1 2 3 4 5":
        break
    a = int(a)
    if(a == 1):
        while(True):
            b = input("\nEnter Name\n")
            c = input("\nEnter Phone number\n")
            d = input("\nEnter Email Id\n")
            if (b == str()):
                print("\nKindly Enter Name\n")
                e = input(query1).lower()
                if(e != 'y'):
                    break
                continue
            if(d == str()):
                print("\nKindly Enter Email\n")
                e = input(query1).lower()
                if(e != 'y'):
                    break
                continue
            if not(c.isdigit() or len(c) != 10):
                print("\nKindly enter digits only and/or enter 10 digits only\n")
                e = input(query1).lower()
                if(e != 'y'):
                    break
                continue
            e = input(
                f'\nPress Y to create account with details Name = {b}, Phone = {c},Email = {d}, Else press any key to main menu\n').lower()
            if(e != 'y'):
                break
            f = Ee.new_user(b, c, d)
            print(f[1])
            e = input(query1).lower()
            if(e != 'y'):
                break

    if(a == 2):
        z = 0
        while(z == 0):
            b = '%'+input("\nEnter name of account Holder\n")+'%'
            c = Ee.select_account(b)
            if(c[0]):
                Ee.account_details(c[1])
                e = input(query1).lower()
                if(e != 'y'):
                    z = 1
            else:
                print(c[1])
                e = input(query1).lower()
                if(e != 'y'):
                    z = 1

    if(a == 3):
        while(True):
            b = input(
                "\nEnter \n1. For Bank to Bank Transaction \n2. For Cash Withdrawal \n3. For Cash Deposit\nElse any key to Main Menu\n")
            if not(b.isdigit()):
                break
            if(int(b) not in range(1, 4)):
                break
            if(int(b) == 1):
                c = input(query2)
                if (not(c.isdigit()) or c == ""):
                    print(query3)
                    if(input(query1).lower() != 'y'):
                        break
                    continue
                c = int(c)
                d = '%'+input("\nEnter name of Sender\n")+'%'
                m = Ee.select_account(d)
                if(m[0]):
                    e = '%'+input("\nEnter name of Beneficiary\n")+'%'
                    n = Ee.select_account(e)
                    if(n[0]):
                        f = Ee.trans(c, 1, m[1], n[1])
                        print(f)
                        e = input(query1).lower()
                        if(e != 'y'):
                            break
                    else:
                        print(n[1])
                        e = input(query1).lower()
                        if(e != 'y'):
                            break
                else:
                    print(m[1])
                    e = input(query1).lower()
                    if(e != 'y'):
                        break

            elif(int(b) == 2):
                c = input(query2)
                if not(c.isdigit()):
                    print(query3)
                    e = input(query1).lower()
                    if(e != 'y'):
                        break
                c = int(c)
                d = '%'+input("\nEnter name of Customer\n")+'%'
                e = Ee.select_account(d)
                if(e[0]):
                    f = Ee.trans(c, 2, e[1])
                    print(f)
                    e = input(query1).lower()
                    if(e != 'y'):
                        break
                else:
                    print(e[1])
                    e = input(query1).lower()
                    if(e != 'y'):
                        break
            elif(int(b) == 3):
                c = input(query2)
                if (not(c.isdigit()) or c == ""):
                    print(query3)
                    e = input(query1).lower()
                    if(e != 'y'):
                        break
                c = int(c)
                d = '%'+input("\nEnter name of Beneficiary\n")+'%'
                e = Ee.select_account(d)
                if(e[0]):
                    f = Ee.trans(c, 3, e[1])
                    print(f)
                    e = input(query1).lower()
                    if(e != 'y'):
                        break
                else:
                    print(e[1])
                    e = input(query1).lower()
                    if(e != 'y'):
                        break

    if(a == 4):
        while(True):
            b = '%'+input("\nEnter name of Account Holder\n")+'%'
            c = Ee.select_account(b)
            if(c[0]):
                d = Ee.history(c[1])
                if not(d[0]):
                    if(d[1] == '\n'):
                        break
                    print(d[1])
                    e = input(query1).lower()
                    if(e != 'y'):
                        break
                e = input(query1).lower()
                if(e != 'y'):
                    break
                continue
            print(c[1])
            e = input(query1).lower()
            if(e != 'y'):
                break

    elif(a == 5):
        while(True):
            b = '%'+input('\nEnter Name of Customer\n')+'%'
            c = Ee.select_account(b)
            if(c[0]):
                print(Ee.close_account(c[1]))
                e = input(query1).lower()
                if(e != 'y'):
                    break
            else:
                print(c[1])
                e = input(query1).lower()
                if(e != 'y'):
                    break