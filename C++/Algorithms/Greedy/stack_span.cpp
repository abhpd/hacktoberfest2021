/* The span of a stack price is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stocks was less than or equal to todays Price
Sample Input: [100,80,60,70,60,75,85]
Sample output: ans[1,1,1,2,1,4,6] */
# include<bits/stdc++.h>
using namespace std;
vector<int> stackspan(vector<int> a)
{
    int n=a.size();
    vector<int> ans;
    stack<pair<int,int>> s;
    for(int i=0;i<a.size();i++)
    {
        int days=1;
        while(!s.empty() && s.top().first<=a[i])
        {
            days+=s.top().second;
            s.pop();
        }
        s.push({a[i],days});
        ans.push_back(days);
    }
    return ans;
}
int main()
{
    vector<int> a ={100,80,60,70,60,75,85};
    int n;
   // n=7;
    vector<int> ans=stackspan(a);
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;

}
