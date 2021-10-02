import requests
from bs4 import BeautifulSoup

companies = {}
data = ['company name', 'repetation', 'years it appeared in']
mins = [len(x) for x in data]
sprt = ' | '
spc = ' '

years = [str(i) for i in range(2017, 2021)]

for year in years:

    url = 'https://summerofcode.withgoogle.com/archive/{}/organizations/'.format(year)

    page = requests.get(url)
    soup = BeautifulSoup(page.content, features='html.parser')
    res = soup.find_all('li', class_='organization-card__container')

    for tag in res:
        company = tag.text.strip().split('\n', 1)[0]
        if (companies.get(company)):
            companies[company].append(year)
            if len(companies[company])*6 - 2 > mins[2]:
                mins[2] = len(companies[company])*6 - 2
        else:
            companies[company] = [year]
            if len(company) > mins[0]:
                mins[0] = len(company)

companies = sorted(companies.items(), key=lambda x: len(x[1]), reverse=True)

file = open('companies.txt', 'w+')
file.write(
    sprt + data[0] + spc*(mins[0] - len(data[0])) + sprt
    + data[1] + spc*(mins[1] - len(data[1])) + sprt
    + data[2] + spc*(mins[2] - len(data[2])) + sprt + '\n'
)
file.write('-'*(mins[0] + mins[1] + mins[2] + 4*3) + '\n')

for company in companies:
    stryear = ''
    num = 0

    for year in company[1]:
        num+=1
        stryear += str(year)+', '
    stryear = stryear.rstrip(', ')
    file.write(
        sprt + company[0] + spc*(mins[0] - len(company[0])) + sprt
        + str(num) + spc*(mins[1] - len(str(num))) + sprt
        + stryear + spc*(mins[2] - len(stryear)) + sprt
        + '\n'
    )
file.close()