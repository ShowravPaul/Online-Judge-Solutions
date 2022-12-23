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

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define in insert
#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr)) /// memset only for -1 and 0
/// fill(a, a+n, 5) /// fill for any value

#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);
#define jor(a) !(a&1) /// jor means EVEN number
#define bjor(a) (a&1) /// bjor means ODD number
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
#define endl "\n"

///---------------------------------------------------------------------------------------
/// for debugging

#define printLine() cout << "----------" << endl;

#ifndef ONLINE_JUDGE
#define watch(x) cout << #x <<" = "; _print(x); cout << endl;
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

ll mod = 1e9+7;
const ll N = 100 + 5;
vll g[N];

vll BFS(ll s) {
    queue<ll> q;
    q.push(s);

    vll vis(N);
    vis[s] = 0;

    vll dis(N);
    dis[s] = 0;

    vll parent(N);
    parent[s] = -1;

    while(q.sz) {
        ll u = q.front();
        q.pop();

        for(auto child : g[u]) {
            if(child != parent[u]) {
                if(vis[child] == 0) {
                    q.push(child);
                    vis[child] = 1;
                    parent[child] = u;
                    dis[child] = dis[u] + 1;
                }
            }
        }
    }

    return dis;
}

void solve()
{

    // idea: i theke s koto dur? i theke d kotodur? eivabe sob i er distance ber korbo. then max tai ans!
    // idea from: https://github.com/rafi-kamal/ACM-Solutions/blob/master/LightOj/Graph%20Theory/1174%20-%20Commandos.cpp

    ll n;
    cin >> n;
    ll m;
    cin >> m;

    // clear
    for0(i, n) g[i].clear();

    for0(i, m) {
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    ll s, d;
    cin >> s >> d;

    vll dis1 = BFS(s);
    vll dis2 = BFS(d);

    ll ans = 0;
    for0(i, n) ans = max(ans, dis1[i] + dis2[i]);

    cout << ans << endl;
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
