#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <vector<int>> g;
vector <int> vis;
bool isloop = false;
bool dfs(int node,int par){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            if(dfs(v,node)){
                return true;
            };
        }
        else if(v!=par){
            return true;
        }
    }
    return false;
}



int solve()
{
    int n,m; 
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1)){
                cout << true <<endl;
                return  0;
            }
        }
    }
    cout << false <<endl;
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