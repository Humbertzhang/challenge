/*
 * https://vjudge.net/problem/Aizu-0118#author=wangguan
 * */
#include <iostream>

using namespace std;

// h列 w行
int h, w;
char a[102][102];
char symbol;
int area = 0;

int xd[4] = {0, 1, 0, -1};
int yd[4] = {-1, 0, 1, 0};


void dfs(int i, int j) {
	a[i][j] = '.';
	for(int k = 0; k < 4; k++) {
		int ii = i + xd[k];
		int jj = j + yd[k];
		if(ii < 0 || jj < 0 || ii >= h || jj >= w) {
			continue;
		}
		if(a[ii][jj] != symbol) {
			continue;
		}
		dfs(ii, jj);
	}
}

int main() {
	while(true){
		cin >> h >> w;
		if(h == 0 && w == 0) {
			break;
		}
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				cin >> a[i][j];
			}
		}
		area = 0;
		
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				// 将.作为访问过的标志
				if(a[i][j] != '.') {
					symbol = a[i][j];
					dfs(i, j);
					area += 1;
				}
			}
		}
		cout << area << endl;
	}
	return 0;
}
