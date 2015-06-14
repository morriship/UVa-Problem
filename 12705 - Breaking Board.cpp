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

int rank[] = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
char in[150];
int num[300];

int main() {
    int t, i, j, now, count, ans;
    cin >> t;
    cin.getline(in, 150);
    rep(i, t) {
        cin.getline(in, 150);
        memset(num, 0, sizeof(num));
        for (j = 0; in[j]; j++) {
            if (in[j] != ' ') { num[in[j]]++; }
        }
        sort(num, num+300);
        now = 2, count = 0, ans = 0;
        for (j = 299; j >= 0 && num[j]; j--) {
            ans += now * num[j];
            count++;
            if (count == rank[now]) {
                count = 0;
                now++;
            }
        }
        cout << ans << endl;
    }
}
