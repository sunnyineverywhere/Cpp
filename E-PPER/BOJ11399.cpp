#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int sum = 0;
	int n;
	cin >> n;
	vector<int> v(n);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}


	for (int i = 0; i < n; i++) {
		v[i] = pq.top();
		pq.pop();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			sum += v[j];
		}
	}

	cout << sum;

}
