# Date Verification Module
def leap_year(a):
    b = int(a.split('/')[0])
    return bool((b%4 == 0 and b%100 != 0) or b% 400 == 0)

def month_verify(a):
    b = int(a.split('/')[1])
    if(b > 0 and b < 13):
        if( b in [1,3,5,7,8,10,12]):
            return (True,'1')
        if(b in [4,6,9,11]):
            return (True,'2')
        return (True,'3')
    return (False,"Month should only lie between 1 to 12")

def date_verify(a):
    b = int(a.split('/')[2])
    if(month_verify(a)[0]):
        if(b >0 and b < 32):
            c = month_verify(a)[1]
            if(c == '1'):
                return (True,)
            if(c == '2'):
                if(b < 31):
                    return (True,)
                return(False, 'Date in this month must be between 1 to 30')
            if(leap_year(a)):
                if (b < 30):
                    return (True,)
                return (False, 'Date in February of Leap year must be in 1 to 29')
            if(b < 29):
                return (True,)
            return (False, 'Date in February of a Normal year must be in 1 to 28')
        return (False, 'Date on any month must be in 1 to 31')
    return month_verify(a)

def date_input():
        a = input('Enter Year \n')
        a = '0'*(4-len(a))+a
        b = input('Enter Month \n')
        b = '0'*(2 - len(b))+b
        c = input('Enter Date \n')
        c = '0'*(2 - len(c))+c
        if not(a.isdigit() and b.isdigit() and c.isdigit()):
            return (False,"Please Enter digits only\n")
        d = f'{a}/{b}/{c}'
        if(month_verify(d)[0]):
            if(date_verify(d)[0]):
                return(True, d)
            return(False, date_verify(d)[1])
        return(False, month_verify(d)[1])