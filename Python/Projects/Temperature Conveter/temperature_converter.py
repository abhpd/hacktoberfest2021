def Cel():
    celsius = float(input("Enter the temperature in Celsius "))  # It will take user input
    fahrenheit :float = (celsius * 9 / 5) + 32  # calculation part
    print("Value in Fahrenheit ", fahrenheit)


def Far():
    fahrenheit = float(input("Enter the temperature in Fahrenheit "))  # It will take user input
    celsius :float = (fahrenheit - 32) * 5 / 9  # calculation part
    print(" Value in   Celsius", celsius)

def condition():
        cont=int(input((" Enter 1 to continue or else to exit ")))
        if cont ==1:
            main()
            condition()

def main():
    print(" To convert Temperatures")
    choice=int(input("Enter 1 to convert Celsius to Fahrenheit 0r Enter 2 for vice versa  "))

    if choice ==1 :
        Cel()

    elif choice ==2 :
        Far()
    else :
        print(' Wrong choice ')
    return

main()
condition()

