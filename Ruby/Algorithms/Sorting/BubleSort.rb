# Bubble sort: A very naive sort that keeps swapping elements until the container is sorted.
# Requirements: Needs to be able to compare elements with <=>, and the [] []= methods should
# be implemented for the container.
# Time Complexity: О(n^2)
# Space Complexity: О(n) total, O(1) auxiliary
# Stable: Yes
# 
# bubble_sort [5, 4, 3, 1, 2] => [1, 2, 3, 4, 5]
def bubble_sort(container)
    loop do
        swapped = false
        (container.size-1).times do |i|
        if (container[i] <=> container[i+1]) == 1
            container[i], container[i+1] = container[i+1], container[i] # Swap
            swapped = true
        end
        end
        break unless swapped
    end
    container
end