#include <iostream>

using namespace std;

void Maze(int* pMaze1, int* pMaze2, int n) {
	int* temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		temp[i] = pMaze1[i] | pMaze2[i];
	}
	char* result = (char*)malloc(n*n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i] % 2 == 1)
				result[i * 5 + n - j - 1] = '#';
			else
				result[i * 5 + n - j - 1] = ' ';
			temp[i] /= 2;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i * 5 + j];
		}
		cout << endl;
	}
	free(result);
	free(temp);
}

int main() {
	int n;
	cin >> n;
	int* arr1 = new int[n];
	int* arr2 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	Maze(arr1, arr2, n);
	delete[]arr1;
	delete[]arr2;
}