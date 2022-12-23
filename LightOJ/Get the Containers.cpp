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
	ll n; cin>>n; 
	ll c; cin>>c;
	ll a[n]; for0(i,n) cin>>a[i];
	
	ll mx = *max_element(a,a+n);
	ll L=mx, R=2e9, ans=0; // ans mx and 2e9 er moddhe thakbe, min container size hobe max size er element er soman
	
	while(L<=R){
		ll mid = (L+R)/2;
		// can mid be an ans? check it!
		// check how many container we need if mid is the size of a container
		
		ll tem = 0;
		ll x = 1;
		for0(i,n){
			if(tem+a[i] <= mid){
				tem += a[i];
			}
			else x++, tem=a[i];
		}
		
		if(x<=c){
			ans = mid;
			R = mid-1;
		}
		else if(x>c) L = mid+1;
	}
	
	cout<<ans<<endl;
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
