#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define S second
#define F first
typedef long long ll;
int n,m;



bool check(int x, int y){
    if(x>=0 && x<n && y>=0 && y<n && arr[x][y]!='#'){
        return 1;
    }
    return 0;
}

void bfs(pair<int,int> st){
    queue <pair<int,int>> q;    
    dist = vector<vector<int>>(n,vector<int>(m,1e9));
    par = vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(m,{0,0}));
    dist[st.F][st.S]=0;
    par[st.F][st.S] = {-1,-1};
    q.push(st);
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(check(pos.F+dx[i],pos.S+dy[i])&& dist[pos.F+dx[i]][pos.S+dy[i]]>dist[pos.F][pos.S]+1){
                par[pos.F+dx[i]][pos.S+dy[i]]={pos.F,pos.S};
                dist[pos.F+dx[i]][pos.S+dy[i]] = dist[pos.F][pos.S]+1;
                q.push({pos.F+dx[i],pos.S+dy[i]});
            }
        }

    }

}

int solve()
{
    cin >>n>>m;
    arr = vector<vector<char>>(n,vector<char>(m,'0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }   
    pair<int,int> s;
    pair <int,int> e;
    cin >> s.F >> s.S;
    cin >> e.F >> e.S;
    bfs(s);
    cout << dist[e.F][e.S]<<endl;
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