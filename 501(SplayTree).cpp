#include<iostream>
using namespace std;

struct Node{
	int w,rn,ln;
	Node *left,*right,*fa;
}*root;

int list[30010];


int find(int);
void splay(Node*);
void zig(Node*);
void zag(Node*);
void Insert(Node*);
void Delete(Node*);
Node* CreateNode(int);

void see(Node*r){
	if(r->left) see(r->left);
	cout << "see  " << r->w << ' ' << r->ln << ' ' << r->rn << endl;
	if(r->right) see(r->right);
	return;
}

int main(){
	int i,j,x,m,n,k,len,con,cccc(0);
	Node *node,*reg;
	for(cin >>k ; k ; k--){
		if(cccc) cout << endl;
		cccc++;
		cin >> m >> n;
		con=0;
		for(i=0 ; i<m ; i++) scanf("%d",&list[i]);
		for(i=len=0 ; i<n ; i++){
			scanf("%d",&x);
			for(; len<x ; len++){
				node=CreateNode(list[len]);
				Insert(node);
	//			see(root);
	//			cout << endl;
			}
			printf("%d\n",find(++con));
		}
		if(root){
			reg=root;
			root=0;
			Delete(reg);
		}
	}
}

int find(int n){
	Node *r=root;
	while(1){
		if(r->ln >= n) r=r->left;
		if(r->ln == n-1){
			if(r->fa) splay(r);
			return r->w;
		}
		if(r->ln <  n-1){
			n-=r->ln+1;
			r=r->right;
		}
	}
}

void zig(Node *n){
	Node *reg=n->right,*y=n->fa;
	n->right=y;
	n->fa=y->fa;
	y->fa=n;
	y->left=reg;
	y->ln=n->rn;
	n->rn+=y->rn+1;
	if(y->left) y->left->fa=y;
	if(n->fa){
		if(y==n->fa->left) n->fa->left=n;
		else n->fa->right=n;
	}
	return;
}

void zag(Node *n){
	Node *reg=n->left,*y=n->fa;
	n->left=y;
	n->fa=y->fa;
	y->fa=n;
	y->right=reg;
	y->rn=n->ln;
	n->ln+=y->ln+1;
	if(y->right) y->right->fa=y;
	if(n->fa){
		if(y==n->fa->left) n->fa->left=n;
		else n->fa->right=n;
	}
	return;
}

void splay(Node *n){
	Node *ff,*f;
	while(n->fa){
		f=n->fa;
		if(!f->fa){
			if(f->right==n) zag(n);
			else zig(n);
			root=n;
		}
		else{
			ff=f->fa;
			if(n==f->left){
				if(f==ff->left) zig(f),zig(n);
				else zig(n),zag(n);
			}
			else{
				if(f==ff->right) zag(f),zag(n);
				else zag(n),zig(n);
			}
			if(!n->fa) root=n;
		}
	}
}

void Insert(Node *n){
	if(!root){
		root=n;
		return;
	}
	Node *now=root;
	while(1){
		if(n->w >= now->w){
			now->rn++;
			if(!now->right){
				now->right=n;
				n->fa=now;
				break;
			}
			else now=now->right;
		}
		if(n->w < now->w){
			now->ln++;
			if(!now->left){
				now->left=n;
				n->fa=now;
				break;
			}
			else now=now->left;
		}
	}
	splay(n);
	return;
}

void Delete(Node *n){
	if(n->right){
		Delete(n->right);
	}
	if(n->left){
		Delete(n->left);
	}
	delete n;
	return;
}

Node* CreateNode(int n){
	Node *node=new Node;
	node->left=node->right=node->fa=0;
	node->w=n;
	node->rn=node->ln=0;
	return node;
}
