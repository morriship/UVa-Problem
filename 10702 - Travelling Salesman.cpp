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

int earn[2][101][101];
int ans[2][101][101];

int main() {
    int c, s, e, t, i, j, k;

    while (scanf("%d%d%d%d", &c, &s, &e, &t) && c) {
        memset(ans, 0, sizeof(ans));
        int anow(1), apre(0), enow(1), epre(0), flag(1);
        rep(i, c) rep(j, c) { scanf("%d", &earn[enow][i][j]); }
        while (t) {
            if (t & 1) {
                if (!flag) {
                    swap(anow, apre);
                        rep(i, c) rep(j, c) {
                        int tmp(-1);
                        rep(k, c) { tmp = max(tmp, ans[apre][i][k] + earn[enow][k][j]); }
                        ans[anow][i][j] = tmp;
                    }
                }
                else {
                    flag = 0;
                    rep(i, c) rep(j, c) { ans[anow][i][j] = earn[enow][i][j]; }
                }
            }
            swap(enow, epre);
            rep(i, c) rep(j, c) {
                int tmp(-1);
                rep(k, c) { tmp = max(tmp, earn[epre][i][k] + earn[epre][k][j]); }
                earn[enow][i][j] = tmp;
            }
            t >>= 1;
        }
//        rep(i, c) {
//            rep(j, c) cout << ans[anow][i][j] << ' ' ;
//            cout << endl;
//        }
//        cout << endl;
        int res(-1);
        rep(i, e) {
            int tmp;
            scanf("%d", &tmp);
            res = max(res, ans[anow][s-1][tmp-1]);
//            cout << ans[anow][s-1][tmp-1] << ' ' << s-1 << ' ' << tmp-1 << endl;
        }
        printf("%d\n", res);
    }
}
