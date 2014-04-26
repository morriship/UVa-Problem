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

char in[55][55];
int dir[4][2]={1, 0, -1, 0, 0, 1, 0, -1};
int num;
vector<int> ans;

void remove(int x, int y) {
	int i,dx,dy;
	in[x][y] = '*';
	rep(i,4) {
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (in[dx][dy] == 'X') {
			remove(dx, dy);
		}
	}
}

void calAns(int x, int y) {
	int i,dx,dy;
	in[x][y] = '.';
	rep(i,4) {
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (in[dx][dy] == '*') {
			calAns(dx, dy);
		}
		else if (in[dx][dy] == 'X') {
			num++;
			remove(dx, dy);
			calAns(dx, dy);
		}
	}
}
	
int main() {
	int n,m,i,j,first(1),count(1);
	for (cin >> m >> n; m || n; cin >> m >> n) {
		ans.clear();
		rep(i,n) { cin >> in[i]; }
		rep(i,n) rep(j,m) {
			if (in[i][j] == '*') {
				num = 0;
				calAns(i, j);
				ans.push_back(num);
			}
		}
		sort(ans.begin(), ans.end());
		cout << "Throw " << count++ << '\n' << ans[0] ;
		xrep(i,1,ans.size()) {
			cout << ' ' << ans[i];
		}
		cout << '\n' << endl;
	}
}
