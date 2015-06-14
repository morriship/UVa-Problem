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

int origin[101][101];
int ans[101][101];
int stru[11][11];

int main() {
    int t, tt, n, m, q, r, fq, fr, k, l, i, j;
    cin >> tt;
    xrep(t, 1, tt+1) {
        cin >> n >> m;
        memset(ans, 0, sizeof(ans));
        rep(i, n) rep(j, m) { cin >> origin[i][j]; }
        cin >> q >> r;
        fq = q/2;
        fr = r/2;
        rep(i, q) rep(j, r) { cin >> stru[i][j]; }
        rep(i, n) rep(j, m) {
            if (origin[i][j]) {
                rep(k, q) rep(l, r) {
                    int x(k+i-fq), y(l+j-fr);
                    if (x >= 0 && x < n && y >=0 && y < m) { ans[k+i-fq][l+j-fr] |= stru[k][l]; }
                }
            }
        }
        cout << "Case " << t << ":" << endl;
        rep(i, n) {
            cout << ans[i][0];
            xrep(j, 1, m) { cout << ' ' << ans[i][j]; }
            cout << endl;
        }
    }
}
