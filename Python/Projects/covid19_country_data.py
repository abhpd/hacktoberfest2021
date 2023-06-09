#guptadev21
#https://github.com/guptadev21

from covid19dh import covid19
import datetime

a, data = covid19(raw = True, verbose = False)

country = input("For which country you want the data: \n")

a, data = covid19(country, cache = False, verbose = False, start = datetime.date(2021,10,1))


#print(data.columns)
print(data.iso_alpha_3)
