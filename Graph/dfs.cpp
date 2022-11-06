#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<vector<int>> g;
vector<int> visited;

void dfs(int node,int comp){
    visited[node] = comp;
    for(auto v:g[node]){
        if(!visited[v]){
            dfs(v,comp);
        }
    }
}

int solve()
{
    int n,m;
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    visited.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b ; 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            comp++;
            dfs(i,comp);
        }
    }
    int a[comp+1];
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        a[visited[i]]++;
    }
    ll ans = 0;
    ll sum = 0;
    for(int i=1;i<=n;i++){
        ans+=a[i]*sum;
        sum+=a[i];
    }
    for(auto x:a){
        cout << x << endl;
    }


};
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}