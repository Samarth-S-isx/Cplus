#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<vector<int>> g;
vector<int> vis;
vector<int> bfsvis;
bool isloop = false;
bool dfs(int node)
{
    vis[node] = 1;
    bfsvis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            if (dfs(v))
            {
                return true;
            };
        }
        else if (vis[v] == bfsvis[v])
        {
            return true;
        }
    }
    bfsvis[node] = 0;
    return false;
}

int solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    bfsvis.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i))
            {
                cout << true << endl;
                return 0;
            }
        }
    }
    cout << false << endl;
};
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    // int tc;
    // cin >> tc;
    // while (tc--)
    // {
    //     solve();
    // }
}