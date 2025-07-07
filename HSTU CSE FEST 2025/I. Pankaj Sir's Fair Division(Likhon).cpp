#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int main(){
    
    ll t; cin>>t;
    while(t--){
        ll l,r,d; cin>>l>>r>>d;
        ll n=r-l+1;
        ll a=l+d;
        ll sum= (n*( (2*a) + (n-1)*(d+1) ))/2;
        
        ll hi=n,lo=1;
        ll x=-1;
        
        while(hi-lo>1){
            ll mid=(hi+lo)/2;
            
            ll sum1= (mid*( (2*a) + (mid-1)*(d+1) ))/2;
            
            if(sum1<(sum-sum1)){
                lo=mid;
            }
            else if(sum1>(sum-sum1)){
                hi=mid;
            }
            else{
                x=mid; break;
            }
        }
        ll ans=0;
        if(x==-1){
            ll k=(hi*( (2*a) + (hi-1)*(d+1) ))/2;
            ll t=(lo*( (2*a) + (lo-1)*(d+1) ))/2;
            
            ans = min(abs(sum-2 * k), abs(sum-2 * t));
        }
        cout<<ans<<endl;
    }
}