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
int a[mx];
ll tree[mx * 3];
 
void build(int node, int b, int e) {
    if (b == e) tree[node] = a[b];
    else {
	int leftNode = 2*node;
	int rightNode = 2*node + 1;
	int mid = (b + e) / 2;
 
	build(leftNode, b, mid);
	build(rightNode, mid+1, e);
 
	tree[node] = 0;
	}
}
 
void update(int node, int b, int e, int l, int r, int add) {
    if (l > r) return;
    if (l == b && e == r) tree[node] += add;
    else {
		int leftNode = 2*node;
		int rightNode = 2*node + 1;
		int mid = (b + e) / 2;
 
        update(leftNode, b, mid, l, min(r, mid), add);
        update(rightNode, mid+1, e, max(l, mid+1), r, add);
    }
}
 
ll get(int node, int b, int e, int pos) {
    if (b == e) return tree[node];
 
    int leftNode = 2*node;
    int rightNode = 2*node + 1;
    int mid = (b + e) / 2;
 
    if (pos <= mid) return tree[node] + get(leftNode, b, mid, pos);
    else return tree[node] + get(rightNode, mid+1, e, pos);
}
 
int main()
{
	int n,q; cin >> n >> q;
	for1(i,n) cin >> a[i];
	build(1, 1, n);
	
	while(q--){
		int x; cin>>x;
		if(x==1){
			int i, j, newvalue; cin>>i>>j>>newvalue;
			update(1, 1, n, i, j, newvalue);
		}
		else{
			int pos; cin>>pos;
			cout<<get(1, 1, n, pos)<<endl;
		}
	}
}
