function quicksort(array, start=1, stop=length(array))

    left, right = start, stop
    if (right <= left)
        return
    end
    pivot = array[convert(Int,floor((left + right) / 2))]
    
    while left <= right
        while array[left] < pivot
            left += 1
        end
        while array[right] > pivot
            right -= 1
        end
        if left <= right
            array[left], array[right] = array[right], array[left]
            left += 1
            right -= 1
        end
    end
    quicksort(array, start, right)
    quicksort(array, left, stop)
    return array
end
arr = [rand(-1000:1000) for i in 1:200]
println(arr)
quicksort(arr)
println(arr)