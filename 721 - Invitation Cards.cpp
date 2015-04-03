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

vector<pair<int, int> > edge[1000001];
vector<pair<int, int> > iedge[1000001];
ll dist[1000001];
int inque[1000001];

int spfa(vector<pair<int, int> > *edge, int p) {
    int ret(0), i, x, y;
    queue<int> que;
    que.push(1);
    inque[1] = 1;
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    while (!que.empty()) {
        x = que.front();
        que.pop();
        inque[x] = 0;
        rep(i, edge[x].size()) {
            y = edge[x][i].first;
            if (!~dist[y] || dist[y] > dist[x] + edge[x][i].second) {
                dist[y] = dist[x] + edge[x][i].second;
                if (!inque[y]) {
                    inque[y] = 1;
                    que.push(y);
                }
            }
        }
    }
    xrep(i, 1, p+1) { ret += dist[i]; }
    return ret;
}

int main() {
    int n, p, q, i, x, y, val, ans(0);
    for (cin >> n; n; n--) {
        scanf("%d%d", &p, &q);
        rep(i, p+1) {
            edge[i].clear();
            iedge[i].clear();
        }
        rep(i, q) {
            scanf("%d%d%d", &x, &y, &val);
            edge[x].push_back(make_pair(y, val));
            iedge[y].push_back(make_pair(x, val));
        }
        ans = spfa(edge, p);
        ans += spfa(iedge, p);
        cout << ans << endl;
    }
}
