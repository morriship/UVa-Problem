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

int cmp(const int &a, const int &b) { return a > b; }

int in[10001];

int main() {
    int n, i, j;

    while (scanf("%d", &n) && n) {
        memset(in, 0, sizeof(in));
        rep(i, n) { scanf("%d", &in[i]); }
        sort(in, in+n, cmp);
        if (in[n-1] < 0) {
            cout << "Not possible" << endl;
            continue;
        }
        while (in[0] > 0) {
            xrep(i, 1, in[0]+1) {
                if (in[i] <= 0) { break; }
                in[i]--;
            }
            if (i <= in[0]) break;
            in[0] = 0;
            sort(in, in+n, cmp);
            while (n && !in[n-1]) { n--; }
        }
        if (in[0]) { cout << "Not possible" << endl; }
        else { cout << "Possible" << endl; }
    }
}
