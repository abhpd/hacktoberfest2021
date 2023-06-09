#include<bits/stdc++.h>
using namespace std;

struct Array{
    int  A[20];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<"  ";
    cout<<endl;
}

void append(struct Array *arr,int x){
    arr->A[arr->length] = x;
    arr->length++;
}

void insert(struct Array *arr,int index,int x){
    for(int i=arr->length;i>index;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=x;
    arr->length++;
}

int Delete(struct Array *arr,int index){
    int x=arr->A[index];
    if(index > 0 && index < arr->length){
        for(int i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array arr,int key){
    for(int i=0;i<arr.length;i++){
        if(key==arr.A[i]){
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key){
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int recursiveBinarySearch(struct Array arr,int l,int h,int key){
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            return recursiveBinarySearch(arr,l,mid-1,key);
        }
        else{
            return recursiveBinarySearch(arr,mid+1,h,key);
        }
    }
    return -1;
}

int get(struct Array arr,int index){
    if(index>=0 && index < arr.length)
        return arr.A[index];
}

void Set(struct Array *arr,int index,int x){
    if(index >=0 && index< arr->length)
        arr->A[index]=x;
}

int Max(struct Array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(max<arr.A[i])
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(min>arr.A[i])
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr){
    int sum =0;
    for(int i=0;i<arr.length;i++){
        sum = sum + arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

void ReverseUsingAuxilary(struct Array *arr){
    int B[arr->length];
    for(int i=arr->length-1,j=0;i>=0;i--,j++)
        B[j] = arr->A[i];
    for(int i=0;i<arr->length;i++)
        arr->A[i] = B[i];
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Reverse(struct Array *arr){
    for(int i=0,j=arr->length-1;i<j;i++,j--)
        swap(arr->A[i],arr->A[j]);
}

void Lshift(struct Array *arr){
    for(int i=0;i<arr->length-1;i++)
        arr->A[i] = arr->A[i+1];
    arr->A[arr->length-1] = 0;
}

void Rshift(struct Array *arr){
    for(int i=arr->length-1;i>0;i--)
        arr->A[i] = arr->A[i-1];
    arr->A[0] = 0;
}

void RotateLeft(struct Array *arr){
    int temp = arr->A[0];
    for(int i=0;i<arr->length-1;i++)
        arr->A[i] = arr->A[i+1];
    arr->A[arr->length-1] = temp;
}

void RotateRight(struct Array *arr){
    int temp = arr->A[arr->length-1];
    for(int i=arr->length-1;i>0;i--)
        arr->A[i]=arr->A[i-1];
    arr->A[0] = temp;
}

//check if all numbers are sorted or not

bool isSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
            return false;
    }
    return true;
}

//Inserts a number at its correct position in a sorted array

void insert_in_sorted_position(struct Array *arr,int x){
    int i = arr->length-1;
    while(x<arr->A[i] && i>=0){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

//Put all -ve numbers on one side and +ve numbers on opposite side

void Rearrange(struct Array *arr){
    int i =0,j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0) 
            i++;
        while(arr->A[j]>0)
            j--;
        if(i<j)
            swap(arr->A[i],arr->A[j]);
    }
}

//sorts the elements of the array using Insertion Sort Algorithm

void Sort(struct Array *arr){
    int key,i;
    for(int j=1;j<arr->length;j++){
        key = arr->A[j];
        i=j-1;
        while(i >= 0 && arr->A[i] > key){
            arr->A[i+1] = arr->A[i];
            i--;
        }
        arr->A[i+1]=key;
    }
}

struct Array *Merge(struct Array *arr1,struct Array *arr2){
    struct Array *arr3 = new struct Array;
    int i=0,j=0,k=0;

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else    
            arr3->A[k++] = arr2->A[j++];
    }
    while(i<arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while(j<arr2->length)
        arr3->A[k++] = arr2->A[j++];
    arr3->length = arr1->length + arr2->length;

    return arr3;    
}

//Prints Multiple missing elements in a sequence if array IS SORTED and has only +ve elements

void Missing_elements(struct Array arr){

    int diff = arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i] - i != diff){
            while(diff< arr.A[i]-i){
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
    cout<<endl;
}

//Prints Multiple missing elements in a sequence even if array is not sorted and skips -ve numbers and prints +ve numbers

void Missing_elements_using_Hash(struct Array arr){
    
    int H[Max(arr)+1];
    int l = Min(arr);
    int h =Max(arr);
    memset(H,0,sizeof(H));
    for(int i=0;i<arr.length;i++)
        H[arr.A[i]]++;
    for(int i=l;i<=h;i++){
        if(H[i]==0)
            cout<<i<<" ";
    }
    cout<<endl;
}

// prints max and min of the array in just one scan

void min_max_single_scan(struct Array arr){
    int mn  = arr.A[0];
    int mx = arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>mx)
            mx=arr.A[i];
        else if(arr.A[i]<mn)
            mn = arr.A[i];
    }
    cout<<"MAX: "<<mx<<" MIN: "<<mn<<endl; 
}

// give pair of elements from the array  with given sum k

void pair_with_sum(struct Array arr,int k){
    int i=0;
    int j= arr.length-1;
    while(i<j){
        if(arr.A[i]+ arr.A[j]==k){
            cout<<arr.A[i]<<" "<<arr.A[j]<<endl;
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] < k)
            i++;
        else
            j--;
    }
}

void Duplicate_using_hash(struct Array arr){
    int H[Max(arr)];
    memset(H,0,sizeof(H));
    int l =Min(arr);
    int h= Max(arr);
    for(int i=0;i<arr.length;i++)
        H[arr.A[i]]++;
    for(int i=l;i<=h;i++){
        if(H[i]>1)
            printf("%d is repeating %d times\n",i,H[i]);
    }
    
}

struct Array *Union(struct Array a,struct Array b){
    struct Array *c = new struct Array;
    int i=0,j=0,k=0;

    while(i<a.length && j<b.length){
        if(a.A[i] < b.A[j])
            c->A[k++] = a.A[i++];
        else if(a.A[i] > b.A[j])
            c->A[k++] = b.A[j++];
        else{
            c->A[k++]=a.A[i++];
            j++;
        }
    }
    while(i<a.length)
        c->A[k++] = a.A[i++];
    while(j<b.length)
        c->A[k++] = b.A[j++];
    
    c->length = k;
    return c;
}

struct Array *Intersection(struct Array a,struct Array b){
    struct Array *c = new struct Array;
    int i=0,j=0,k=0;
    while(i<a.length && j<b.length){
        if(a.A[i] < b.A[j])
            i++;
        else if(a.A[i]>b.A[j])
            j++;
        else{
            c->A[k++] = a.A[i++];
            j++;
        }
    }
    c->length = k;
    return c;
}

struct Array *Difference(struct Array a,struct Array b){
    struct Array *c =new struct Array;
    int i=0,j=0,k=0;
    while(i<a.length && j<b.length){
        if(a.A[i] < b.A[j])
            c->A[k++] = a.A[i++];
        else if(a.A[i] > b.A[j])
            j++;
        else{
            i++;
            j++;
        }
    }
    while(i<a.length)
        c->A[k++] = a.A[i++];
    c->length = k;
    return c;
}
void isMember(struct Array arr,int x){
    int a = BinarySearch(arr,x);
    if(a==-1)
        cout<<x<<" is Not a Member of Array"<<endl;
    else
        printf("Yes! %d is member of the Array\n",x);
}

int main(){
    struct Array arr = {{2,3,4,5,6},10,5};
    struct Array arr1 = {{1,4,7,8,10,12},10,6};
    append(&arr,7);
    insert(&arr,0,1);
    cout<<Delete(&arr,2)<<endl;
    insert(&arr,2,3);
    display(arr);
    cout<<LinearSearch(arr,5)<<endl;
    cout<<BinarySearch(arr,6)<<endl;
    cout<<recursiveBinarySearch(arr,0,arr.length-1,7)<<endl;
    cout<<get(arr,4)<<endl;
    display(arr);
    cout<<Max(arr)<<endl;
    cout<<Min(arr)<<endl;
    cout<<Sum(arr)<<endl;
    cout<<Avg(arr)<<endl;
    ReverseUsingAuxilary(&arr);
    display(arr);
    Reverse(&arr);
    Lshift(&arr);
    display(arr);
    Rshift(&arr);
    display(arr);
    RotateRight(&arr);
    display(arr);
    RotateLeft(&arr);
    Set(&arr,3,4);
    Rearrange(&arr);
    display(arr);
    cout<<isSorted(arr)<<endl;
    insert_in_sorted_position(&arr,10);
    insert_in_sorted_position(&arr,8);
    display(arr);
    Sort(&arr);
    display(arr);
    display(arr1);
    struct Array *arr2=Merge(&arr,&arr1);
    display(*arr2);
    Missing_elements(arr1);
    display(arr);
    Missing_elements_using_Hash(arr);
    min_max_single_scan(arr);
    pair_with_sum(arr,13);
    Duplicate_using_hash(*arr2);
    struct Array *uni = Union(arr,arr1);
    display(arr);
    display(arr1);
    struct Array *a = Intersection(arr,arr1);
    struct Array *b = Difference(arr,arr1);
    display(*uni);
    display(*a);
    display(*b);
    isMember(arr,14);
    isMember(arr,10);
    return 0;
}
