// BINARY SEARCH

int main(){
    int a[10],n,i,beg,end,mid,item;
    printf("\nEnter the no of array elements: ");
    scanf("%d",&n);
    printf("\nENter the array elemnts: ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nEnter the item to be searched: ");
    scanf("%d",&item);
    beg=0;
    end=n-1;
    mid=(beg+end)/2;
    while(beg<=end){
        if(item<a[mid])
        end=mid-1;
        else
        beg=mid+1;
        mid=(beg+end)/2;
    }
    if(a[mid]==item)
    printf("\nItem present at the location: %d",mid+1);
    else
    printf("\nItem doesnot exist");
}