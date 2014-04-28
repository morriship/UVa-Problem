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

int n,in[550],cost[550][550],dp[550][550],ans[550][550],use[550];

int subCost(int x, int y) {
    int i,j,k,s,mina,minb,count;
    xrep(i,1,y-x+1) {
        xrep(j,x,y-i+1) {
            if (dp[j][j+i] >= 0) {
                continue;
            }
            dp[j][j+i] = INF;
            xrep(k,j,j+i) {
                count = 0;
                mina = minb = INF;
                xrep(s,j,k+1) {
                    mina = min(mina, in[s]);
                }
                xrep(s,k+1,j+i+1) {
                    if (in[s] < mina) {
                        count++;
                    }
                    minb = min(minb, in[s]);
                }
                if (!count) {
                    xrep(s,j,k+1) {
                        if (in[s] < minb) {
                            count++;
                        }
                    }
                }
                dp[j][j+i] = min(dp[j][j+i], i - count + 1 + dp[j][k] + dp[k+1][j+i]);
            }
        }
    }
    return dp[x][y];
}

void calCost() {
    int i,j,k,limit;
    memset(dp, -1, sizeof(dp));
    rep(i,n) {
        dp[i][i] = 0;
    }
    memset(cost, -1, sizeof(cost));
    rep(i,n) {
        xrep(j,i,n) {
            limit = j - i + 1;
            memset(use,0,sizeof(use));
            xrep(k,i,j+1) {
                if (in[k] > limit || use[in[k]]) {
                    break;
                }
                use[in[k]]++;
            }
            if (k == j + 1) {
                cost[i][j] = subCost(i, j);
            }
        }
    }
}

void calAns() {
    int i,j,k;
    memset(ans, 0x2f, sizeof(ans));
    rep(i,n) {
        rep(j,n-i) {
            if (cost[j][j+i] >= 0) {
                ans[j][j+i] = cost[j][j+i];
            }
            xrep(k,j,j+i) {
                if (ans[j][k] < INF && ans[k+1][j+i] < INF) {
                    ans[j][j+i] = min(ans[j][j+i], ans[j][k] + ans[k+1][j+i]);
                }
            }
        }
    }
}

int main() {
    int i;
    while (cin >> n) {
        rep(i,n) {
            cin >> in[i];
        }
        calCost();
        calAns();
        if (ans[0][n-1] >= INF) {
            cout << "impossible" << endl;
        }
        else {
            cout << ans[0][n-1] << endl;
        }
    }
}
