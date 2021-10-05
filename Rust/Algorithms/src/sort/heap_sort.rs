use super::swap;

fn heapify<T: Ord + Copy>(arr: &mut Vec<T>, n: usize, i: usize) {
    let mut largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;
    if left < n && arr[left] > arr[largest] {
        largest = left;
    }
    if right < n && arr[right] > arr[largest] {
        largest = right;
    }
    if largest != i {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

pub fn heap_sort<T: Ord + Copy>(arr: &mut Vec<T>) {
    let n = arr.len();
    for i in (0..=n / 2 - 1).rev() {
        heapify(arr, n, i);
    }
    for i in (0..=n - 1).rev() {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}
