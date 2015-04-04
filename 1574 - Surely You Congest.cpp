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

struct Node {
    int val, can, y, rev;

    void set(int _y, int _val, int _can, int _rev) {
        y = _y;
        val = _val;
        can = _can;
        rev = _rev;
    }

    Node ch() { can ^= 1; }
};
 
multimap<int, int> dmap;
vector<Node> edge[25001], temp[25001];
int dist[25001], n;
bitset<25001> inque;
multiset<int> target;
int pre[25001], cars[1001];
 
void spfa() {
    int i, x;
    queue<int> que;
    inque.reset();
    memset(dist, 0x2f, sizeof(dist));
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        x = que.front();
        que.pop();
        inque[x] = false;
        rep(i, edge[x].size()) {
            Node y = edge[x][i];
            if (dist[x] + y.val < dist[y.y]) {
                dist[y.y] = dist[x] + y.val;
                if (!inque[y.y]) {
                    inque[y.y] = true;
                    que.push(y.y);
                }
            }
        }
    }
}

void rebuild() {
    int i, j;
    Node node;
    rep(i, n) {
        rep(j, edge[i].size()) {
            node = edge[i][j];
            if (dist[node.y] + node.val == dist[i]) {
                int rev = node.y;
                node.rev = temp[node.y].size();
                node.can = 0;
                temp[i].push_back(node);
                node.rev = temp[i].size() - 1;
                node.y = i;
                node.val = -node.val;
                node.can = 1;
                temp[rev].push_back(node);
            }
        }
    }
    rep(i, n) { edge[i] = temp[i]; }
}
 
void reset() {
    int i;
    rep(i, n) { edge[i] = temp[i]; }
}

int bfs() {
    int i, j, k, x;
    Node node;
    queue<int> que;
    que.push(0);
    memset(pre, -1, sizeof(pre));

    while (!que.empty()) {
        x = que.front();
        que.pop();
        rep(i, edge[x].size()) {
            node = edge[x][i];
            if (node.can && !~pre[node.y]) {
                pre[node.y] = node.rev;
                if (target.find(node.y) != target.end()) {
                    target.erase(target.find(node.y));
                    return node.y;
                }
                que.push(node.y);
            }
        }
    }
    return 0;
}

int maxFlow() {
    int res, ret(0);

    if (target.size() == 1) { return 1; }
    Node node;
    reset();
    while (res = bfs()) {
        ret++;
        while (res) {
            node = edge[res][pre[res]];
            edge[res][pre[res]].can ^= 1;
            edge[node.y][node.rev].can ^= 1;
            res = node.y;
        }
    }
    return ret;
}
 
int main() {
    int m, c, i, x, y, t, val, ans;
    while (~scanf("%d%d%d", &n, &m, &c)) {
        Node node;
        rep(i, n) {
            edge[i].clear();
            temp[i].clear();
        }

        rep(i, m) {
            scanf("%d%d%d", &x, &y, &t);
            node.set(y-1, t, 1, edge[y-1].size());
            edge[x-1].push_back(node);
            node.set(x-1, t, 1, edge[x-1].size()-1);
            edge[y-1].push_back(node);
        }

        rep(i, c) {
            scanf("%d", &cars[i]);
            --cars[i];
        }

        spfa();
        rebuild();

        dmap.clear();
        ans = 0;
        rep(i, c) {
            if (!cars[i]) { ans++; }
            else { dmap.insert(make_pair(dist[cars[i]], cars[i])); }
        }

        target.clear();
        val = dmap.begin()->first;
        multimap<int, int>::iterator it;
        for(it = dmap.begin(); it != dmap.end(); it++) {
            if ((*it).first != val) {
                ans += maxFlow();
                target.clear();
                val = (*it).first;
            }
            target.insert((*it).second);
        }
        if (target.size()) { ans += maxFlow(); }
        cout << ans << endl;
    }
}
