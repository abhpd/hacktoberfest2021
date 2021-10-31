/* Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR. 
Problem Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
class Solution{
    public:
    vector<string> findPath(vector<vector<int>> & m, int n) {
        std::vector<std::string> res;
        if(m[0][0]==0){
            return res;
        }
        std::unordered_set<std::pair<int,int>,pair_hash> set;
        recur(res,m,n,0,0,set,"");
        std::sort(res.begin(),res.end());
        return res;
    }
    void recur(std::vector<std::string> & res,vector<vector<int>> & m, int n,int i,int j,std::unordered_set<std::pair<int,int>,pair_hash> set,string path){
        if(i == n-1 && j == n-1){
            res.push_back(path);
            return;
        }
        set.insert(std::make_pair(i,j));
        if(i != n-1 && m[i+1][j] != 0 && set.count(std::make_pair(i+1,j)) == 0){
            recur(res,m,n,i+1,j,set,path+"D");
        }
        if(i != 0 && m[i-1][j] != 0 && set.count(std::make_pair(i-1,j)) == 0){
            recur(res,m,n,i-1,j,set,path+"U");
        }
        if(j != n-1 && m[i][j+1] != 0 && set.count(std::make_pair(i,j+1)) == 0){
            recur(res,m,n,i,j+1,set,path+"R");
        }
        if(j != 0 && m[i][j-1] != 0 && set.count(std::make_pair(i,j-1)) == 0){
            recur(res,m,n,i,j-1,set,path+"L");
        }
    }
};