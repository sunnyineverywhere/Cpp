#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;


int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;


	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}

	for (int i = 1; i < k; i++) {
		pq.pop();
	}

	cout << pq.top();

	return 0;
}
