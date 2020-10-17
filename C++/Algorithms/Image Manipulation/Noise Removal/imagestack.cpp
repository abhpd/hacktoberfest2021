#include<iostream>
#include<fstream>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
int findMedian(int arr[], int n){
  bubbleSort(arr, n);
  if(n%2==0){
    return (arr[n/2]+ arr[n/2+1])/2;
  }
  else{
    return arr[n/2];
  }
}
int main(int argc, char** argv){
  if(argc<=3){
    cout<<"Too few arguments"<<endl;
    return 0;
  }
  if(argc>11){
    cout<<"Too many arguments"<<endl;
    return 0;
  }
  int noOfImages= argc-2;
  int *** arr= new int**[noOfImages];
  string format;
  int x, y, maxValue;
  for(int i=0; i<noOfImages; i++){
    fstream file;
    file.open(argv[i+1], ios::in);
    if(!file.good()){
      cout<<"File opening error"<<endl;
      return 0;
    }
    string temp;
    file>>format;
    file>>temp;
    x=stoi(temp);
    file>>temp;
    y=stoi(temp);
    file>>temp;
    maxValue=stoi(temp);
    arr[i]= new int*[x];
    for(int j=0; j<x; j++){
      arr[i][j]= new int[y];
    }
    for(int j=0; j<x; j++){
      for(int k=0; k<y; k++){
        if(file.eof()){
          cout<<"Error in file"<<argv[i+1]<<endl;
          return 0;

        }
        else{
          file>>arr[i][j][k];

        }
      }
    }
    file.close();


  }


  int **outputArr= new int*[x];
  for(int i=0; i<x; i++){
    outputArr[i]= new int[y];
  }
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      int * tempArr= new int[noOfImages];
      for(int k=0; k<noOfImages; k++ ){
        tempArr[k]= arr[k][i][j];
      }
      int med= findMedian(tempArr, noOfImages);
      outputArr[i][j]= med;
      delete [] tempArr;
    }
  }
  fstream file;
  file.open(argv[argc-1], ios::out);
  file<<format<<endl<<x<<endl<<y<<endl<<maxValue<<endl;
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      file<<outputArr[i][j]<<" ";
    }
    file<<endl;
  }
  file.close();
  for(int i=0; i<x; i++){
    delete[] outputArr[i];
  }
  delete [] outputArr;

  for(int i=0; i<noOfImages; i++){
    for(int j=0; j<x; j++){
      delete[] arr[i][j];
    }
    delete[] arr[i];
  }
  delete [] arr;



}
