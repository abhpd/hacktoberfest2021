electricity_units = int(input("Enter the number of units: "))
if electricity_units<50:
    charge = 2.60
    surcharge = 25
    total_bill_amount = (electricity_units*charge)+surcharge
elif electricity_units<=100:
    charge = 3.25
    surcharge = 35
    total_bill_amount = (50*2.60)+25+((electricity_units-50)*charge)+surcharge
elif electricity_units<=200:
    charge = 5.25
    surcharge = 45
    total_bill_amount = (50*2.60)+25+((100-50)*3.25)+35+((electricity_units-100)*charge)+surcharge
elif electricity_units>200:
    charge = 7.50
    surcharge = 100
    total_bill_amount = (50*2.60)+25+((100-50)*3.25)+35+((200-100)*5.25)+45+((electricity_units-200)*charge)+surcharge
print("The total electricity bill:-",total_bill_amount)
