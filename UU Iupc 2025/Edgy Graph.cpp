#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
while(t--) {

ll n,m; cin >> n >> m;
vector<ll> v(n+1,1e9);

ll found = 0;
map<pair<ll,ll>,ll> save;
for (ll i = 0; i < m; i++)
{
    ll a,b,w; cin >> a >> b >> w;
    v[a] = min(v[a],w);
    v[b] = min(v[b],w);
    save[{a,b}] = w;
}

for(auto [x,y] : save)
{
    if(y != max(v[x.first],v[x.second])) {found = 1; break;}
}

if(found == 1) {cout << -1 << endl; continue;}
for (ll i = 1; i <= n; i++)
{
    cout << v[i] << " ";
}
cout << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}