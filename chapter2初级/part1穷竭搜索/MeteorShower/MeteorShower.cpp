/*
 *https://vjudge.net/problem/POJ-3669#author=s19435631
 * */

#include <iostream>
#include <queue>
#include <utility>
#define SIZE 400
using namespace std;
int INF = 2147480000;

typedef pair<int, int> P;
queue<P> que;

int m;
int used_time = -1;
// 点矩阵，值为爆炸时间
int points[SIZE][SIZE] = {0};
// 时间矩阵,值为到达该点的时间
int times[SIZE][SIZE] = {0};
bool visited[SIZE][SIZE] = {0};

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void bfs() {
    que.push(P(0,0));
    visited[0][0] = true;

    while(que.size()) {
        P p = que.front(); que.pop();
        if(points[p.first][p.second] == INF) {
            used_time = times[p.first][p.second];
            break;
        }
        for(int k = 0; k < 4; k++) {
            int xx = p.first + dx[k];
            int yy = p.second + dy[k];
            if(xx >= 0 && yy >= 0 && xx < SIZE && yy < SIZE && !visited[xx][yy] && points[xx][yy] > times[p.first][p.second]+1) {
                que.push(P(xx, yy));
                times[xx][yy] = times[p.first][p.second]+1;
                visited[xx][yy] = true;
            }
        }
    }
}

void set_around(int x, int y, int t) {
    for(int k = 0; k < 4; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(xx >= 0 && yy >= 0 && xx < SIZE && yy < SIZE) {
            points[xx][yy] = min(t, points[xx][yy]);
        }
    }
}

int main() {
    cin >> m;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            points[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        points[x][y] = t;
        set_around(x, y, t);
    }
    bfs();
    cout << used_time << endl;
    return 0;
}
