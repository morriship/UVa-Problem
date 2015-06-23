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

char in[1010];
int use[300];

int main() {
    int t, tt, i, j, k, ans, count;

    for (scanf("%d", &tt), t = 1; t <= tt; t++) {
        scanf("%s", in);
        for (i = ans = 0; in[i]; i++) {
            count = 0;
            memset(use, 0, sizeof(use));
            ans++;
            use[in[i]] = 1;
            count = 1;
            for (j = i-1, k = i+1; j >= 0 && in[k]; j--, k++) {
                if (use[in[j]] % 2) { count--; }
                else { count++; }
                use[in[j]]++;
                if (use[in[k]] % 2) { count--; }
                else { count++; }
                use[in[k]]++;
                if (count < 2) { ans++; }
            }
            memset(use, 0, sizeof(use));
            count = 0;
            for (j = i, k = i+1; j >= 0 && in[k]; j--, k++) {
                if (use[in[j]] % 2) { count--; }
                else { count++; }
                use[in[j]]++;
                if (use[in[k]] % 2) { count--; }
                else { count++; }
                use[in[k]]++;
                if (count < 2) { ans++; }
            }
        }
        cout << "Case " << t << ": " << ans << endl;
    }
}
