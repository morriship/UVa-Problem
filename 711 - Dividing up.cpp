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

int in[7];
bitset<200> bs;

int main() {
    int i, j, sum, t(1);
    while (cin >> in[1]) {
        bs.reset();
        sum = in[1];
        xrep(i, 2, 7) {
            cin >> in[i];
            sum += in[i] * i;
        }
        if (!sum) { break; }
        cout << "Collection #" << t++ << ':' << endl;
        if (sum % 2) { cout << "Can't be divided." << endl; }
        else {
            xrep(i, 1, 7) {
                if (in[i] > 13) {
                    sum -= (in[i] - 12 - (in[i]&1)) * i;
                    in[i] = 12 + (in[i]&1);
                }
            }
            sum >>= 1;
            rep(i, 7) {
                for (; in[i]; in[i]--) {
                    bs |= bs << i;
                    bs[i] = 1;
                }
            }
            if (bs[sum]) { cout << "Can be divided." << endl; }
            else { cout << "Can't be divided." << endl; }
        }
        cout << endl;
    }
}
