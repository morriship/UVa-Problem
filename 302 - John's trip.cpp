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

int use[2000];
vector<int> path;

vector<pair<int, int> > edge[50];

void trace(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        pair<int, int> tmp = edge[x][i];
        if (!use[tmp.first]) {
            use[tmp.first] = true;
            trace(tmp.second);
            path.push_back(tmp.first);
        }
    }
}

int main() {
    int x, y, z, i, j, n, st;
    while (scanf("%d%d", &x, &y) && x && y) {
        n = 1;
        st = min(x, y);
        rep(i, 50) { edge[i].clear(); }
        scanf("%d", &z);
        edge[x].push_back({z, y});
        edge[y].push_back({z, x});
        while (scanf("%d%d", &x, &y) && x && y) {
            n++;
            scanf("%d", &z);
            edge[x].push_back({z, y});
            edge[y].push_back({z, x});
        }
        rep(i, 50) {
            if (edge[i].size() % 2) { break; }
            sort(edge[i].begin(), edge[i].end());
        }
        if (i < 50) {
            cout << "Round trip does not exist.\n" << endl;
            continue;
        }
        memset(use, 0, sizeof(use));
        path.clear();
        trace(st);
        if (path.size() < n) {
            cout << "Round trip does not exist.\n" << endl;
            continue;
        }
        cout << path[n-1];
        for (i = n-2; i >= 0; i--) { cout << ' ' << path[i]; }
        cout << '\n' << endl;
    }
}
