def search(list_data: list, key: int, left: int = 0, right: int = 0) -> int:
    right = right or len(list_data) - 1
    if left > right:
        return -1
    elif list_data[left] == key:
        return left
    elif list_data[right] == key:
        return right
    else:
        return search(list_data, key, left + 1, right - 1)

#print(search([6,3,8,9,2,1],2)) -> 4