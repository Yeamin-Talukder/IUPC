#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
while(t--) {


ll n; cin >> n;

string s; cin >> s;


if(n == 1 && s == "B") {cout << 1 << endl; continue;}
if(n == 1 && s == "A") {cout << -1 << endl; continue;}


map<char,ll> save;

ll found = 0;
for (ll i = 0; i < n; i++)
{
    if( i < n-1 && s[i] == 'B' && s[i+1] == 'B') {found = 1; break;}
    save[s[i]]++;
}



if( save.size() == 1 || found == 1 ) {cout << -1 << endl; continue;}

vector<ll> ans(n,-1);
ll val = n;

for (ll i = 0; i < n; i++)
{
    if(s[i] == 'A') ans[i] = val--;
    else break;
}

for (ll i = n-1; i >= 0 ; i--)
{
    if(s[i] == 'A') ans[i] = val--;
    else break;
}

for (ll i = 0; i < n; i++)
{
    if(s[i] == 'A' && ans[i] == -1) ans[i] = val--;
}

for (ll i = 0; i < n; i++)
{
    if(ans[i] == -1) ans[i] = val--;
}

for(auto u : ans) cout<<u<< " " ;
cout << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}