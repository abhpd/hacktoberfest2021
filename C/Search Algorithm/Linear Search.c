// LINEAR SEARCH

int main(){
    int a[10],n,i,item;
    printf("\nEnter the no of array elements: ");
    scanf("%d",&n);
    printf("\nEnter the no of array elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nEnter the no to be searched: ");
    scanf("%d",&item);
    for(i=0;i<n;i++){
        if(item==a[i]){
            printf("\nItem found at location: %d",i+1);
            break;
        }
    }    
    if(i==n)
    printf("\nItem does'n exist");
}