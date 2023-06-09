# Comb sort: A variation on bubble sort that dramatically improves performance.
# Source: http://yagni.com/combsort/
# Requirements: Needs to be able to compare elements with <=>, and the [] []= methods should
# be implemented for the container.
# Time Complexity: О(n^2)
# Space Complexity: О(n) total, O(1) auxiliary
# Stable: Yes
# 
# comb_sort [5, 4, 3, 1, 2] => [1, 2, 3, 4, 5]
def comb_sort(container)
    container
    gap = container.size
    loop do
        gap = gap * 10/13
        gap = 11 if gap == 9 || gap == 10
        gap = 1 if gap < 1
        swapped = false
        (container.size - gap).times do |i|
        if (container[i] <=> container[i + gap]) == 1
            container[i], container[i+gap] = container[i+gap], container[i] # Swap
            swapped = true
        end
        end
        break if !swapped && gap == 1
    end
    container
end