# Imports
from bs4 import BeautifulSoup as bs
import requests

# This functions returns a an empty list if no book found 
# Returns a "error" if site does some changes in it code or getting error in response
def run(url):
	# Empty Book list
	Books = []
	# initialising pages as true
	pages = True
	page = 1
	while pages:
		# formating url
		uri=url+str(page)
		# Getting response after providing a request
		try:
			response = requests.get(uri)
			bs_html = bs(response.text , "html.parser")
		except:
			return "error"
		# Getting the table where books are stored
		table = bs_html.find("table",{"class":"catalog"})
		# Getting into table body
		try:
			table_body = table.find("tbody")
		except: 
			pages = False
			break
		# getting all table rows
		table_rows = table_body.find_all("tr")
		# Calculating the length of books
		a = len(table_rows)
		if a<=1:
			return []
		# Iterating Through all table rows
		for i in range(a):
			# temporary book list for current book
			book = []
			# Getting into the table row
			table_row = table_rows[i]
			# Getting all <td> tags
			table_data = table_row.find_all("td")
			# extracting author name from the row
			author_name = table_data[0].get_text().strip()
			# extracting book name from the row
			book_name = table_data[1].get_text().strip()
			# extracting publisher name from the row
			publisher = table_data[2].get_text().strip()
			# extracting size from the row
			size = table_data[3].get_text().strip()
			# getting links two mirror links
			all_list_items = table_data[4].find_all("li")
			# making an empty list for links
			links = []
			for i in all_list_items:
				a_tag = i.find("a")
				link = a_tag.get("href")
				links.append(link)
			# Appending all data into a list
			book.extend([author_name,book_name,"none","none","none","none",size,"none",links])
			# appending the current book in the book list
			Books.append(book)
		page+=1
	return Books






if __name__ == '__main__':
	print(run("https://libgen.is/scimag/?q=hello+world&page="))