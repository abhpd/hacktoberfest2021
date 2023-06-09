menu = """
1 - Pesos Colombianos
2 - Pesos Argentinos
3 - Pesos Mexicanos
Choice an option:
"""
#dollars = dolares

option = int(input(menu))

#block code
if option == 1:
    pesos = input("How many Colombian pesos do you have??")
    pesos = float(pesos)
    value_dolar = 3875
    dolares = pesos / value_dolar
    dolares = round(dolares,2)
    dolares = str(dolares)
    print("You have $" + dolares + " dolares")

elif opcion == 2:
    pesos = input("How many Argentinian pesos do you have?")
    pesos = float(pesos)
    value_dolar = 150
    dolares = pesos / value_dolar
    dolares = round(dolares,2)
    dolares = str(dolares)
    print("You have $" + dolares + " dolares")

elif opcion == 3:
    pesos = input("How many Mexican pesos do you have?")
    pesos = float(pesos)
    value_dolar = 24
    dolares = pesos / value_dolar
    dolares = round(dolares,2)
    dolares = str(dolares)
    print("You have $" + dolares + " dolares")

else:
    print("Please enter a correct option")
