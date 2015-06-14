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

string str;

int main() {
    int t, tt, start;
    ll ans;
    cin >> t;
    for (tt = 1; tt <= t; tt++) {
        cin >> str;
        ans = 0;
        start = str.length() / 2 - 1;
        if (str.length() & 1) { ans = str[start+1] - '0'; }
        while (start >= 0) {
            ans <<= 1;
            ans += max(str[start], str[str.length()-start-1]) - '0';
            ans <<= 1;
            ans += min(str[start], str[str.length()-start-1]) - '0';
            start--;
            ans %= mod;
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
}
