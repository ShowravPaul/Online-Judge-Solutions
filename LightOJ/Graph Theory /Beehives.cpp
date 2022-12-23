#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
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
#define jor(a) !(a&1) /// jor means EVEN number
#define bjor(a) (a&1) /// bjor means ODD number
#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr))
/// memset only for -1 and 0
/// fill(a, a+n, 5) /// fill for any value

#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);

#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl

///---------------------------------------------------------------------------------------
/// for debugging

#define printLine() cout << "----------" << endl;

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" = "; _print(x); cout << endl;
#endif

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

///---------------------------------------------------------------------------------------

vector<ll> v[505];


ll BFS(ll s) {
    queue<ll> q;
    q.push(s);

    ll vis[505] = {};
    ll dis[505] = {};
    ll parent[505] = {};
    ll ans = INF;

    vis[s] = 1;
    dis[s] = 0;
    parent[s] = -1;

    while(q.sz) {
        ll u = q.front();
        q.pop();
        // debug(u)

        for(auto t : v[u]) {
            if(vis[t] == 0) {
                q.push(t);
                dis[t] = dis[u] + 1;
                vis[t] = 1;
                parent[t] = u;
            }
            else if(t != parent[u]){
                ll nodes = dis[u] + dis[t] + 1;
                ans = min(ans, nodes);
            }
        }
    }

    return ans;
}

void solve()
{
    // idea: editorial

// every node theke BFS run kore smallest length er cycle ber kora lagbe
// DFS / multisource dfs kaaj kore na. counter case:
//     1
// 7 8
// 0 1
// 2 1
// 2 3
// 3 4
// 4 5
// 1 5
// 5 6
// 6 1

    // BFS use kore labelwise distance ber kore kora lagbe
    // jodi visited pai then node x er dis ar node y er er dis er sum + 1
    // karon source theke node x hoilo A dis dure
    // ar node y hoilo B dis dure taile source soho ei cycle e node ache A + B + 1 ta

    ll n;
    cin >> n;
    ll m;
    cin >> m;

    for0(i, n) v[i].clear();

    for0(i, m) {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    ll ans = INF;
    for0(i, n) {
        ans = min(ans, BFS(i));
    }

    if(ans == INF) cout << "impossible" << endl;
    else cout << ans << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        fileRead
        fileWrite
    #endif

    FAST
    int tc=1;
    cin>>tc;

    for(int i=1; i<=tc; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
}

