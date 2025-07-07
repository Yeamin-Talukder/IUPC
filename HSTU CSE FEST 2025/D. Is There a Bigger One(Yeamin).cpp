#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll n; cin >> n;
vector<ll> v(n); for(auto &u:v) cin>>u;

vector<ll> mx(n);
ll high = 0;
for (ll i = n-1; i >= 0; i--)
{
    if(v[i] > high) high = v[i];
    mx[i] = high;
}

for (ll i = 0; i < n; i++)
{
    if(v[i] < mx[i] ) cout << 1 << " ";
    else cout << 0 << " ";
}
cout << endl;

// Time Complexcity  : O() 
// Space Complexcity : O() 
}