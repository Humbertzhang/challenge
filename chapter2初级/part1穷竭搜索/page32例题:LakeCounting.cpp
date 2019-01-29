#include <iostream>
using namespace std;

// n行 m列
int n, m;
char a[105][105];

void dfs(int i, int j) {
	if(i < 0 || j < 0 || i >= n || j >= m) {
		return;
	}
	if (a[i][j] == '.') {
		return;
	}
	// a[i][j] == 'W'
	a[i][j] = '.';
	for(int ii = i-1;ii <= i+1; ii++) {
		for(int jj = j-1;jj <= j+1; jj++) {
			dfs(ii, jj);	
		}
	}
}


int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}	
	int times = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'W'){
				dfs(i, j);
				times+=1;
			}
		}
	}
	cout << times << endl;
}
