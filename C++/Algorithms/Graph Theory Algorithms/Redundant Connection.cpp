// Leetcode question : https://leetcode.com/problems/redundant-connection/
// Question : Redundant Connection
// Redundent connection : UNION FIND SOLUTION

class Solution {
public:
    
    vector<int> parent;
    
    int findParent(int u){
        return parent[u] == u ? u : (parent[u] = findParent(parent[u]));
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size()+1;
        
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        
        for(vector<int> &e:edges){
            int u = e[0], v = e[1];
            int p1 = findParent(u), p2 = findParent(v);
            
            if(p1 != p2){
                parent[p1] = min(p1, p2);
                parent[p2] = min(p1,p2);
            }else{
                return e;
            }
        }
        
        return {};
    }
};
