#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"


class segment_tree
{
public : 

vector<vector<ll>>save;

segment_tree(ll size)
{
    save.resize(4*size);
}

void create(ll node,ll start,ll end,vector<ll>&v)
{
if(start== end) { save[node].push_back(v[start]);  return;}

ll mid = (start+end) / 2;
create(node*2 , start , mid , v);
create((node*2)+1 , mid+1 , end , v);

ll l = 0 , r = 0;

while(l < save[node*2].size() && r < save[node*2 + 1].size())
{
    if(save[node*2][l] < save[node*2 + 1][r]) save[node].push_back(save[node*2][l++]);
    else save[node].push_back(save[node*2 + 1][r++]);
}

while(l < save[node*2].size()) save[node].push_back(save[node*2][l++]);
while(r < save[node*2 + 1].size()) save[node].push_back(save[node*2 + 1][r++]);

}

void query(ll node , ll start , ll end , ll l , ll r , ll value , pair<ll,ll> &ans)
{

if(start > r || end < l) return;

    if(l <= start && end <= r )
    {
        ll small = (lower_bound(save[node].begin(), save[node].end() , value) - save[node].begin() );
        ll big =   save[node].size() - (upper_bound(save[node].begin(), save[node].end() , value) - save[node].begin());

        ans.first += small;
        ans.second += big;

        return;
    }

ll mid=(start+end)/2;

query(node*2,start,mid,l,r,value,ans);
query((node*2)+1,mid+1,end,l,r,value,ans);

}

};

void dfs(ll node , ll parent , ll &time , vector<ll> &in , vector<ll> &out , vector<vector<ll>> &edge)
{
    in[node] = time++;
    for(auto child : edge[node])
    {
        if(child != parent) dfs(child , node , time , in , out , edge);
    }
    out[node] = time++;
}

void traverse(ll node , ll parent , ll n , vector<ll> &in , vector<ll> &out , vector<vector<ll>> &edge , vector<ll> &weight, segment_tree &seg  , ll &ans )
{
    pair<ll,ll> total = {0,0};
    seg.query(1 , 1 , 2*n , 1 , 2*n , weight[node] , total);

    total.first /= 2;
    total.second /= 2;

    for(auto child : edge[node])
    {
        if(child != parent)
        {
            pair<ll,ll> x = {0,0};
            seg.query(1 , 1 , 2*n , in[child] , out[child]  , weight[node] , x);

            x.first /= 2;
            x.second /= 2;

            ll small = total.first - x.first;
            ll big = total.second - x.second;

            ll add = (small * x.second) + (big * x.first) ;

            total.first -= x.first;
            total.second -= x.second;

            ans += add;
        }
    }
}


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
while(t--) {

ll n; cin >> n;

vector<vector<ll>> edge(n+2);
vector<ll> parent(n+1);
parent[1] = -1;

for (ll i = 2; i <= n; i++)
{
    ll x; cin >> x;
    edge[i].push_back(x);
    edge[x].push_back(i);

    parent[i] = x;
}

vector<ll> weight(n+1); 
for (ll i = 1; i <= n; i++)
{
    ll x; cin >> x;
    weight[i] = x; 
}

vector<ll> in(n+1),out(n+1),flat(2*n+1);

ll time = 1;
dfs(1 , -1 , time , in , out , edge);

for (ll i = 1; i <= n; i++)
{
    flat[in[i]] = weight[i];
    flat[out[i]] = weight[i];
}

segment_tree seg(flat.size()+5);
seg.create(1,1,flat.size()-1,flat);

ll ans = 0;
for (ll i = 1; i <= n ; i++)
{
    traverse(i , parent[i] , n , in , out , edge , weight , seg , ans);
} 
cout << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}