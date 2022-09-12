#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 500;
ll ans[200][200];
ll check[200][200];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i = 0; i<n; i++)cin>>v[i];
    sort(v.begin(), v.end());
    for(ll i = 0; i<200; i++){
        for(ll j = 0; j<200; j++){
            check[i][j] = inf;
        }
    }
    ll ok = v[0];
    for(ll i = 0; i<n; i++){
        check[i][0] = 0;
    }
    for(ll i = 1; i<n; i++){
        if(ok-1<0)break;
        ans[i][0] = 1;
        check[i][0] = 1;
        ok--;
    }
    for(ll j = 1; j<n; j++){
        ll kek = v[j];
        for(ll i = 0; i<n; i++){
            if(i == j)continue;
            if(kek<=0){
                check[i][j] = 0;
                ans[i][j] = 0;
                continue;
            }
            if(check[j][i] == inf and kek>0){
                ans[i][j] = 1;
                check[i][j] = 1;
                kek--;
                continue;
            }
            ans[i][j] = abs(2-check[j][i]);
            kek-=abs(2-check[j][i]);
            check[i][j] = ans[i][j];
        }
    }
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
