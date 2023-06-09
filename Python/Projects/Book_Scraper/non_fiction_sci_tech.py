# Imports
from bs4 import BeautifulSoup as bs
import requests

# This functions returns a an empty list if no book found 
# Returns a "error" if site does some changes in it code or getting error in response
def run(url):
	# Empty Book list
	Books = []
	# Getting response after providing a request
	try:
		response = requests.get(url)
		bs_html = bs(response.text , "html.parser")
	except:
		return "error"
	# Getting the table where books are stored
	table = bs_html.find_all("table")
	table = table[2]
	# Getting all rows of the table
	table_rows = table.find_all("tr")
	# Calculating the length of books
	a = len(table_rows)
	if a<=1:
		return []
	# Iterating Through all table rows except 0th row
	for i in range(1,a):
		# temporary book list for current book
		book = []
		# Getting into the table row
		table_row = table_rows[i]
		# Getting all <td> tags
		table_data = table_row.find_all("td")
		# extracting author name from the row
		author_name = table_data[1].get_text().strip()
		# extracting book name from the row
		book_name = table_data[2].get_text().strip()
		# extracting name of publisher
		publisher = table_data[3].get_text().strip()
		# extracting year the book was published
		year = table_data[4].get_text().strip()
		# extracting number of pages in the book
		pages = table_data[5].get_text().strip()
		# extracting the language the book is written in
		language = table_data[6].get_text().strip()
		# extracting the size of book
		size = table_data[7].get_text().strip()
		# extracting the book extension like - pdf,epub,txt ect.
		extension = table_data[8].get_text().strip()
		# getting links two mirror links
		link1 = table_data[9].find("a").get("href")
		link2 = table_data[10].find("a").get("href")
		# Appending all data into a list
		book.extend([author_name,book_name,publisher,year,pages,language,size,extension,[link1,link2]])
		# appending the current book in the book list
		Books.append(book)
	return Books

if __name__ == '__main__':
	print(run("https://libgen.is/search.php?req=hello+world&open=0&res=100&view=simple&phrase=1&column=def"))