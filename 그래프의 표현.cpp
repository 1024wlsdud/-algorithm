#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

// 그래프의 표현

// 노드의 수 N과 간선의 수 M이 주어짐 2<= N <= 30000 , 1 <= M <= 30000
// 두 번째 줄로부터 M개의 줄에 그래프의 간선 정보가 a b 형태로 주어짐
// 이는 노드 a와 b가 양방향으로 연결됨을 나타냄 (1<= a , b <= N)
// 같은 a,b 쌍은 한 번만 주어지고 노드는 자기 자신과 연결되어 있지 않음
// 하나의 노드에 대한 연결된 노드들의 번호는 오름차순대로 들어옴
// 입력의 순서대로 간선 목록에 추가하면 간선 목록을 정렬할 필요 x 

// ex
/*
* [inpit]
* 4 3 // 노드의 수 4, 간선의 수 3
* 1 2 
* 1 3 
* 3 4
* 
* [output]
* 2 3	// 1 은 2 와 3이랑 연결되어 있음
* 1		// 2는 1과 연결되어 있음
* 1 4	// 3은 1과 4와 연결되어 있음
* 3		// 4는 3이랑만 연결되어 있음 
*/


// 어떻게 풀어야 할까?
// => Input

using namespace std;

vector<int> graphList[30000];

class GraphEx {
	int N; // 노드의 수
	int M; // 간선의 개수
	int size;
public:
	GraphEx(int N, int M) {
		this->N = N;
		this->M = M;
		this->size = 0;
		int input1;
		int input2;
		for (int i = 0; i < M; i++) {
			cin >> input1;
			cin >> input2;
			setNode(input1, input2);
		}
		
	}

	void setNode(int input1, int input2) {
		graphList[input1].push_back(input2);
		graphList[input2].push_back(input1);
	}

	void printGraph() {
		for (int i = 1; i < N+1; i++) {
			size = graphList[i].size();
			if (size == 0) {
				cout << endl;
				continue;
			}
			for (int j = 0; j < size; j++) {
				cout<< graphList[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main() {
	int num1, num2;
	// 노드의 수 N과 간선의 수 M 입력
	cin >> num1 >> num2;
	if (num1 < 2 || num1 > 30000 || num2 < 1 || num2 >30000)
		return 0;
	GraphEx ge(num1, num2);
	ge.printGraph();

	
}