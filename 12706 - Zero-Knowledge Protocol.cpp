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

map<int, int> xmap;
int s[20010], p[20010];

int main() {
    int t, n, m, in, ind, count, i;
    ll ans, score;

    for (cin >> t; t; t--) {
        cin >> n >> m;
        xmap.clear();
        memset(p, 0, sizeof(p));
        ans = ind = count = 0;

        rep(i, n) {
            scanf("%d", &in);
            if (xmap.find(in) == xmap.end()) { xmap[in] = ind++; }
            s[i] = xmap[in];
        }
        rep(i, m) {
            scanf("%d", &in);
            if (xmap.find(in) == xmap.end()) { break; }
            p[xmap[in]]++;
        }
        if (i < m || n < m) {
            for (i++; i < m; i++) { scanf("%d", &in); }
            cout << 0 << endl;
            continue;
        }

        rep(i, m) {
            int &tmp = s[i];
            p[tmp]--;
            if (p[tmp] < 0) { count++; }
        }
        score = 2;
        if (!count) { ans++; }
        xrep(i, m, n) {
            int &tmp = s[i];
            p[tmp]--;
            if (p[tmp] < 0) { count++; }
            int &tmp2 = s[i-m];
            p[tmp2]++;
            if (p[tmp2] <= 0) { count--; }
            if (!count) { ans += score * score; }
            score++;
        }
        cout << ans << endl;
    }
}
