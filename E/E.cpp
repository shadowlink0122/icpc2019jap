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

char piece[6][8][10][10];
char box[10][10][10];

void init(){
    // memset(piece, 0, sizeof(piece));
    // memset(box, 0, sizeof(box));
    rep(i,0,6)
        rep(j,0,8)
            rep(x,0,10)
                rep(y,0,10)
                    piece[i][j][x][y] = 'N';

    rep(j,0,10)
        rep(x,0,10)
            rep(y,0,10)
                box[j][x][y] = 'N';
}

void printAfterInput(char p[10][10]){
  puts("==================");
  rep(i,0,n){
    rep(j,0,n){
      cout << p[i][j];
    }
    puts("");
  }
}

void lotate(char p[10][10], int index,int pn){
    if(index == 8)return;
    rep(x,0,n){
        rep(y,0,n){
            piece[pn][index][y][n-x-1] = p[x][y];
        }
    }
    lotate(piece[pn][index], index+1, pn);
}

void flip(int index, int pn){
    // printf("index:%d, pn=%d\n",index,pn);
    if(index == 8)return;
    rep(x,0,n){
        rep(y,0,n/2){
            swap(piece[pn][index][x][y], piece[pn][index][x][n-y-1]);
        }
    }
    flip(index+1, pn);
}

void input(){
    rep(i,0,6){
        char p[10][10];
        rep(y,0,n){
            scanf("%s",p[y]);
        }
        // printAfterInput(p);
        lotate(p, 0, i);
        flip(4, i);
    }
}

void getPiece(char p[10][10], int pi, int state){
    rep(x,0,n){
        rep(y,0,n){
            assert(piece[pi][state][x][y] == 'X' || piece[pi][state][x][y] == '.');
            p[x][y] = piece[pi][state][x][y];
            assert(p[x][y] == 'X' || p[x][y] == '.');
        }
    }
}

void getPoint(int *xa, int *ya,int *za, int *xb, int *yb,int *zb, int sf){
    sf += 1;

    switch(sf){
        case 1:
            *xa = 0, *ya = 0, *za = 0;
            *xb = n, *yb = n, *zb = 0+1;
            break;
        case 2:
            *xa = 0, *ya = 0, *za = 0;
            *xb = 0+1, *yb = n, *zb = n;
            break;
        case 3:
            *xa = 0, *ya = 0, *za = n-1;
            *xb = n, *yb = n, *zb = n;
            break;
        
        case 4:
            *xa = n-1, *ya = 0, *za = 0;
            *xb = n, *yb = n, *zb = n;
            break;
        case 5:
            *xa = 0, *ya = n-1, *za = 0;
            *xb = n, *yb = n, *zb = n;
            break;
        case 6:
            *xa = 0, *ya = 0, *za = 0;
            *xb = n, *yb = 0+1, *zb = n;
            break;
    }
}

void out(int xa, int ya, int za, int xb, int yb, int zb){
    puts("");

    rep(x,xa,xb){
        rep(y,ya,yb){
            rep(z,za,zb){
                cout << box[x][y][z];
            }
        }
        puts("");
    }
}

bool check(){
    int xa, ya, za;
    int xb, yb, zb;
    rep(i,0,6){
        getPoint(&xa, &ya, &za, &xb, &yb, &zb, i);
        // out(xa,ya,za,xb,yb,zb);
        rep(x, xa, xb)
            rep(y,ya, yb)
                rep(z, za, zb)
                    if(box[x][y][z] != 'X')return false;
    }

    return true;
}

bool setting(int pi, int state, int sf){
    char p[10][10];
    int xa, ya, za;
    int xb, yb, zb;
    getPiece(p, pi, state);
    getPoint(&xa, &ya, &za, &xb, &yb, &zb, sf);

    puts("Setting");
    bool st = true;

    rep(x, xa, xb){
        rep(y,ya, yb){
            rep(z, za, zb){
                printf("%c:%c, ",box[x][y][z], p[x][y]);
                if(box[x][y][z] == 'X' && p[x][y] == 'X')
                    st = false;
            }
        }
    }
    puts("");
    if(!st)return st;
    // ok
    rep(x, xa, xb)
        rep(y,ya, yb)
            rep(z, za, zb){
                assert(p[x][y] == 'X' || p[x][y] == '.');
                if(p[x][y] == 'X')box[x][y][z] = p[x][y];
            }
    return true;
}

void undo(int pi, int state, int sf){
    char p[10][10];
    int xa, ya, za;
    int xb, yb, zb;
    getPiece(p, pi, state);
    getPoint(&xa, &ya, &za, &xb, &yb, &zb, sf);

    rep(x, xa, xb)
        rep(y,ya, yb)
            rep(z, za, zb)
                if(p[x][y] == 'X'){
                    box[x][y][z] = 'N';
                }
}

bool dfs(int depth){
    if(depth > 5){
        return check();
    }
    rep(state,0,8){ // which state
        rep(place,0,6){ // which place
            printf("depth:%d, State:%lld, place:%lld\n",depth+1, state+1, place+1);
            if(setting(depth, state, place)){
                if(dfs(depth+1))return true;
                undo(depth, state, place);
            }
        }
    }
    return false;
}

void printPiece(){
  rep(i,0,6){// num pf piece
    puts("=============================");
    cout << "piece:" << i+1 << endl;
    rep(j,0,8){// num of state
      cout << "State:" << j+1 << endl;
      rep(x,0,n){
        rep(y,0,n){
          cout << piece[i][j][x][y];
        }
        puts("");
      }
    }
  }
}

int main() {
    while(cin >> n,n){
        init();
        input();
        // printPiece();
        cout << (dfs(0) ? "Yes" : "No") << endl;
    }
    return 0;
}

