#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

// �׷����� ǥ��

// ����� �� N�� ������ �� M�� �־��� 2<= N <= 30000 , 1 <= M <= 30000
// �� ��° �ٷκ��� M���� �ٿ� �׷����� ���� ������ a b ���·� �־���
// �̴� ��� a�� b�� ��������� ������� ��Ÿ�� (1<= a , b <= N)
// ���� a,b ���� �� ���� �־����� ���� �ڱ� �ڽŰ� ����Ǿ� ���� ����
// �ϳ��� ��忡 ���� ����� ������ ��ȣ�� ����������� ����
// �Է��� ������� ���� ��Ͽ� �߰��ϸ� ���� ����� ������ �ʿ� x 

// ex
/*
* [inpit]
* 4 3 // ����� �� 4, ������ �� 3
* 1 2 
* 1 3 
* 3 4
* 
* [output]
* 2 3	// 1 �� 2 �� 3�̶� ����Ǿ� ����
* 1		// 2�� 1�� ����Ǿ� ����
* 1 4	// 3�� 1�� 4�� ����Ǿ� ����
* 3		// 4�� 3�̶��� ����Ǿ� ���� 
*/


// ��� Ǯ��� �ұ�?
// => Input

using namespace std;

vector<int> graphList[30000];

class GraphEx {
	int N; // ����� ��
	int M; // ������ ����
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
	// ����� �� N�� ������ �� M �Է�
	cin >> num1 >> num2;
	if (num1 < 2 || num1 > 30000 || num2 < 1 || num2 >30000)
		return 0;
	GraphEx ge(num1, num2);
	ge.printGraph();

	
}