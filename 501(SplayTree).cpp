#include<iostream> 
#include<sstream> 
#include<vector> 
#include<map> 
#include<string> 
#include<string.h> 
#include<algorithm> 
#include<math.h> 
#include<set> 
#include<queue> 
#define LINF (1ll<<60) 
#define INF (1<<30)
#define rep(a,b) for(a=0 ; a<b ; a++) 
#define xrep(a,b,c) for(a=b ; a<c ; a++) 
typedef long long ll;
using namespace std;

struct Path{
	int y, can, rev;
};

int pre[200002];
int pEdge[200002];
int use[200002];
vector<Path> edge[200002];

void addedge(int x,int y){
	Path path;
	path.y=y, path.can=1, path.rev=edge[y].size();
	edge[x].push_back(path);
	path.can=0;
	path.y=x;
	path.rev=edge[x].size()-1;
	edge[y].push_back(path);
}

void traceback(int st,int ed){
	int nowx=ed, prex;
	while(nowx!=st){
		prex=pre[nowx];
		Path &path = edge[prex][pEdge[nowx]];
		path.can=0;
		edge[nowx][path.rev].can=1;
		nowx=prex;
	}
}

bool BFS(int st,int ed){
	int i,y;
	queue<int> que;
	que.push(st);
	memset(pre,0,sizeof(pre));
	memset(use,0,sizeof(use));
	memset(pEdge,0,sizeof(pEdge));
	while(!que.empty()){
		int x=que.front();
		que.pop();
		rep(i,edge[x].size()){
			y=edge[x][i].y;
			if(!use[y] && edge[x][i].can){
				y=edge[x][i].y;
				pre[y]=x;
				pEdge[y]=i;
				use[y]=1;
				if(y==ed) break;
				que.push(y);
			}
		}
		if(i<edge[x].size()) break;
	}
	if(!use[ed]) return false;

	traceback(st, ed);
	return true;
}

int Dinic(int st, int ed){
	int ret=0;
	while(BFS(st,ed)){
		ret++;
	}
	return ret;
}

int main(){
	// 0: st , n+1: ed
	int n,m,a,b,c,i,j,k;
	while(~scanf("%d%d%d%d%d",&n,&m,&a,&b,&c)){
		rep(i,n+n+1) edge[i].clear();
		xrep(i,1,n+1){
			addedge(i,n+i);
		}
		rep(i,m){
			scanf("%d%d",&j,&k);
			addedge(j+n,k);
			addedge(k+n,j);
		}
		addedge(0,a);
		addedge(0,b);

		if(Dinic(0,c)>=2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
