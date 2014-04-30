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
#define LINF (1ull<<63)
#define INF (1<<29)
#define EPS (1e-10)
#define two(a) (1<<(a))
#define lshift(a,b) (a<<b)
#define rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

int pri[19] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int num[18];
int sol[18];
int factor[64][18];
int facSum[64][18];
int plen = 18;
int len;
ll ans;

void init() {
    int i,j;
    memset(factor, 0, sizeof(factor));
    memset(facSum, 0, sizeof(facSum));
    xrep(i,2,64) {
        int temp = i;
        rep(j,18) {
            while (temp % pri[j] == 0) {
                temp /= pri[j];
                factor[i][j]++;
            }
            facSum[i][j] = factor[i][j] + facSum[i-1][j];
        }
    }
}

void go(ll now, int index, int remain, int limit) {
    int i,j,k,diff,dNum;
    int debug = 0;
    if (!remain) {
        rep(i,18) {
            if (sol[i]) {
                break;
            }
        }
        if (i == 18) {
            ans = min(now, ans);
        }
        return;
    }
    if (index >= 18 || limit * (18 - index) < remain) {
        return;
    }
    diff = -1; 
    rep(i,18) {
        if (sol[i] < 0) {
            return;
        }
        if (sol[i] != 0) {
            diff = i;
            dNum = sol[i];
        }
    }
    if (diff == -1) {
        if (now <= ans / pri[index]) {
            go (now * pri[index], index + 1, remain -1, 1); 
        }
        return;
    }
    xrep(i,1,min(remain,limit)+1) {
        if (facSum[i][diff]) break;
    }
    i--;
    rep(j,i) { 
        if (now > ans / pri[index]) {
            return;
        }
        now *= pri[index];
    }
    rep(j,18) {
        sol[j] -= facSum[i][j];
    }
    for (i++; i <= min(remain,limit); i++) {
        if (now > ans / pri[index]) {
            rep(j,18) {
                sol[j] += facSum[i-1][j];
            }
            return;
        }
        rep(j,18) {
            sol[j] -= factor[i][j];
        }
        rep(j,18) {
            if (sol[j] < 0) {
                break;
            }
        }
        if (j < 18) {
            rep(k,18) {
                sol[k] += facSum[i][k];
            }
            return;
        }
        now *= pri[index];
        if (diff != -1 && dNum == sol[diff]){ 
            continue;
        }
        go(now, index + 1, remain - i, i);
    }
    rep(j,18) {
        sol[j] += facSum[i-1][j];
    }
}

void findSol() {
    int i(len),j;
    ll now = 1;
    memset(sol, 0, sizeof(sol));
    if (len > 0) {
        rep(j,18) {
            sol[j] = facSum[len-1][j] - num[j];
        }
    }
    else {
        rep(j,18) {
            sol[j] = -num[j];
        }
    }
    do {
        rep(j,18) {
            sol[j] += factor[i][j];
        }
        rep(j,18) {
            if (sol[j] < 0) {
                break;
            }
        }
        if (j == 18) {
            go(1LL, 0, i, i);
        }
    } while (++i < 64);
}

int main() {
    int i,j;
    ll n;

    init();

    while (cin >> n) {
        cout << n << ' ';
        if (n == 1) {
            cout << 2 << endl;
            continue;
        }
        ans = LINF - 1;
        memset(num, 0, sizeof(num));
        rep(i,plen) {
            if (n == 1){
                break;
            }
            while (n % pri[i] == 0) {
                n /= pri[i];
                num[i]++;
            }
        }
        len = i - 1;
        findSol();
        cout << ans << endl;
    }
}
