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
#define sqr(a)((a) *(a))
#define jor(a) !(a & 1) // jor means EVEN number
#define bjor(a)(a & 1)  // bjor means ODD number
#define all(a) a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr)) //memset only for -1 and 0
//fill(a, a+n, 5)   //fill for any value
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
    string visit="VISIT", backward="BACK", forward="FORWARD", quit="QUIT";
    stack<string> stackBackward, stackForward;
    stackBackward.push("http://www.lightoj.com/");
    string s;
    while(cin>>s)
    {
        if(s==quit) break;
        else if(s==visit){
            string url;
            cin>>url;
            stackBackward.push(url);
            cout<<url;
            while(!stackForward.empty()) stackForward.pop();
        }
        else if(s==forward){
            if(stackForward.sz == 0) cout<<"Ignored";
            else{
                string top = stackForward.top();
                cout<<top;
                stackBackward.push(top);
                stackForward.pop();
            }
        }
        else if(s==backward){
            if(stackBackward.sz==1) cout<<"Ignored";
            else{
                string top = stackBackward.top();
                stackForward.push(top);
                stackBackward.pop();
                cout<<stackBackward.top();
            }
        }
        cout<<endl;
    }
}
 
int main()
{
    //IOS;
    //fileRead;
    int tc; cin>>tc;
    int t=1;
    while(tc--){
        cout<<"Case "<<t++<<":\n";
        solve();
    }
}
