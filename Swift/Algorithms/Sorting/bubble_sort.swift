//Performs BubbleSort of an array passed as reference(inout)

func bubbleSort(arr: inout [Int]) {
    for i in stride(from: arr.count - 1, to: 1, by: -1) {
        for j in 0..<i where arr[j] > arr[j + 1] {
            swap(&arr[j], &arr[j + 1])
        }
    }
}
