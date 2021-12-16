#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100000000ULL
#define fi first
#define se second
#define eb 0.000000001
#define mod 1000000003
using namespace std;

char op[3] = "--";
//str -> int
//map<string, int> inp;
//int -> str
//vector<string> ntos;

//struct for one node of trie
struct TrieNode {
	
	map<string, TrieNode *> children;
	//is this terminal?
	bool terminal;
	TrieNode() : terminal(false){
		//memset(children, 0, sizeof(children));
	}
	//destructor
	/*
	~TrieNode() {
		for(int i=0;i<ALPHABETS;++i)
			if(children[i])
				delete children[i]; //cascade deletion
	}
	*/
	//insert string "key" to the trie that has cur node as root
	void insert(vector<string> & key,int idx){
		if(idx == key.size())
			terminal = true;
		else {
			string next = key[idx];
			//create child node if NULL
			if(children.find(next)==children.end())
				children[next] = new TrieNode();
			//recurse to that child node
			children[next] -> insert(key,idx+1);
		}
	}
	/*
	//IN trie that has cur node as root, find node with "key"
	TrieNode * find (const char* key){
		if(*key==0) return this;
		int next = toNumber(*key);
		if(children[next] == NULL) return NULL;
		return children[next]->find(key+1);
	}*/
	void traverse(int idx){
		for(auto iter = children.begin();iter != children.end();iter++){
			ffor(i,idx)cout<<op;
			cout<<iter->first<<endl;
			iter->second->traverse(idx+1);
		}
		/*
		queue<pair<TrieNode *, int>> q;
		q.push({this, -1});
		while(!q.empty()){
			TrieNode * fr = q.front().fi;
			int depth = q.front().se;
			
			cout<<
		}*/
	}
};

int main(){
	fastio;
	int cnt = 0,n,k;
	cin >> n;
	TrieNode * root = new TrieNode();
	while(n--){
		cin >> k;
		vector<string> inp(k);
		ffor(i,k){
			cin >> inp[i];
		}
		root->insert(inp,0);
	}
	
	root->traverse(0);
}