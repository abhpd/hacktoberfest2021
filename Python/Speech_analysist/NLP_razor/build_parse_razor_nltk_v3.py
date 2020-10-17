import textrazor
from nltk import Tree

marker = ["xcomp", "advcl", "conj"]

def mark(node, marked_num):
    global max_position
    mark_array[node.position] = marked_num
    token_array[node.position] = node.token
    max_position=max(max_position, node.position)
    for child in node.children:
        if (child.relation_to_parent == "punct"): continue
        if (child.relation_to_parent == "cc"): continue
        if (child.relation_to_parent in marker):
            mark(child, marked_num + 1)        
        else:
            mark(child, marked_num)

def to_phrase():
    for x in range(max_position + 1):
        if mark_array[x] == 0: continue
        phrase[mark_array[x] - 1] += str(" " + token_array[x])
        # print(mark_array[x] - 1, token_array[x])

    for x in phrase:
        if x: print(x)

textrazor.api_key="d64cc7e640600e8e2305304d8e79e6b945b575825a72ce4b853da187"
client = textrazor.TextRazor(extractors=["dependency-trees"])
# text_input="open the browser and search Google for freedom"
# text_input="Bell, based in Los Angeles, makes and distributes electronic, computer and building products"

while (1):
    mark_array = [0] * 70
    token_array = ["" for i in range(70)]
    phrase = ["" for i in range(10)]
    max_position = 0
    text_input = input("text=")
    response = client.analyze(text_input)
    sent = response.sentences()
    mark(sent[0].root_word, 1)
    to_phrase()