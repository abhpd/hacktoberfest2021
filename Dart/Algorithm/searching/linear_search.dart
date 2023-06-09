int linearSearch<T extends Comparable>(List<T> data, T searchItem) {
  for (var i = 0; i < data.length; i++) {
    if (data[i] == searchItem) return i;
  }
  return -1;
}

void main() {
  final itemIndex = linearSearch([1, 2, 3, 4, 5], 3);
  print('INDEX FOUND OF DATA $itemIndex');
}
