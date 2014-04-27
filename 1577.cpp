#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-10)
#define two(a) (1<<(a))i
#define lshift(a,b) (a<<b)
#define rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

int n,k,len;
int in[1000001];

int find (int lim) {
    int i,_max(0),now(0);
    rep(i,n) {
        while (now <= _max) {
            if (in[now + 1] - in[now] <= lim) {
                break;
            }
            now++;
        }
        if (now > _max) {
            return 0;
        }
        now += 2;
        _max += lshift(k, 1);
    }
    return 1;
}

int main() {
    int i;
    while (~scanf("%d%d", &n, &k)) {
        len = lshift((n * k), 1);
        rep(i,len) {
            sca(in[i]);
        }
        sort(in, in + len);
        int ft = in[1] - in[0],ed = in[len-1],mi;
        while (ft < ed) {
            mi = rshift((ft + ed), 1);
            if (find(mi)) { ed = mi; }
            else { ft = mi + 1; }
        }
        printf("%d\n", ft);
    }
}
