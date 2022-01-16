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

//only a single case alphabet =26
const int ALPHABETS = 26;
int toNumber(char ch) {return ch - 'a';};

//struct for one node of trie
struct TrieNode {
	TrieNode * children[ALPHABETS];
	//is this terminal?
	bool terminal;
	TrieNode() : terminal(false){
		memset(children, 0, sizeof(children));
	}
	//destructor
	~TrieNode() {
		for(int i=0;i<ALPHABETS;++i)
			if(children[i])
				delete children[i]; //cascade deletion
	}
	
	//insert string "key" to the trie that has cur node as root
	void insert(const char * key){
		if(*key == 0)
			terminal = true;
		else {
			int next = toNumber(*key);
			//create child node if NULL
			if(children[next]==NULL)
				children[next] = new TrieNode();
			//recurse to that child node
			children[next] -> insert(key+1);
		}
		
	}
	
	//IN trie that has cur node as root, find node with "key"
	TrieNode * find (const char* key){
		if(*key==0){
			if(terminal)return this;
			else return NULL;
		} 
		int next = toNumber(*key);
		if(children[next] == NULL) return NULL;
		return children[next]->find(key+1);
	}
};

int main(){
	fastio;
	int n,m;
	cin >> n >> m;
	TrieNode * root = new TrieNode();
	while(n--){
		char inp[501];
		cin >> inp;
		//cout << inp << endl;
		root -> insert(inp);
	}
	int cnt=0;
	while(m--){
		char inp[501];
		cin >> inp;
		if(root->find(inp)){
			//cout << inp << "<-"<<endl;
			cnt++;
		}
	}
	cout << cnt;
}