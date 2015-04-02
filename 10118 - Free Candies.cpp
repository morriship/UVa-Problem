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
#define LIMIT 100000000
typedef long long ll;
using namespace std;


int dp[41][41][41][41];
int in[4][41];

pair<int, int> check(int i, int j, int k, int l) {
    if (i && dp[i-1][j][k][l] < LIMIT) { return make_pair(in[0][i], dp[i-1][j][k][l]); }
    if (j && dp[i][j-1][k][l] < LIMIT) { return make_pair(in[1][j], dp[i][j-1][k][l]); }
    if (k && dp[i][j][k-1][l] < LIMIT) { return make_pair(in[2][k], dp[i][j][k-1][l]); }
    if (l && dp[i][j][k][l-1] < LIMIT) { return make_pair(in[3][l], dp[i][j][k][l-1]); }
    return make_pair(-1, -1);
}

int main() {
    int i, j, k, l, n, ans;
    for (cin >> n; n; cin >> n) {
        ans = 0;
        rep(i, n) rep(j, 4) { cin >> in[j][i+1]; }
        memset(dp, 0x2f, sizeof(dp));
        dp[0][0][0][0] = 0;
        ++n;
        rep(i, n) rep(j, n) rep(k, n) rep(l, n) {
            pair<int, int> p = check(i, j, k, l);
            if (!~p.first) { continue; }
            int val(p.first), now(p.second), res(0), flag(0), count(0);
            while (now) {
                int temp = now % 100;
                now /= 100;
                if (val != temp) {
                    res = res * 100 + temp;
                    count++;
                }
                else { flag = true; }
            }
            if (!flag) { res = res * 100 + val; }
            dp[i][j][k][l] = res;
            ans = max(ans, (i+j+k+l-count+(flag-1))>>1);
        }
        cout << ans << endl;
    }
}
