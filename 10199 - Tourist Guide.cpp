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
#define mod 1000000007
typedef long long ll;
using namespace std;

map<string, int> xmap;
string city[101];
vector<int> edge[101];
set<string> ans;

int dfn[101], low[101], ind;

void tarjan(int now, int parent) {
    int i, y, flag(0);
    dfn[now] = low[now] = ++ind;
    rep(i, edge[now].size()) {
        y = edge[now][i];
        if (!dfn[y]) {
            tarjan(y, now);
            if (low[y] >= dfn[now]) { ans.insert(city[now]); }
            else { low[now] = min(low[now], low[y]); }
        }
        else if (y != parent) { low[now] = min(low[now], dfn[y]); }
    }
}

void solv(int now) {
    int i, y, count(0);
    dfn[now] = low[now] = ++ind;
    rep(i, edge[now].size()) {
        y = edge[now][i];
        if (!dfn[y]) {
            count++;
            tarjan(y, now);
        }
    }
    if (count > 1) { ans.insert(city[now]); }
}

int main() {
    int n, m, i, j, count(0);
    for (cin >> n; n; cin >> n) {
        if (count++) { cout << endl; }
        ans.clear();
        xmap.clear();
        rep(i, n) {
            cin >> city[i];
            xmap[city[i]] = i;
            edge[i].clear();
        }
        cin >> m;
        rep(i, m) {
            string a, b;
            cin >> a >> b;
            edge[xmap[a]].push_back(xmap[b]);
            edge[xmap[b]].push_back(xmap[a]);
        }
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        ind = 0;
        rep(i, n) {
            if (!dfn[i]) { solv(i); }
        }
        cout << "City map #" << count << ": " << ans.size() << " camera(s) found" << endl;
        for (auto c: ans) { cout << c << endl; }
    }
}
