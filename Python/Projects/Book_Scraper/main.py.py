# Imports
import non_fiction_sci_tech
import fiction
import scientific_articles

def name_format(name):
    name = name.replace(" ","+")
    return name

# Function for getting Books With all details in a form of list
# Format of list - [author_name,book_name,publisher,year,pages,language,size,extension,[link1,link2]]
# items that will not be available will have a value of "none"
# name - name of the book
# type - type of book you are searching (if not given the default value will be non_fiction_sci_tech)
# type - non_fiction_sci_tech , fiction , scientific_articles
def get_books(name,type="non_fiction_sci_tech"):
    # Url for which the scrape has to be done
    if type=="non_fiction_sci_tech":
        url = f'http://libgen.is/search.php?req={name_format(name)}&lg_topic=libgen&open=0&view=simple&res=100&phrase=1&column=def'
        books = non_fiction_sci_tech.run(url)
        return books
    elif type=="fiction":
        url = f'https://libgen.is/fiction/?q={name_format(name)}'
        books = fiction.run(url)
        return books
    elif type=="scientific_articles":
        url = f'https://libgen.is/scimag/?q={name_format(name)}&page='
        books = scientific_articles.run(url)
        return books
    else:
    	return "Enter a valid parameter"

if __name__ == '__main__':
	print(get_books("hello world"))