# page30例题：部分和问题

描述：

```
给定整数a1 ... an，判断是否可以从中选出若干数，使他们和恰好为k。
限制:
1 <= n <= 20
-10^8 <= ai <= 10^8
-10^8 <= k <= 10^8
```



样例1：

```
输入：
4  // n
1 2 4 7  // ai
13	// k
输出：
Yes
```



样例2:

```
输入:
4
1 2 4 7
15
输出:
No
```





想法：

从a1开始决定加或者不加，在判断完所有数字之后再看和是不是k.

在解空间上来看，是一个二叉树，如图：

![image-20190129230044674](/Users/apple/Library/Application Support/typora-user-images/image-20190129230044674.png)



左子树为选择不加这个节点，右子树为选择加这个节点。

代码如下：

```cpp
#include <iostream>
using namespace std;

int n=0;
int k=0;
int a[21] = {0};

// i:已经计算了前i项
// sum: 前i项的和
bool dfs(int i, int sum) {
	// 停止条件
	if(i == n) {
		return sum == k;
	}
	// 以下为分支条件.
	// 分支1:加上第i个数字
	if(dfs(i+1, sum+a[i])) {
		return true;
	}
	// 分支2:不加第i个数字
	if(dfs(i+1, sum)) {
		return true;
	}
	// 以上两个分支都无法满足等于k，则返回false，在最终回被main函数判断.
	return false;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++ ) {
		cin >> a[i];
	}
	cin >> k;

	if(dfs(0, 0)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
```

关于dfs:

dfs的模板大概如下：

```cpp
bool dfs(args) {
    if (到达停止条件)
    	return 是否达到条件;
    // 对dfs的每一个分支进行扫描
    if(分支1) {
        return true;
    }
    if(分支2) {
        return true;
    }
    ...
    // 所有分支不满足
    return false;
}
```











