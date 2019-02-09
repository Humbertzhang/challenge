/**
 *DFS:https://www.luogu.org/problemnew/show/U56860
 **/
#include <iostream>

using namespace std;

char sea[1003][1003];
char sea2[1003][1003];
bool visited[1003][1003];

int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 第一次 before 为 #  after 为 $, 将# 递归为 $，单独的# 为岛屿个数
// 第二次 before 为 $ after 为 # ， 将 $ 递归为#，单独的$为岛屿个数
void dfs1(int x, int y, char before, char after) {
	sea[x][y] = after;
	// 上下左右四个递归dfs, 将 # 变为 $
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx > 0 && yy > 0 && xx < n && yy < n && !visited[xx][yy] && sea[xx][yy] == before){
			visited[xx][yy] = true;
			dfs1(xx, yy, before, after);
		}
	}	
}

bool besidesea(int x, int y) {
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx > 0 && yy > 0 && xx < n && yy < n && sea[xx][yy] == '.') {
			return true;
		}
	}
	return false;
}

void initvisit() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

int main() 
{
	// input 
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> sea[i][j];
			sea2[i][j] = sea[i][j];
		}
	}
	int count_before = 0, count_after = 0;
	// 统计原有个数, 将所有的#变为$
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(sea[i][j] == '#') {
				visited[i][j] = true;
				count_before += 1;
				dfs1(i, j, '#', '$');
			}
		}
	}
	// visited 清空，在淹没中，避免新淹没的被当作原来的海.
	initvisit();	
	
	// 淹没
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(sea[i][j] == '$' && !visited[i][j] && besidesea(i, j)) {
				sea[i][j] = '.';
				visited[i][j] = true;
			}
		}
	}
	
	// visited 清空 
	initvisit();

	// 统计剩余个数
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(sea[i][j] == '$') {
				visited[i][j] = true;
				count_after += 1;
				dfs1(i, j, '$', '#');
			}
		}
	}	
	cout << count_before - count_after << endl;
	return 0;
}
