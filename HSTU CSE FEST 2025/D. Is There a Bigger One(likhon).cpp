#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int main(){
    
    ll n; cin>>n;
        
    vector<ll>v(n),pre(n); for(ll i=0;i<n;i++) cin>>v[i];
    
    ll mx=LLONG_MIN;
    
    for(ll i=n-1;i>=0;i--){
        if(v[i]>mx){
            pre[i]=v[i];
            mx=v[i];
        }
        else pre[i]=mx;
    }
    
    for(ll i=0;i<n-1;i++){
        if(pre[i+1]>v[i]) cout<<1<<" ";
        else cout<<0<<" ";
    }
    cout<<0<<endl;
}