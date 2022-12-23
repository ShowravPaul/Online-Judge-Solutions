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


void solve()
{
    ll n,  m;
    cin>>n>>m;

    vll g[n+5];
    ll w[n+5][n+5];
    ll dis[n+5];

    memset(w, 0, sizeof(w)); /// all weight 0 initially
    fill(dis, dis+n+5, 2e9); /// all dis INF

    for0(i,m){
        ll x, y, d; cin>>x>>y>>d;
        if(w[x][y] == 0){
            w[x][y] = w[y][x] = d;

            g[x].pb(y), g[y].pb(x);
        }
        else{
            w[x][y] = w[y][x] = min(d, w[x][y]);
        }
    }


    /// basic Dijkstra
    
    ll str; cin>>str;

    queue<ll>q;
    q.push(str);
    dis[str]=0; /// starting node er dis 0

    while(!q.empty()){
        ll node = q.front();
        q.pop();

        for(auto t: g[node]){
            /// ei node e aste max koto
            /// 1. ager node porjonoto ja chilo ar
            /// 2. ager node ar ei node asar edge ta
            /// 1 ar 2 er max
            ll newMax = max(dis[node], w[t][node]);

            /// ans jodi ager tai valo thake taile ar change korum na, eita ekta wrong way
            /// ar jodi eita best hoy taile eitai ans and eita ans dia samne aro kichu node er ans valo paite pari karon eita ager ta theke valo way
            if(dis[t] > newMax){
                dis[t] = newMax;
                q.push(t);
            }
        }
    }

    for0(i,n){
        if(dis[i] == 2e9) cout<<"Impossible\n";
        else cout<<dis[i]<<endl;
    }
}

int main()
{
    FAST
    int tc=1;
    cin>>tc;
    int testCase = 0;
    while(tc--){
        cout<<"Case "<<++testCase<<":\n";
        solve();
    }
}

