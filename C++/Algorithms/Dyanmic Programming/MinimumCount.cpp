int minCount(int n){
    if(n <= 3){
        return n;
    }
   int *count = new int[n+1];
   count[0] = 0;
   count[1] = 1;
   count[2] = 2;
   count[3] = 3;

   for(int i = 4; i <= n; i++){
       int ans = i;
       for(int j = 1; j <= n/2; j++){
           int k = i - (j * j);

           if(k >= 0){
               ans = min(ans,count[k] + 1);
           }
       }
       count[i] = ans;
   }
   return count[n];
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
