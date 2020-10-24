int minCount(int n){
    if(n <= 3){
        return n;
    }
   int *count = new int[n+1];
   count[0] = 0;
   count[1] = 1;
   count[2] = 2;
   count[3] = 3;
// 0 = 0
// 1 = 1 ^ 1
// 2 = 1 ^ 1 + 1 ^ 1
// 3 = 1 ^ 1 + 1 ^ 1 + 1 ^ 1
	

   for(int i = 4; i <= n; i++){
       int ans = i;
	   
	//j <= n/2 is sort of sqrt(n) because squaring of a number greater than n/2 provides a greater number than n. 
	//So in order to work with the qualified numbers we reduced it to n/2 or sqrt(n).
       for(int j = 1; j <= n/2; j++){
           int k = i - (j * j);

           if(k >= 0){
               ans = min(ans,count[k] + 1);
	//Getting the cost of each number, from the previous optimal numbers to reach n. So +1 is added to represent the current number cost.
           }
       }
       count[i] = ans;
	// storing of optimal results for each (i...n) 
   }
	//returing the cost of optimal cost for n for which minimum squares are needed.
   return count[n];
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
