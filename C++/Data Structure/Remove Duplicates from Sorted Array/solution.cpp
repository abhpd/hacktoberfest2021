class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int temp=-101;
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=temp){
                temp=a[i];
                count++;
            }
            else{
                a[i]=101;
            }
        }
        sort(a.begin(),a.end());
        return count;
    }
};
