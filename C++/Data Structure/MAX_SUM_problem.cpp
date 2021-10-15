#include <iostream>
using namespace std;

// definig all the variables to global scope;
int A[1000], K, N, T;

// K= atmost element no.
// N= no. of elemts wanna insert in array
// T= no. of tests
// insert function to insert elemets of the array

void insert(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
}

// calc function: the algorithm used to find sum of atmost K element(s)
int calc(int n, int k, int arr[])
{
   int sum = 0, m = 0, i, j, temp;
   //  'for' loop is used for sorting the array in descending order
   for (int i = 0; i < n; ++i)
   {
      for (j = i + 1; j < n; ++j)
      {
         if (arr[i] < arr[j])
         {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }
   for (i = 0; i < k; i++)
   {
      sum = sum + arr[i];
   }

   // loop to add repeated elements (the remaining elements after at least 1 atmost of k)
   for (i = k - 1; i < n; k++)
   {
      int count = 0;
      for (j = k; j < n; j++)
         if (arr[i] == arr[j])
         {
            count = count + arr[i];
            sum = sum + count;
         }
      break; // to stop loop saving time
   }

   return sum;
}

// main function starts from here
int main()
{
   int A[1000], t = 1;
   cout << "enter tests ";
   cin >> T;
   do
   {
      cin >> N >> K;
      insert(A, N);
      cout << calc(N, K, A);
      ++t;
      cout << endl;
   } while (t == T);
   return 0;
}
