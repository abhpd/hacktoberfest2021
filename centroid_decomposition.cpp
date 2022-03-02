int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
    static vector<int> sz(g.size());
    function<void (int, int)> get_sz = [&](int i, int par) {
        sz[i] = 1;
        for (auto j : g[i]) {
            if (j != par && !dead[j]) {
                get_sz(j, i);
                sz[i] += sz[j];
            }
        }
    };
    get_sz(root, -1);
    int n = sz[root];
    function<int (int, int)> dfs = [&](int i, int par) {
        for (auto j : g[i]) {
            if (j != par && !dead[j]) {
                if (sz[j] > n / 2) {
                    return dfs(j, i);
                }
            }
        }
        return i;
    };
    return dfs(root, -1);
}

vector<int> CentroidDecomposition(const vector<vector<int>> &g, const vector<vector<pair<int, int>>> &l, int q) {
    int n = g.size();
    vector<int> ans(q, 0);
    vector<bool> dead(n, false);
    function<void (int)> rec = [&](int start) {
        int c = OneCentroid(start, g, dead);
        dead[c] = true;
        for (auto i : g[c]) {
            if (!dead[i]) {
                rec(i);
            }
        }
        dead[c] = false;
    };
    rec(0);
    return ans;
}
