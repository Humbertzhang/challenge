/*
 *	部分和问题
 *	tag: dfs
 * */
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
