#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class ncr
{
    public : 

    vector<ll> factorial;
    ll mod = 998244353;

    ncr( ll size)
    {
        factorial.resize(size + 1);
        factorial[0] = 1;

        ll val = 1;
        for (ll i = 1; i <= size; i++)
        {
            val = (val * i) % mod;
            factorial[i] = val;
        }
    }

      ll bigmod(ll a, ll b) {
            ll result = 1;
            while (b > 0) {
                if (b & 1) result = (result * a) % mod;        
                a = (a * a) % mod;
                b >>= 1;              
            }
            return result;
        }

    ll cal( ll n , ll r)
    {
        ll a = factorial[n];
        ll b = (factorial[r] * factorial[n - r]) % mod;
        return ( a * bigmod(b , mod - 2) ) % mod;
    }
};



int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ncr ncr(1e6+5);

vector<ll> save;
save.push_back(2);

for (ll i = 4; i < 1e6+3; i+=2)
{
    save.push_back( (save[save.size()-1] ^ ncr.cal(i,i/2)) );
}


ll int t; cin >> t;
while(t--) {

ll n; cin >> n;

ll val = 0;
val ^= (n % 2);

if(n == 1) {cout << val << endl; continue;}

ll x = n/2;
val ^= save[x-1];

cout << val << endl;


}

// Time Complexcity  : O() 
// Space Complexcity : O() 
}