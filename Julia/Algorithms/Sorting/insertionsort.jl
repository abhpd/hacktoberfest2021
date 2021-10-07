function insertionsort(array)
    for i in 2:length(array)
        current = array[i]
        j = i - 1 
        while j >= 1 && current < array[j]
            array[j + 1] = array[j]
            j -= 1
        end
        array[j+1] = current
    end
end
arr = [rand(-100:100) for i in 1:20]
println(arr)
insertionsort(arr)
println(arr)