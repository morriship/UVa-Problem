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

int in[51];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int cmp(const int &a, const int &b) { return a > b; }

int main() {
    int n, t, i, j, k, l, now, a, b;
    for (cin >> n >> t; n; cin >> n >> t) {
        rep(i, n) { scanf("%d", in+i); }
        sort(in, in+n, cmp);
        while (t--) {
            int val;
            a = 0, b = INF;
            scanf("%d", &val);
            rep(i, n-3) xrep(j, i+1, n-2) xrep(k, j+1, n-1) xrep(l, k+1, n) {
                int tmp(in[i]);
                tmp *= in[j] / gcd(tmp, in[j]);
                tmp *= in[k] / gcd(tmp, in[k]);
                tmp *= in[l] / gcd(tmp, in[l]);
                int res = (val/tmp)*tmp;
                a = max(a, res);
                if (res == val) { b = val; }
                else { b = min(b, res+tmp); }
            }
            cout << a << ' ' << b << endl;
        }
    }
}
