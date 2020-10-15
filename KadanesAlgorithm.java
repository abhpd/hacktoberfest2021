int kadane(int[] arr,int n){
    int current_sum=0;
    int best_sum=0;
    for(int i=0;i<n;i++){
        current_sum=current_sum+arr[i];
        if(best_sum<current_sum){
            best_sum=current_sum;
        }
        if(current_sum<0){
            current_sum=0;
            
        }
        
    }
    return sum;
}
