//https://www.hackerrank.com/challenges/bfsshortreach
#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <list>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
	int id ;
	int distance;
	bool visited;
	Node* parent;


	Node(int a = 0){
		id = a;
		distance = -1;
		visited = false;
	}
};


void find(int s,vector<Node*> &v,vector<vector<int> >&edges){

	
	v[s]->visited = true;
	v[s]->distance = 0;
	queue<int> q;
	vector<int> dist(v.size(),-1);
	q.push(s);
	int top = 0;
	Node* cur;
	while(!q.empty()){
		top = q.front();
		q.pop();
		cur = v[top];
		//cerr<< top <<"!!"<<endl;
		for(int i = 0; i < edges.size();i++){
		//cout << i <<"  ---  "<<v[i]->visited<<" ";
		//cout << endl;
	}
		for(int i = 0; i < edges[top].size();i++){
			//cout << edges[top][i] <<" !"<<" "<<v[edges[top][i]]->visited<<endl;
			if (!v[edges[top][i]]->visited ){
				//cerr << edges[top][i]<<"==="<<endl;
				q.push(edges[top][i]);
				v[edges[top][i]]->visited = true;
				v[edges[top][i]]->distance = 6 + cur->distance;
			}
		}
	}
	for(int i = 0; i<v.size(); i++){
		if( i !=s){
		cout << v[i]->distance<<" ";
		}
	}
	cout << endl;
}


int main() {

	int T = 0;
	cin >> T ;
	int N = 0, M = 0;
	int n0 = 0, n1= 0;
	int S = 0;
	for ( int  t = 0; t < T ; t++){
		cin >> N >> M ;
		std::vector<Node*> v;
		vector<vector<int> >edges(N,std::vector<int>());
		for(int i = 0; i < N;i++){
			v.push_back(new Node(i));
			
		} 
		for ( int i = 0; i < M; i++){
			cin >> n0 >> n1;
			edges[n0-1].push_back(n1-1);
			edges[n1-1].push_back(n0-1);
		}
		cin >> S;
		find(S-1,v,edges);

	}
  	

    return 0;
}
