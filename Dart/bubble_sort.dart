class Bubble {
  List<int> sort(List<int> list) {
    final int length = list.length - 1;

    for (int i = 0; i < length; i++) {
      for (int j = 0; j < length - i; j++) {
        if (list[j] > list[j + 1]) {
          int aux = list[j];
          list[j] = list[j + 1];
          list[j + 1] = aux;
        }
      }
    }

    return list;
  }
}

void main() {
  //test algorithm with print, so sorry

  List<int> unsorted = [1, 3, 5, 2, 4, 6, 0];
  List<int> sorted = Bubble().sort(unsorted);

  print(sorted.toString());
}
