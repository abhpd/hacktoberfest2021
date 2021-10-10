fn main() {
    let mut v = Vec::new();
    v.push(3);
    v.push(7);
    v.push(-1);
    v.push(50);
    v.push(1);
    v.push(8);
    bubble_sort(&mut v);
    println!("{:?}", v);
}

fn bubble_sort(v: &mut Vec<i32>) {
    for i in 0..v.len() {
        for j in i..v.len() {
            if v[i] > v[j] {
                let temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}
