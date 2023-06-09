// Next Greater Element
/*
    In this Question, we need to find the next Greater Element for all the elements in an array.
    Ex: 
        Input : n = 6
                arr: 75 84 92 74 9 29
        Output : 84 92 -1 -1 29 -1

*/

#include <bits/stdc++.h>
using namespace std;

// Naive Approach
/*
    Traversing the remaining array for each element and finding the next greater for every element using two nested loops.
*/

vector<int> nextGreaterElement1(vector<int> arr, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                ans.push_back(arr[j]);
                break;
            }
        }
    }
    return ans;
}

/*
    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/




// Efficient Approach
/*
    Using a stack
        Traversing the array backwards, Popping all the smaller elements than the current element and pushing the elements in the stack.
            - If any element greater than the current element is present in the stack, then it is the next greater element for the current element,
            - else, then the next greater element for the current element is -1
*/

vector<int> nextGreaterElement2(vector<int> arr, int n)
{
    if (n == 0)
        return {};
    stack<int> st;
    st.push(arr[n - 1]);
    vector<int> ans;
    ans.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        ans.push_back(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/

// Display Utility Function
void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> ans1 = nextGreaterElement1(arr, n);
    display(ans1);
    vector<int> ans2 = nextGreaterElement2(arr, n);
    display(ans2);
    return 0;
}