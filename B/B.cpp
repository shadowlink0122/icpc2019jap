#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz size()
#define endl "\n"
#define print(X) cout << (X) << "\n"
// // #define input(X) getline(cin,X)
static const ll  INF = 1e9+7;
static const ll INFL = 1e18+7;
ll n,m,l, p;
string s,t;
ll d[200010],e[200010],dp[1001][1001];
char field[202][202];

int x = 0,y = 0;

P get(char c){
	P ans = {0, 0};
	rep(i,0,n){
		rep(j,0,m){
			if(field[i][j] == c)return P{i, j};
		}
	}
	return ans;
}

int calc(P point){
	int ans = abs(x-point.first)+abs(y-point.second) + 1;

	x = point.first;
	y = point.second;
	return ans;
}

int solve(){
	int ans = 0;
	rep(i,0,s.sz){
		P point = get(s[i]);
		ans += calc(point);
	}
	return ans;
}

int main(){
	while(cin >> n >> m, n){
		int ans = 0;
		x = y = 0;

		rep(i,0,n)cin >> field[i];
		cin >> s;
		print(solve());
	}
	return 0;
}

