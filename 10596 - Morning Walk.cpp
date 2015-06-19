#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

vector<int> edge[201];
int use[201];

void trace(int now) {
    use[now] = 1;
    for (int i = 0; i < edge[now].size(); i++) {
        if (!use[edge[now][i]]) { trace(edge[now][i]); }
    }
}

int main() {
    int x, y, n, r, i, j, k;

    while (~scanf("%d%d", &n, &r)) {
        if (!r) {
            cout << "Not Possible" << endl;
            continue;
        }
        memset(use, 0, sizeof(use));
        rep(i, n) { edge[i].clear(); }
        rep(i, r) {
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        rep(i, n) if (edge[i].size()) {
            trace(i);
            rep(j, n) if (!use[j] && edge[j].size() || edge[j].size() % 2) {
                cout << "Not Possible" << endl;
                break;
            }
            if (j >= n) { cout << "Possible" << endl; }
            break;
        }
    }
}
