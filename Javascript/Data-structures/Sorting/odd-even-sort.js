const oddEvenSort = (arr) => {
	const swap = (arr, i, j) => {
		let temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	};

	let sorted = false;
	while (!sorted) {
		sorted = true;
		for (let i = 1; i < arr.length - 1; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr, i, i + 1);
				sorted = false;
			}
		}

		for (i = 0; i < arr.length - 1; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr, i, i + 1);
				sorted = false;
			}
		}
	}
	return arr;
};

console.log(oddEvenSort(['46', '200', '1']));
