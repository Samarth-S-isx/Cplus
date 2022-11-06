#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define S second
#define F first
vector<vector<pair<int,int>>> g;
int n,m,x;
int dis[100009];
void bfs(int node){
    deque <int> q;
    for(int i=1;i<=n;i++){
        dis[i]=1e9;
    }
    dis[node]=0;
    q.push_back(node);
    while (!q.empty())
    {
        int xx = q.front();
        q.pop_front();
        for(auto x:g[xx]){
            int negihbour = x.F;
            int weight = x.S;
            if(dis[negihbour]>dis[xx]+weight){
                dis[negihbour]=dis[xx]+weight;
                if(weight==0) q.push_front(negihbour);
                else q.push_back(negihbour);
            }
        }
    }
    



}   


int solve()
{
    
    cin >> n >>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int sc;
    cin>>sc;
    bfs(sc);
    cout<<dis[sc]<<endl;
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