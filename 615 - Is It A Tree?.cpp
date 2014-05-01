#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-10)
#define two(a) (1<<(a))
#define lshift(a,b) (a<<b)
#define rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

map<int, int> xmap;
vector<int> edge[10000];
int use[10000];
int len;

void addEdge(int x, int y) {
    if (!xmap[x]) {
        xmap[x] = len;
        edge[len++].clear();
    }
    if (!xmap[y]) {
        xmap[y] = len;
        edge[len++].clear();
    }
    edge[xmap[x]].push_back(xmap[y]);
}

int find(int x, int parent) {
    int i,y;
    use[x] = 1;
    for (i = 0; i < edge[x].size(); i++) {
        y = edge[x][i];
        if (use[y]) { return 1; }
        if (find(y, x)) { return 1;}
    }
    return 0;
}

int main() {
    int fault,i,j,x,y,num(0),ans;
    for (cin >> x >> y; ~x ; cin >> x >> y) {
        if (!(x || y)) {
            cout << "Case " << ++num << " is a tree." << endl;
            continue;
        }
        xmap.clear();
        len = 1;
        do {
            addEdge(x, y);
            cin >> x >> y;
        } while (x || y);
        ans = 0;
        for (i = 1; i < len; i++) {
            memset(use, 0, sizeof(use));
            fault = find(i, -1);
            for (j = 1; j < len; j++) {
                if (!use[j]) {
                    fault++;
                }
            }
            if (!fault) {
                ans = 1;
            }
        }
        if (ans == 1) { cout << "Case " << ++num << " is a tree." << endl; }
        else { cout << "Case " << ++num << " is not a tree." << endl; }
    }
}
