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
#define mem(arr, b) memset(arr, b, sizeof(arr)) //memset only for -1 and 0
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

#define watch(x) cout << (#x) << " is " << (x) << endl

//-------------------------------------------------------------------

ll fact[20];
void calculateFact(){
	fact[0]=1;
	for1(i,19){
		fact[i] = fact[i-1]*i;
	}
}

void solve()
{
    ll n; cin>>n;
    vll v;
    ll need=n;
    forba(i, 19, 0){
        if(need==fact[i]) {need=0; v.pb(i); break;}
        else if(need>fact[i]) need-=fact[i], v.pb(i);
    }
    sort(all(v));
    if(need==0){
        for0(i,v.sz){
            cout<<v[i]<<"!";
            if(i==v.sz-1) break;
            cout<<"+";
        }
    }
    else cout<<"impossible";
    cout<<endl;
}

int main()
{
    FAST
    int tc=1;
    cin>>tc;
    int testCase = 0;
    calculateFact();
    while(tc--){
        cout<<"Case "<<++testCase<<": ";
        solve();
    }
}
