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

map<char,int> save;
for(auto u : s) save[u]++;

if(save['H'] > 0 && save['S'] && save['T'] && save['U']) cout << "YES" << endl;
else cout << "NO" << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}