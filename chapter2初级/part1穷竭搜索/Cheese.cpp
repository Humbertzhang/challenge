#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;
queue<P> q;

// h第一维度,w第二维度
int h, w, n;
char a[1005][1005]; 
char blocks[1005][1005];
int times[1005][1005] = {0};
bool visited[1005][1005] = {0};
int sumtime;

// 4个方向
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void bfs(char target, int sx, int sy) {
	// clear queue
	while(!q.empty()){
		q.pop();
	}
	int endx, endy;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++){
			blocks[i][j] = a[i][j];
			times[i][j] = 0;
			visited[sx][sy] = false;
		}
	}
	q.push(P(sx, sy));
	visited[sx][sy] = true;
	while(q.size()) {
		// 访问p
		P p = q.front(); q.pop();
		//到达本次bfs终点
		if(blocks[p.first][p.second] == target) {
			endx = p.first;
			endy = p.second;
			break;
		}
		for(int k = 0; k < 4; k++) {
			int nx = p.first + dx[k];
			int ny = p.second + dy[k];
			if(nx >= 0 && ny >= 0 && nx < h && ny < w && blocks[nx][ny] != 'X' && visited[nx][ny] == false) {
				q.push(P(nx, ny));	
				visited[nx][ny] = true;
				times[nx][ny] = times[p.first][p.second] + 1;
			}
		}
	}
	sumtime += times[endx][endy];
	if (target - '0' < n) {
		bfs(target + 1, endx, endy);
	}	
}


int main()
{
	cin >> h >> w >> n;
	int sx = 0, sy = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}

	sumtime = 0;
	bfs('1', sx, sy);
	cout << sumtime << endl;
	return 0;
}
