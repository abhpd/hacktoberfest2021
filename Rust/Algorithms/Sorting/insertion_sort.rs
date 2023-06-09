fn main() {
    let mut v = Vec::new();
    v.push(3);
    v.push(7);
    v.push(-1);
    v.push(50);
    v.push(1);
    v.push(8);
    insertion_sort(&mut v);
    println!("{:?}", v);
}

fn insertion_sort(v: &mut Vec<i32>) {
    for i in 0..v.len() {
        let mut j = i;
        while j > 0 && v[j] < v[j-1] {
            let temp = v[j];
            v[j] = v[j-1];
            v[j-1] = temp;
            j -= 1;
        }
    }
}