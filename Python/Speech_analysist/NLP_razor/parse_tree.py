import textrazor
from nltk import Tree

def tok_format(tok):
    if tok.relation_to_parent:
    	return "_".join([tok.token, str(tok.position), tok.relation_to_parent])
    else :
    	return tok.token

def to_nltk_tree(node):
    if len(node.children) > 0:
        return Tree(tok_format(node), [to_nltk_tree(child) for child in node.children])
    else:
        return tok_format(node)

textrazor.api_key="d64cc7e640600e8e2305304d8e79e6b945b575825a72ce4b853da187"
client = textrazor.TextRazor(extractors=["dependency-trees"])
# text_input="open the browser and search Google for freedom"
# text_input="Bell, based in Los Angeles, makes and distributes electronic, computer and building products"

while (1):
	text_input = input("text=")
	response=client.analyze(text_input)
	sent=response.sentences()
	[to_nltk_tree(sent[0].root_word).pretty_print()]
