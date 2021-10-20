function getDigit(num, pos) {
    num = num.toString()
    return Number(num[(num.length - 1) - pos]) || 0
}

function digitCount(num) {
    if (num === 0) return 1
    return Math.floor(Math.log10(num)+1)
}

function mostDigitCount(arr) {
    let maxDigit = 0
    arr.map((item) => {
        let count = Math.floor(Math.log10(item) + 1)
        if (count > maxDigit) {
            maxDigit = count
        }
    })
    return maxDigit
}
radixSort([23,43,5566,123,8797,445321,1,3,15])
function radixSort(arr) {
    let maxDigitCount = mostDigitCount(arr)
    for (let i = 0; i < maxDigitCount; i++) {
        let digitBuckets = Array.from({length: 10}, () => [])
        for (let j = 0; j < arr.length; j++) {
            let digit = getDigit(arr[j], i)
            digitBuckets[digit].push(arr[j]) 
        }
        arr = [].concat(...digitBuckets)
    }
    return arr
}
