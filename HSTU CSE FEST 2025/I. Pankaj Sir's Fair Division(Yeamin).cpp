#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll cal (ll l , ll r , ll d )
{
    ll n = r-l+1;
    ll a = l+d;
    ll sum = (n*( (2*a) + (n-1)*(d+1) ))/2;
    return sum;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
while(t--) {

    ll l,r,d; cin>>l>>r>>d;

    if( (r-l+1) == 2)
    {
        ll x = cal(l , r , d);
        ll y = cal(l , r-1 , d);

        cout << abs((x-y) - y) << endl;
        continue;
    }


    ll total = cal(l , r , d);
    ll ans = LLONG_MAX;
    
    ll low = l;
    ll high = r;

    while( (high - low + 1 ) >= 3 )
    {
        ll mid1 = low + (high - low + 1)/3;
        ll mid2 = high - (high - low + 1)/3;

        ll sum1 = cal(l , mid1 , d); sum1 = abs( (total - sum1) - sum1 );
        ll sum2 = cal(l , mid2 , d); sum2 = abs( (total - sum2) - sum2 );

        if(sum1 < sum2 ) {ans = min(ans,sum1); high = mid2;}
        else {ans = min(ans,sum2); low = mid1;}
    }
    
    cout << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}