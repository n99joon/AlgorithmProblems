#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define swap(x,y) int temp=x;x=y;y=temp;
using namespace std;

//Insertion Sort / Time = Best = O(n), avg, worst=O(n^2), Spcae = O(n)
int main() {
	fastio;
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	for(int i=1;i<n;i++){
		//int tgt=a[i];cout <<"tgt = "<<tgt << endl;
		for(int j=i-1;j>=0;j--){
			if(a[j]>tgt){
				a[j+1]=a[j];
				if(!j){
					a[j]=tgt;
				}
			}else{
				a[j+1]=tgt;
				break;
			}
		}
		/*
		for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
		*/
	}
	
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}

//https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html