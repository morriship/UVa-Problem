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

int ch[300];
string in;

void init() { ch['A'] = 0, ch['C'] = 1, ch['G'] = 2, ch['T'] = 3; }

int main() {
    int n, ans, i, j, k, inl;
    init();

    for (cin >> n; n; n--) {
        cin >> in;
        ans = 0;
        inl = in.length();
        xrep(i, 1, inl) {
            if (ch[in[ans]] > ch[in[i]]) { ans = i; }
            else if (ch[in[ans]] == ch[in[i]]) {
                for (j = (ans+1)%inl, k = (i+1)%inl; j != ans; j = (j+1)%inl, k = (k+1)%inl) {
                    if (ch[in[j]] != ch[in[k]]) { break; }
                }
                if (ch[in[j]] > ch[in[k]]) { ans = i; }
            }
        }
        cout << in[ans];
        for (i = (ans+1)%inl; i != ans; i = (i+1)%inl) { cout << in[i]; }
        cout << endl;
    }
}
