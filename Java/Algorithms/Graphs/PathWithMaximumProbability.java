class Solution
{
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //create own graph
        vector<unordered_map<int, double>> graph(n);
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]][edges[i][1]] = succProb[i];
            graph[edges[i][1]][edges[i][0]] = succProb[i];
        }
        
        //functionality wise, this array works as a visited array, 
        //only when we find a larger probability than the stored value
        //we will need to push next node into the queue
        vector<double> ps(n, 0.0);  ///probability of reaching each node
        
        ps[start] = 1.0; //important intilization
        
        queue<int> q;
        q.push(start);
        double res = 0;
        while(!q.empty()) {
            int nd = q.front();
            q.pop();
            for(auto& it: graph[nd]) {
                int next = it.first;
                double pro = it.second;
                //we can reach this node with a larger probability, try starting from it
                //a node might be pushed into the queue more than once
                if(ps[nd] * pro > ps[next]) {
                    q.push(next);
                    ps[next] = ps[nd] * pro;
                }
            }
        }
        
        return ps[end];
    }
}
