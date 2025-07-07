#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"


void make_prime(vector<bool> &seive,vector<ll> &prime)
{
    seive[0] = 1;
    seive[1] = 1;
    
    ll size = seive.size();
    for (ll i = 2; i*i < size; i++)
    {
        if(seive[i] == 0)
        {
            for (ll j = i*i; j < size; j+=i) seive[j] = 1;
        }
    }

    for (ll i = 2; i < size; i++) if(seive[i] == 0) prime.push_back(i);
    
}

ll cal(ll a , ll b , ll c , ll x)
{
    return (a*(x*x) + b*x + c);
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);


vector<bool> seive(1e5+1000);
vector<ll> prime;
make_prime(seive,prime);

map<ll,ll> save;

for (ll i = 1; i < prime.size(); i++)
{
    if( (prime[i-1] + prime[i+1])/2 > 1e4) break; 
    if( (prime[i-1] + prime[i+1]) % 2 == 0 &&  (prime[i-1] + prime[i+1])/2 == prime[i]) save[prime[i]] = 1;
}


ll a,b,c; cin >> a >> b >> c;

if(a == 0 && b == 0) {cout << -1 << endl; return 0;}

ll val = 0;
vector<ll> ans;
while(1)
{
    ll x = cal(a,b,c,val++);
    if(x > 1e4) break;
    if(save[x] == 1) ans.push_back(x);
}

if(ans.size() == 0) {cout << -1 << endl; return 0;}

cout << ans.size() << endl;
for(auto u:ans) cout<<u<< " " ;
cout << endl;


// Time Complexcity  : O() 
// Space Complexcity : O() 
}