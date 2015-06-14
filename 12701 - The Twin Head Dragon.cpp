#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define min(a,b) ( a < b ? a : b )
#define max(a,b) ( a > b ? a : b )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

int _index[15][15];
vector<pair<int, int> > edge[15];
int use[15], n;
double dp[two(13)];

void go(int now, int num, int sum, int s, double ori_val) {
    int i, j, ind;
    rep(i, edge[now].size()) {
        auto &y = edge[now][i];
        ind = two(_index[now][y.first]);
        if (!(ind & s)) {
            dp[s|ind] = min(dp[s|ind], ori_val + double(sum+y.second)/double(num+1));
            go(y.first, num+1, sum+y.second, s|ind, ori_val);
        }
    }
}

int main() {
    int i, j, x, y, w;
    for (scanf("%d", &n); n; scanf("%d", &n)) {
        rep(i, n) { edge[i].clear(); }
        rep(i, n-1) {
            scanf("%d%d%d", &x, &y, &w);
            edge[x].push_back({y, w});
            edge[y].push_back({x, w});
            _index[x][y] = _index[y][x] = i;
        }
        rep(i, two(n-1)) { dp[i] = 1e30; }
        dp[0] = 0;
        rep(i, two(n-1)) {
            rep(j, n) { go(j, 0, 0, i, dp[i]); }
        }
        printf("%.4lf\n", dp[two(n-1)-1] + EPS);
    }
}
