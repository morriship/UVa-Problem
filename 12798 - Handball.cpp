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


int main() {
    int ans, n, m, flag, i, j, tmp;
    while (~scanf("%d%d", &n, &m)) {
        ans = 0;
        rep(i, n) {
            flag = 1; 
            rep(j, m) {
                scanf("%d", &tmp);
                if (!tmp) { flag = 0; }
            }
            ans += flag;
        }
        cout << ans << endl;
    }
}
