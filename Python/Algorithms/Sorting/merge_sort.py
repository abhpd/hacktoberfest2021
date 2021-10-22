def merge(left, right):
    sorted_list = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_list.append(left[i])
            i += 1
        else:
            sorted_list.append(right[j])
            j += 1

    sorted_list += left[i:]
    sorted_list += right[j:]
    return sorted_list


def merge_sort(input_list):
    if len(input_list) == 1:
        return input_list
    middle = len(input_list) / 2
    left_list = merge_sort(input_list[:middle])
    right_list = merge_sort(input_list[middle:])
    return merge(left_list, right_list)


if __name__ == "__main__":

    list_to_sort = [10, 3, 16, 5, 8]  # sample test case
    print(merge_sort(list_to_sort))
