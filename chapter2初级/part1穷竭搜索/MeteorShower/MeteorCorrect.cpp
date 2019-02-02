#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
int vis[400][400], vim[400][400];
int dis[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
struct xx
{
    int x, y;
}vv;
int check(int x, int y)
{
    if((x >= 0 && x <= 500) && (y >= 0 && y <= 500)) return 1;
    else return 0;
}
void bfs()
{
    int ans = 0, fl = 0;
    queue <xx> qq;
    vv.x = vv.y = 0;
    vim[0][0] = 0;
    qq.push(vv);
    while(!qq.empty())
    {
        vv = qq.front();
        qq.pop();
        int x1 = vv.x;
        int y1 = vv.y;
        if(vis[x1][y1] == -1)
        {
            ans = vim[x1][y1];
            fl = 2;
            printf("%d\n", ans);
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int x0 = x1 + dis[i][0];
            int y0 = y1 + dis[i][1];
            if(check(x0, y0) && !vim[x0][y0] && (vim[x1][y1] + 1 < vis[x0][y0] || vis[x0][y0] == -1))
            {
                vim[x0][y0] += vim[x1][y1] + 1;
                vv.x = x0;
                vv.y = y0;
                qq.push(vv);
            }
        }
    }
    if(!fl) puts("-1");
}
int main()
{
    int n, a, b, time;
    while(~scanf("%d", &n))
    {
        memset(vis, -1, sizeof(vis));
        memset(vim, 0, sizeof(vim));
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &a, &b, &time);
            if(vis[a][b] == -1) vis[a][b] = time;
            else vis[a][b] = min(vis[a][b], time);
            for(int j = 0; j < 4; j++)
            {
                int x0 = a + dis[j][0];
                int y0 = b + dis[j][1];
                if(check(x0, y0))
                {
                    if(vis[x0][y0] == -1) vis[x0][y0] = time;
                    else vis[x0][y0] = min(vis[x0][y0], time);
                }
            }
        }
        bfs();
    }
    return 0;
}
