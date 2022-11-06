#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<vector<pair<ll,ll>>> g;
vector<ll> vis;
vector <ll> dist;
ll n,m;
void dikstra(ll sc){
    dist[sc] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,sc});
    while(!pq.empty()){
        ll u = pq.top().second;pq.pop();
        if(vis[u]!=-1) continue;
        vis[u]=1;
        for(auto x:g[u]){
            ll v = x.first;
            ll w = x.second;
            if(vis[v]!=-1) continue;
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

int solve()
{
    ll x,a,b,c;
    cin >> n>>m;
    g.clear();
    g.resize(n+1);
    vis.resize(n+1,-1);
    dist.resize(n+1,1e18);
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    dikstra(1);
    for(ll i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
};
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}