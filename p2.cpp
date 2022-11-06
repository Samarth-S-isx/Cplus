#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define prll(arr)     \
    for (auto x : arr) \
        cout << x << " ";
string bts(ll x)
{
    bitset<32> bset(x);
    return bset.to_string();
}
ll N = 1e5 + 10;

void solve()
{
    ll n, x;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll,ll> m1,m2,m3,m4;

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];m1[a[i]]++;
        // x = log10(a[i])+1;
        // if(x!=1LL) a[i]=x;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];m2[b[i]]++;
        // x = log10(b[i])+1;
        // if(x!=1LL) b[i]=x;
    }
    for(ll i=0;i<n;i++){
        if(m1[a[i]]>=1 && m2[a[i]]>=1){ 
        m1[a[i]]--,m2[a[i]]--; 
        }
    }
    ll ans=0; 
    vector<ll> a2,b2; 
    for(ll i=0;i<n;i++){ 
        if(m1[a[i]]>=1 && a[i]>=10){ 
            ll x=a[i],cnt=0; 
            m1[x]--; 
            cnt = log10(a[i])+1;
            a2.push_back(cnt); 
            m3[cnt]++; 
            ans++; 
        } 
        else if(m1[a[i]]>=1){ 
            a2.push_back(a[i]); 
            m1[a[i]]--; 
            m3[a[i]]++; 
        } 
    } 
    for(ll i=0;i<n;i++){ 
        if(m2[b[i]]>=1 && b[i]>=10){ 
            ll el=b[i],cnt=0; 
            m2[el]--;  
            cnt = log10(b[i])+1;
            b2.push_back(cnt); 
            m4[cnt]++; 
            ans++; 
        } 
        else if(m2[b[i]]>=1){ 
            b2.push_back(b[i]); 
            m2[b[i]]--; 
            m4[b[i]]++; 
        } 
    } 

   
    for(ll i=0;i<a2.size();i++){ 
        if(m3[a2[i]]>=1 && m4[a2[i]]>=1){ 
            m3[a2[i]]--,m4[a2[i]]--; 
            
        } 
    } 
    for(ll i=0;i<a2.size();i++){ 
        if(m3[a2[i]]!=0 && a2[i]!=1){ 
            ans++; 
            m3[a2[i]]--; 
        } 
    } 
    for(ll i=0;i<b2.size();i++){ 
        if(m4[b2[i]]!=0 && b2[i]!=1) 
            { 
                ans++; 
                m4[b2[i]]--; 
            } 
    } 
    cout<<ans<<endl; 
};
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // solve();
    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}