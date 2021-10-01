struct BlockCutTree{
    // id is the component ID after we abstract the the 2-vertex connected components
    vector<int> tin, low, id;
    vector<bool> isCut, vis;
    stack<int> s;
    bool makeComponents;//Whether we want to store components or not
    int n, timer;
    vector<vector<int>> comps;
    void init(int _n, bool _makeComponents) {
        n = _n;
        timer = 0;
        makeComponents = _makeComponents;
        tin.resize(n), low.resize(n), isCut.resize(n), vis.resize(n);
    }
    void makeComp(int id = -1) {
        vector<int> cmp;
        while (!s.empty() && s.top() != id) {
            cmp.push_back(s.top());
            s.pop();
        }
        if (id != -1) {
            s.pop();
            cmp.push_back(id);
        }
        comps.push_back(cmp);
    }
    void dfs(int i, const vector<vector<pair<int, int>>> &g, int par = -1) {
        vis[i] = true;
        low[i] = tin[i] = timer++;
        bool hasPath = false;
        for (auto [j, id]: g[i]) {
            if (j == par) continue;
            if (!vis[j] || tin[j] < tin[i]) {
                s.push(id);
            }
            if (vis[j]) {
                low[i] = min(low[i], tin[j]);
            }else{
                dfs(j, g, i);
                low[i] = min(low[i], low[j]);
                if (par == -1 ? hasPath: low[j] >= tin[i]) {
                    isCut[i] = true;
                    if (makeComponents) {
                        makeComp(id);
                    }
                }
                hasPath = true;
            }
        }
    }
    void findArticulationPoints(const vector<vector<pair<int, int>>> &g) {
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, g);
                makeComp();
            }
        }
    }
    //TODO: Depending on the Problem, should be implemented
//    void blockCutTree() {
//        
//    }
};
