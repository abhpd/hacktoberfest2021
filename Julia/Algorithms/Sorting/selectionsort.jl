function selectionsort(array)
    for i in 1:length(array)
        min = i
        for j in i+1:length(array)
            if(array[j] < array[min])
                min = j
            end
        end
        array[i], array[min] = array[min],array[i]
    end    
end
arr = [rand(-100:100) for i in 1:20]
println(arr)
selectionsort(arr)
println(arr)