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
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

char in[35][85];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void floodfill(int x, int y) {
	int i,dx,dy;
	in[x][y] = '#';
	rep(i,4) {
		dx = dir[i][0] + x;
		dy = dir[i][1] + y;
		if (in[dx][dy] == ' ') {
			floodfill(dx, dy);
		}
	}
}

int main() {
	int n,i,j,sx,sy,t,first(1);
	for (cin >> t; t; t--) {
		if (first) {
			first = 0;
			cin.getline(in[0], 84);
		}
		n=0;
		while (cin.getline(in[n], 84)) {
			if (in[n][0] == '_') {
				break;
			}
			n++;
		}
		rep(i,n) {
			for (j = 0; in[i][j]; j++) {
				if (in[i][j] == '*') {
					sx = i;
					sy = j;
					break;
				}
			}
			if (in[i][j]) break;
		}
		floodfill(sx, sy);
		rep(i,n+1) {
			cout << in[i] << endl;
		}
	}
}
