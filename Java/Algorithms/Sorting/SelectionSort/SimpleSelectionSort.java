class SimpleSelectionSort {
        public void selectionSort() {
        for(int i=0;i<nElems-1;i++){
            int minIndex=i;
            for(int j=i+1;j<nElems;j++){
                if(a[minIndex]>a[j]){
                    minIndex=j;
                }
            }
            swap(i,minIndex);
        }
        System.out.print("Selection Sorting ->");
        display();
        }
}