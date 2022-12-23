#include <bits/stdc++.h>
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
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, int> mli;
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
#define sqr(a) ((a) *(a))
#define jor(a) !(a & 1)	// jor means EVEN number
#define bjor(a) (a & 1)	// bjor means ODD number
#define all(a) a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr))	//memset only for -1 and 0
//fill(a, a+n, 5)	//fill for any value
#define for0(i, b) for (int i = 0; i < (b); i++)
#define for1(i, b) for (int i = 1; i <= (b); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)
#define forba(i, b, a) for (int i = (b); i >= (a); i--)
#define rep(i, a, b, c) for (int i = (a); i != (b); i += (c))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);
void print(int a[], int n)
{
	// for testing or debugging
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
}

///----------------------------------------------------------------------------------

void solve(){
    int n,m; cin>>n>>m;
    deque<int>dq; int u=0;
    while(1){ if(u==m) break;
         u++;
        string s; cin>>s;

        if(s=="pushLeft"){
            int x; cin>>x;
            if(dq.sz==n) cout<<"The queue is full";
            else{
                cout<<"Pushed in left: "<<x;
                dq.push_front(x);
            }
        }
        else if(s=="pushRight"){
            int x; cin>>x;
            if(dq.sz==n) cout<<"The queue is full";
            else{
                cout<<"Pushed in right: "<<x;
                dq.push_back(x);
            }
        }
        else if(s=="popLeft"){
            if(dq.empty()) cout<<"The queue is empty";
            else{
                cout<<"Popped from left: "<<dq.front();
                dq.pop_front();
            }
        }
        else if(s=="popRight"){
            if(dq.empty()) cout<<"The queue is empty";
            else{
                cout<<"Popped from right: "<<dq.back();
                dq.pop_back();
            }
        }

        cout<<endl;
    }
}

int main()
{
    //fileRead;
    int tc; cin>>tc;
    int t=1;
    while(tc--){
        cout<<"Case "<<t++<<":\n";
        solve();
    }
}

