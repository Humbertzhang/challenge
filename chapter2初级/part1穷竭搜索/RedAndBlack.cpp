/*
 * http://poj.org/problem?id=1979
 * */
#include <iostream>
using namespace std;

// h列 w行
int h, w;
char a[21][21];
int countb = 0;

int xd[4] = {0, 1, 0, -1};
int yd[4] = {-1, 0, 1, 0};

void dfs(int i, int j) {
	a[i][j] = '#';
	countb += 1;
	for(int k = 0; k < 4; k++) {
		int ii = i + xd[k];
		int jj = j + yd[k];
		if(ii < 0 || jj < 0 || ii >= w || jj >= h) {
			continue;
		}
		if(a[ii][jj] == '.'){
			dfs(ii, jj);
		}
	}
}

int main() {
	while(true) {
		cin >> h >> w;
		if(h == 0 && w == 0) {
			break;
		}
		
		// init
		int manx = 0, many = 0;
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				cin >> a[i][j];
				if(a[i][j] == '@') {
					manx = i;
					many = j;
				}
			}
		}
		countb = 0;
		dfs(manx, many);
		cout << countb << endl;
	}
	return 0;	
}
