pub mod heap_sort;
pub mod quick_sort;

pub fn swap<T: Copy>(arr: &mut Vec<T>, lhs: usize, rhs: usize) {
    let tmp = arr[lhs];
    arr[lhs] = arr[rhs];
    arr[rhs] = tmp;
}
