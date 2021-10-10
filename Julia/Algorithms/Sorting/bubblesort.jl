function bubblesort(array)
    len = length(array)
    if (len <= 1)
        return array
    end
    for i in 1:len, j in 1:len-i 
        if (array[j] > array[j+1])
            array[j], array[j+1] = array[j+1], array[j]
        end
    end
    return array
end
arr = [rand(-100:100) for i in 1:20]
println(arr)
bubblesort(arr)
println(arr)