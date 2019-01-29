# page32例题：Lake Counting

题目链接:**https://vjudge.net/problem/POJ-2386**

描述：

![](https://ae01.alicdn.com/kf/HTB1ffGraZvrK1Rjy0Fe763TmVXaZ.png)



### 基本思想：

在main函数中扫描整个数组，如果一个空为W，则对其进行dfs，将其本身设置为"."，并dfs扫描其上下左右斜总共8个格子。

在main函数中调用过几次dfs则代表有多少独立的水洼。



### 代码:

```cpp
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
```

