#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

const double pi = acos(-1.0);
const long long INF = 2e18;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define in insert
#define endl "\n"

#define sqr(a) ((a) * (a))
#define jor(a) !(a&1)// jor means EVEN number
#define bjor(a) (a&1)// bjor means ODD number

#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr))
//memset only for -1 and 0
//fill(a, a+n, 5) //fill for any value

#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);

void print(int a[], int n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define Y() cout <<"YES"<<endl
#define N() cout <<"NO"<<endl

//-------------------------------------------------------------------

vll g[105];
ll cost[105][105];
ll dis[105];
ll n, m;

void dijkstra(ll start){
    fill(dis, dis+105, 1e15);
    dis[start]=0; /// distance of starting node is 0

    priority_queue<pair<ll, ll> >q;
    q.push({0,start}); /// {dis,node} sort by distance

    while(!q.empty()){
        ll u = q.top().ss;
        ll costU = -q.top().ff;
        q.pop();

        if(u==n) return;

        for(auto v: g[u]){ /// go to every node connected to u
            ll c = cost[u][v];
            if(cost[u][v]+costU < dis[v]){ /// if min cost possible
                dis[v] = cost[u][v]+costU;
                q.push({-dis[v], v});
            }
        }
    }
}

void solve()
{
    /// clear
    for0(i,105) g[i].clear();
    memset(cost, -1, sizeof(cost));

    cin>>n>>m;

    /// input
    for0(i,m){
        ll u,v,c; cin>>u>>v>>c;
        g[u].pb(v), g[v].pb(u);
        if(cost[u][v]==-1){
            cost[u][v] = c;
            cost[v][u] = c;
        }
        else{ /// for more edge between two nodes, keep the minimum one
            cost[u][v] = min(cost[u][v], c);
            cost[v][u] = min(cost[v][u], c);
        }
    }

    dijkstra(1);

    if(dis[n] != 1e15) cout<<dis[n]<<endl;
    else cout<<"Impossible"<<endl;
}

int main()
{
    int tc=1;
    cin>>tc;
    int testCase = 0;
    while(tc--){
        cout<<"Case "<<++testCase<<": ";
        solve();
    }
}

