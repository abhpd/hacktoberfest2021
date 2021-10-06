fn main() {
	mut arr := [100, 56, 12, 48, 65, 7]
	len_arr := arr.len

	println('Unsorted array: $arr')

	for i in 0..len_arr {
		for j in 0..len_arr-i-1 {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}

	println('Sorted array: $arr')
}