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
    for(ll i = 0; i<200; i++){
        for(ll j = 0; j<200; j++){
            check[i][j] = inf;
        }
    }
    sort(v.begin(), v.end());
    ll ok = v[0];
    for(ll i = 0; i<n; i++)check[i][0] = 0;
    for(ll i = 1; i<v.size(); i++){
        if(ok-1<0)break;
        check[i][0] = 1;
        ans[i][0] = 1;
        ok-=1;
    }
    for(ll j = 1; j<v.size(); j++){
        ll kek = v[j];
        for(ll i = 0; i<v.size(); i++){
            if(j == i)continue;
            if(kek <= 0)break;
            else if(check[j][i] == inf){
                ans[i][j] = 1;
                check[i][j] = 1;
                kek-=1;
            }
            else{
                ans[i][j] = abs(2-check[j][i]);
                kek-=abs(2-check[j][i]);
            }
            //cout<<i<<" "<<j<<" "<<kek<<"\n";
        }
    }
    for(ll i = 0; i<n; i++){
        for(ll j = 0 ;j<n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
