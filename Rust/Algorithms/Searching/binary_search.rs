fn main() {
    let v = vec![2, 5, 6, 7, 8, 9, 12, 45, 65, 66, 85];
    let index = binary_search(&v, 100); 
    if index != -1 {
        println!("Element is found at index {}", index);
    } else {
        println!("Element not found in the vector");
    }
}

// Recursive Binary Search
fn binary_search_rec(vector: &Vec<i32>, l: usize, r: usize, val: i32) -> i32 {
    if l >= r {
        return -1
    }

    let mid = (l + r) / 2;
    if vector[mid] == val {
        return mid as i32
    }

    if vector[mid] > val {
        return binary_search_rec(vector, l, mid-1, val)
    } else {
        return binary_search_rec(vector, mid+1, r, val)
    }
}

// Iterative Binary Search
fn binary_search(vector: &Vec<i32>, val: i32) -> i32 {
    let mut l = 0;
    let mut r = vector.len() - 1;

    while l <= r {
        let mid = (l + r) / 2;
        if vector[mid] == val {
            return mid as i32
        }

        if vector[mid] > val {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1
}