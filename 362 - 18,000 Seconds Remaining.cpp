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


int main() {
    int i, j, n, t(0), sum, val, remain;
    for (scanf("%d", &n); n; scanf("%d", &n)) {
        printf("Output for data set %d, %d bytes:\n", ++t, n);
        sum = 0;
        remain = n;
        for (i = 1; remain; i++) {
            scanf("%d", &val);
            sum += val;
            remain -= val;
            if (i % 5 == 0) {
                if (!sum) { puts("   Time remaining: stalled"); }
                else { printf("   Time remaining: %d seconds\n", (remain*5)/sum + (remain*5%sum!=0)); }
                sum = 0;
            }
        }
        printf("Total time: %d seconds\n\n", i-1);
    }
}
