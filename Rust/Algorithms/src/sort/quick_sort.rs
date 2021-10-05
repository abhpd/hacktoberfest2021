use super::swap;

fn partition<T: Ord + Copy>(arr: &mut Vec<T>, start: usize, end: usize) -> usize{
    let pivot = arr[end];
    let mut index = start;
    for i in start..end {
        if arr[i] <= pivot {
            swap(arr, i, index);
            index += 1;
        }
    }
    swap(arr, end, index);
    index
}

fn sort<T: Ord + Copy>(arr: &mut Vec<T>, start: usize, end: usize) {
    if start < end {
        let index = partition(arr, start, end);
        sort(arr, start, index - 1);
        sort(arr, index + 1, end);
    }
}

pub fn quick_sort<T: Ord + Copy>(arr: &mut Vec<T>) {
    sort(arr, 0, arr.len() - 1);
}