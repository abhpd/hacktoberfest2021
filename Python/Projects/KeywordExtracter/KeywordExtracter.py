# Keywords play an important role when reading a long text to understand the subject and context of the text.
# There are so many Python libraries for the task of extracting keywords, the best ones are spaCy, Rake-Nltk, YAKE.
# In this program, I have used the Rake-NLTK to extract keyword from textfile.
# RAKE stands for Rapid Automatic Keyword Extraction.

from rake_nltk import Rake
rake_nltk_var = Rake()

f = open(r'C:\Users\Arvind\Desktop\Text.txt', 'r')

rake_nltk_var.extract_keywords_from_sentences(f)
keyword_extracted = rake_nltk_var.get_ranked_phrases()
print(keyword_extracted)
