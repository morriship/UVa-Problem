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

int ans[100101];

int main() {
    int i, t, n;
    memset(ans, 0, sizeof(ans));
    for (int i = 99999; i > 0; i--) {
        int tmp(i), sum(i);
        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        ans[sum] = i;
    }

    for (cin >> t; t; t--) {
        cin >> n;
        cout << ans[n] << endl;
    }
}
