# Imports
from bs4 import BeautifulSoup as bs
import requests

# This will seperate the size and extension from the extracted data
def seperate_size_ext(text):
	text = text.replace("/"," ")
	text = text.split()
	return text

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
	table = bs_html.find("table",{"class":"catalog"})
	# Getting into table body
	table_body = table.find("tbody")
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
		book_name = table_data[2].get_text().strip()
		# extracting language of the book
		language = table_data[3].get_text().strip()
		# getting size and extension and seperating them
		sne = table_data[4].get_text().strip()
		extnsize_data = seperate_size_ext(sne)
		# getting size
		size = str(extnsize_data[1])+str(extnsize_data[2])
		# getting extension
		extension = extnsize_data[0]
		# getting links two mirror links
		all_list_items = table_data[5].find_all("li")
		# making an empty list for links
		links = []
		for i in all_list_items:
			a_tag = i.find("a")
			link = a_tag.get("href")
			links.append(link)
		# Appending all data into a list
		book.extend([author_name,book_name,"none","none","none",language,size,extension,links])
		# appending the current book in the book list
		Books.append(book)
	return Books


if __name__ == '__main__':
	print(run("https://libgen.is/fiction/?q=hello+world"))