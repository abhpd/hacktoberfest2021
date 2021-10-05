pub mod sort;

#[cfg(test)]
mod tests {
    use crate::sort::{heap_sort::heap_sort, quick_sort::quick_sort, swap};
    #[test]
    fn test_swap() {
        let mut arr = vec![1, 4, 3, 6];
        swap(&mut arr, 0, 2);
        assert_eq!(arr, [3, 4, 1, 6]);
    }
    #[test]
    fn test_quick_sort() {
        let mut arr = vec![1, 4, 2, 5, 6, 4, 1, 6, 9, 11, 24];
        let mut unsorted_arr = arr.clone();
        arr.sort();
        quick_sort(&mut unsorted_arr);
        assert_eq!(unsorted_arr, arr);
    }
    #[test]
    fn test_heap_sort() {
        let mut arr = vec![1, 4, 2, 5, 6, 4, 1, 6, 9];
        let mut unsorted_arr = arr.clone();
        arr.sort();
        heap_sort(&mut unsorted_arr);
        assert_eq!(unsorted_arr, arr);
    }
}
