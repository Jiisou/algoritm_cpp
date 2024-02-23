// 14244 : 트리 만들기
#include <iostream>
#include <vector>
using namespace std;
// tree is an acyclic connected graph
//When there is no root, a node with a degree of 1 is called a leaf.

void add(int u, int v) { // add undirected edge 
	cout << u << " " << v<< '\n';
}
int main() {

	int node, leaf; 
	cin >> node >> leaf; // the number of edge is node mius 1
	
	add(0, 1);
	add(0, 2); // minimun form :the number of leaf is two
	leaf -= 2;

	for (int i = 3; i < node; i++) {
		if (leaf) {
			add(0, i);
			leaf--;
		}
		else add(i - 1, i);
	}

	return 0;
}
