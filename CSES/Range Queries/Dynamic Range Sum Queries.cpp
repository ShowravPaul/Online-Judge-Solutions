#include<bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef set<int> si;
typedef set<ll> sll;
 
const double pi = acos(-1.0);
const ll INF = 2e18;
const int MAX_NUM=2e9;
 
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
 
 
//______________________________________________________\\
 
#define mx 200001
int arr[mx];
ll tree[mx * 3];
 
void init(int node, int b, int e)
{
	if (b == e) {
		tree[node] = arr[b];
		return;
	}
	
	int Left = node * 2;
	int Right = node * 2 + 1;
	int mid = (b + e) / 2;
	init(Left, b, mid);
	init(Right, mid + 1, e);
	tree[node] = tree[Left] + tree[Right];
}
 
ll query(int node, int b, int e, int i, int j)
{
	if (i > e || j < b) return 0;
	if (b >= i && e <= j) return tree[node];
	
	int Left = node * 2;
	int Right = node * 2 + 1;
	int mid = (b + e) / 2;
	ll p1 = query(Left, b, mid, i, j);
	ll p2 = query(Right, mid + 1, e, i, j);
	
	return p1 + p2;
}
 
void update(int node, int b, int e, int i, int newvalue)
{
	if (i > e || i < b) return; 
	
	if (b==e) { 
		tree[node] = newvalue; 
		return;
	}
	
	int Left = node * 2;
	int Right = node * 2 + 1;
	int mid = (b + e) / 2;
	update(Left, b, mid, i, newvalue);
	update(Right, mid + 1, e, i, newvalue);
	tree[node] = tree[Left] + tree[Right];
}
 
int main()
{
	int n,q; cin >> n >> q;
	for1(i,n) cin >> arr[i];
	init(1, 1, n);
	
	while(q--){
		int x; cin>>x;
		if(x==1){
			int i, newvalue; cin>>i>>newvalue;
			update(1, 1, n , i, newvalue);
		}
		else{
			int l,r; cin>>l>>r;
			cout<<query(1, 1, n, l, r)<<endl;
		}
	}
}
