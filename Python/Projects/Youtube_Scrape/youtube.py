from bs4 import BeautifulSoup  #Importing the Beautiful Soup Library
import requests				   #Importing the requests library
import time					   #Importing the time library
import csv					   #Importing the csv module
import re

response = requests.get('https://www.youtube.com/results?search_query=vicky+kaushal')
soup = BeautifulSoup(response.text, 'lxml')

links = soup.find_all('a')
link, final_list = list() , list()

for i in links:
	if re.findall('watch',i.get('href')):
		link.append('https://www.youtube.com' + i.get('href'))


for i in link:
	if i not in final_list:
		final_list.append(i)

for i in final_list:
	print(i)
