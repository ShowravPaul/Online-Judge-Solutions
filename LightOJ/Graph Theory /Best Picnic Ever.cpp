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

vector<ll> v[1000 + 5];
ll places[1005];

void BFS(ll s) {
    queue<ll> q;
    q.push(s);

    ll vis[1000 + 5] = {};
    vis[s] = 1;

    while(q.sz) {
        ll u = q.front();
        q.pop();
        places[u]++;

        for(auto x : v[u]) {
            if(vis[x] == 0) {
                q.push(x);
                vis[x] = 1;
            }
        }
    }
}

void solve()
{
    ll k, n, m;
    cin >> k >> n >> m;

    // clear
    for1(i, n) v[i].clear();
    for1(i, n) places[i] = 0;

    sll SET;
    for1(i, k) {
        ll x;
        cin >> x;
        SET.insert(x);
    }

    for1(i, m) {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
    }

    // node: sobai ekta node e thakte pare!
//     consider this Case:
// 1
// 3 5 4
// 1
// 1
// 1
// 1 2
// 1 4
// 2 3

    // idea: 1st person kotogula jaygay jaite pare sob mark korbo
    // 2nd person koto jaygay jaite pare mark korbo
    // eivabe sob person er jnno korbo. last e dekhbo mark kora place gulate koyta te k jon e jaite pare?
    // complexity: O(k*node)

    for(auto t : SET) {
        BFS(t);
    }

    ll ans = 0;
    for1(i, n) if(places[i] == SET.sz) ans++;

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

