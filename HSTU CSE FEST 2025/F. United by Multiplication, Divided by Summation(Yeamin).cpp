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

if(n == 1) {cout << 1 << endl; continue;}
if(n == 2 ) {cout << 2 << " " << 2 << endl; continue;}

for (ll i = 0; i < n; i++)
{
    if(i == 0) cout << n << " ";
    else if( i == 1) cout << 2 << " ";
    else cout << 1 << " ";
}
cout << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}