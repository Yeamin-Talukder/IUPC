#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int main() {
    ll t = 1; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll>v(n); for(ll i=0;i<n;i++) cin>>v[i];
        ll ans=0,oneco=0,sum=0;
        ll rep=1e9;
        for(ll i=n-1;i>=0;i--){
            
            if(i==n-1 && v[i]!=-1) rep=v[i];
            
            if(v[i]==-1){
                sum+=rep;
                //cout<<sum<<endl;
                oneco++;
            }
            else{
                if(v[i]>rep){
                    ans=max(sum,ans);
                    sum=(oneco*1e9)+v[i];
                    oneco=0;
                    rep=v[i];
                }
                else{
                    sum+=v[i];
                    ll tem=(oneco*1e9)+v[i];
                    if(tem>sum){
                        sum=tem;
                        
                    }
                    oneco=0;
                    rep=v[i];
                }
                
            }
            //cout<<ans<<endl;
        }
        
        ans=max(sum,ans);
        
        if(oneco>0){
            ll tem=(oneco*1e9);
            ans=max(ans,tem);
        }
        
        cout<<ans<<endl;
        
    }
}