#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define FIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield);cout.precision(20);cout.setf(ios::fixed,ios::floatfield);
#define endl '\n';
int main()
{
    FIO;
    ll t;
    cin>>t;
    while(t--){
        ll n,i;
        cin>>n;
        if(n>1){
        for(i=1;i<=n-2;i++){
            cout<<1<<" ";
        }
        cout<<2<<" "<<n<<endl;
        }
        else{
            cout<<1<<endl;
        }

    }
}