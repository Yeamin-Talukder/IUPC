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

if(n > 4) {cout << "NO" << endl; continue;}
if(n == 1) {cout << "YES" << endl; continue;}

if(n == 2 ) {
    ll num = stoll(s);
    if(num % 2 == 0) {cout << "YES" << endl;}
    else cout << "NO" << endl;
    continue;
}

ll found = 0;

for (ll i = 0; i < n-1; i++)
{
    string tem;
    tem.push_back(s[i]);
    tem.push_back(s[i+1]);
    ll num = stoll(tem);
    if(num % 2 != 0){found = 1;break;} 
}

if(found == 1) {cout << "NO" << endl; continue;}


if(n >= 3)

{for (ll i = 0; i < n-2 ; i++)
{
    string tem;
    tem.push_back(s[i]);
    tem.push_back(s[i+1]);
    tem.push_back(s[i+2]);
    ll num = stoll(tem);
    if(num % 3 != 0){found = 1;break;}
}}

if(found == 1) {cout << "NO" << endl; continue;}

if(n == 4)
{
for (ll i = 0; i < n-3; i++)
{

    string tem;
    tem.push_back(s[i]);
    tem.push_back(s[i+1]);
    tem.push_back(s[i+2]);
    tem.push_back(s[i+3]);
    ll num = stoll(tem);
    if(num % 4 != 0){found = 1;break;}
}}

if(found == 1) {cout << "NO" << endl; continue;}
else cout << "YES" << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}