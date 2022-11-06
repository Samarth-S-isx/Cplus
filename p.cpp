#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define prll(arr)      \
    for (auto x : arr) \
        cout << x << " ";
string bts(ll x)
{
    bitset<32> bset(x);
    return bset.to_string();
}
ll N = 1e5 + 10;

void solve(ll t)
{
   int n,x;
   cin>>n>>x;
   vector<int>a(n,0);
   int maxx = 0;
   for(int i=0;i<n;i++){
        cin>>a[i];
        maxx = max(maxx,a[i]);
   }
    int y = x/maxx;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            cout<<1<<endl;
            return;
        }
    }
    if(y*maxx==x){
        cout<<max(2,y)<<endl;
    }else{
        cout<<max(2,y+1)<<endl;
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // solve(0);
    ll tc, t = 0;
    cin >> tc;
    while (t < tc)
    {
        solve(t + 1);
        t++;
    }
}