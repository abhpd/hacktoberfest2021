//Quick Sort using Swift

func quickSort(_ arr: inout [Int], begin: Int, end: Int) {
    if begin < end {
        let partitionInd = partition(&arr, begin: begin, end: end)
        quickSort(&arr, begin: begin, end: partitionInd - 1)
        quickSort(&arr, begin: partitionInd + 1, end: end)
    }
}
func partition(_ arr: inout [Int], begin: Int, end: Int) -> Int {
    let pivot = arr[end]
    var i = begin - 1
    for j in begin..<end {
        if arr[j] <= pivot {
            i += 1
            arr.swapAt(i, j)
        }
    }
    arr.swapAt(i + 1, end)
    return i + 1
}
