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
#define mem(arr, b) memset(arr, b, sizeof(arr))
/// memset only for -1 and 0
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
const double pi = acos(-1.0);
const long long INF = 2e18;
 
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
const ll N = 100005;
ll n, m;
vll g[N];
ll parent[N];
ll vis[N];
ll first = -1, last = -1;
 
void DFS(ll s, ll p) { // main idea: ami jodi dekhi visited, taile dekhbo eita amr ancestor kina? mane path ei ahce kina? hoile cycle ache.
    vis[s] = 1;
    parent[s] = p;
 
    for(auto t : g[s]) {
        if(first != -1) return; // jodi peye jai
 
        // if(t != p) { // asole eikhane parent check er dorkar nai. karon 1 -> 2 and 2 -> 1 hoite pare. ar sob do directed e. tai no prob!
            if(vis[t] == 0) DFS(t, s);
            else if(vis[t] == 1) {
                first = t;
                last = s;
                return;
            }
            else if(vis[t] == 2) continue;
        // }
    }
 
    vis[s] = 2; // sob node visit kora sesh
}
 
void solve()
{
    cin >> n >> m;
    for0(i, m) {
        ll x, y; cin >> x >> y;
        g[x].pb(y);
    }
 
    for1(i, n) {
        if(vis[i] == 0) {
            DFS(i, -1);
            if(first != -1) break;
        }
    }
 
    // watch(first) watch(last)
 
    if(first == -1) cout << "IMPOSSIBLE" << endl;
    else {
        vll ans;
        ll x = last;
        while(x != parent[first]) { // x != -1 hobe na, last theke back korte korte first porjonoto asbo. 2 vabe korte pari. first porjonot ese break then ans.pb(first). or first er parent porjonto loop colbe.
            ans.pb(x);
            x = parent[x];
        }
        // ans.pb(first);
        ans.pb(last);
        reverse(all(ans));
        cout << ans.sz << endl;
        for(auto t : ans) cout << t << " ";
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        fileRead
        fileWrite
    #endif
 
    FAST
    int tc=1;
    // cin>>tc;
 
    for(int i=1; i<=tc; i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
