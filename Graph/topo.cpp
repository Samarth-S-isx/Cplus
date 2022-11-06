#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<vector<int>>g;
int n,m;
vector<int> vis;
vector<int> indegree;
vector<int> topo;

int solve()
{
    int a,b;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    indegree.assign(n+1,0);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        indegree[b]++;
    }
    for(auto x:indegree){
        cout<<x<<" ";
    }
    cout<<endl;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++) if(indegree[i]==0) pq.push(i);
    while(!pq.empty()){
        int u = pq.top();pq.pop();
        topo.push_back(u);
        for(auto v:g[u]){
            indegree[v]--;
            cout<<v<<"**"<<endl;
            if(indegree[v]==0) pq.push(v);
        }
    }
    for(auto x:indegree){
        cout<<x<<" ";
    }
    cout<<endl;
    if(topo.size()!=n){
        cout<<-1<<endl;
        return 0;
    } 
    for(auto x:topo){
        cout<<x<<" ";
    }
    cout<<endl;

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