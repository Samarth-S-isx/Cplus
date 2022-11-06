#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define print(arr)        \
    for (auto x : arr)    \
    {                     \
        cout << x << " "; \
    }
int solve()
{
   string s;
   cin>>s;
//    reverse(s.begin(),s.end());
   int n = s.size();
   int kmp[n+1];
   kmp[0] = -1;
   int i = 0,j=-1;
   while(i<n){
        while(j!=-1 && s[i]!=s[j]) j = kmp[j];
        j++;i++;
        kmp[i] = j;
   }
    print(kmp);
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