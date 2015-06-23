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

int in[4];

int main() {
    int t, tt, i;
    for (scanf("%d", &tt), t = 1; t <= tt; t++) {
        rep(i, 4) { scanf("%d", &in[i]); }
        in[2] -= in[0];
        in[3] -= in[1];
        in[0] = in[1] = 0;
        in[0] = in[3];
        in[3] = in[2];
        in[2] = 0;
        if (in[0] < 0) {
            in[2] -= in[0];
            in[0] = 0;
        }
        if (in[3] < 0) {
            in[1] -= in[3];
            in[3] = 0;
        }
        cout << "Case " << t << ": " << in[0] << ' ' << in[1] << ' ' << in[2] << ' ' << in[3] << endl;
    }
}
