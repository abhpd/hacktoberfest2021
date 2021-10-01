'''
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Case 1:
          a ----------- b
start -------------------------- end

Case 2:
                a ----------------------------- b
start -------------------------- end

Case 3:
a ----------------------------- b
            start -------------------------- end

'''


def mergeoverlappingintervals(arr, n):
    answer = []
    arr.sort()
    start = arr[0][0]
    end = arr[0][1]

    for i in range(1, n):
        # Case 1 - Start and End remains same
        if (arr[i][0]>=start and arr[i][1]<=end):
            continue
        # Case 2 - Start remains same but b becomes End
        elif (arr[i][0]>=start and arr[i][1]>=end and arr[i][0]<=end):
            end = arr[i][1]
        # Case 3 - a becomes Start but End remains same
        elif (arr[i][0]<=start and arr[i][1]<=end and arr[i][0]<=end):
            start = arr[i][0]
        else:
            answer.append([start, end])
            start = arr[i][0]
            end = arr[i][1]
    answer.append([start, end])
    return answer