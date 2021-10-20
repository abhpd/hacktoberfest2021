def Quicksort(Sequnace):
    length=len(Sequnace)
    if length<=1:
        return Sequnace
    else:
        pivot=Sequnace.pop()
    item_Greater=[]
    item_Lower=[]

    for item in Sequnace:
        if item>pivot:
            item_Greater.append(item)
        else:
            item_Lower.append(item)
    return Quicksort(item_Lower) + [pivot] + Quicksort(item_Greater)
print(Quicksort([10,8,9,5,7,1]))   