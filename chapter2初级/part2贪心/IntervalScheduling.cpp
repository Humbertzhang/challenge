/*
 * 区间调度例题
 * */
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n;
int s[1000005];
int t[1000005];

typedef pair<int, int> P;
vector<P> v;

int main() 
{
	// input
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}
	
	// 处理
	for(int i = 0; i < n; i++) {
		P p = P(t[i], s[i]);
		v.push_back(p);
	}
	// sort pair只看pair的first
	sort(v.begin(), v.begin() + n);

	int init = -1;
	int count = 0;
	for(int i = 0; i < n; i++) {
		// first 为结束时间 second为开始时间
		if(v[i].second > init) {
			count += 1;
			init = v[i].first; 	
		}
	}
	cout << count << endl;
	return 0;
}
