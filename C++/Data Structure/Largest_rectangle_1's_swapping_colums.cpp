
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
        // An auxiliary array to store count of consecutive 1's
    // in every column.
	    int hist[r][c];

        // Step 1: Fill the auxiliary array hist[][]
	    for(int i=0;i<c;i++)
	    {
	        // First row in hist[][] is copy of first row in mat[][]
            hist[0][i]= mat[0][i];

            // Fill remaining rows of hist[][]
	        for(int j=1;j<r;j++)
	        {
	            hist[j][i]= (mat[j][i]==0)? 0:hist[j-1][i] +1;
	        }
	    }
        // Step 2: Sort columns of hist[][] in non-increasing order
	    for(int i=0;i<r;i++)
	    {
	        int count[r+1]= {0};
	        for(int j=0;j<c;j++)
	        {
	            count[hist[i][j]]++;
	        }

            // Traverse the count array from right side
	        int col=0;
	        int col_no = 0;
          for (int j = r; j >= 0; j--) {
            if (count[j] > 0) {
                for (int k = 0; k < count[j]; k++) {
                    hist[i][col_no] = j;
                    col_no++;
                }
              }
	        }
	    }

         // Step 3: Traverse the sorted hist[][] to find maximum area
	    int curr_area,max_area=0;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
             // Since values are in decreasing order,
            // The area ending with cell (i, j) can
            // be obtained by multiplying column number
            // with value of hist[i][j]
	            curr_area= (j+1)*hist[i][j];
	            if(curr_area>max_area)
	            {
	                max_area=curr_area;
	            }
	        }
	    }
	    return max_area;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x;
        cin >> r >> c;
        vector<bool> mat[r];
        for (int i = 0; i < r; i++) {
            mat[i].assign(c, false);
            for (int j = 0; j < c; j++) {
                cin >> x;
                mat[i][j] = x;
            }
        }
        Solution ob;
        auto ans = ob.maxArea(mat, r, c);
        cout << ans << "\n";

    }
    return 0;
}
  // } Driver Code Ends