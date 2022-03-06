#include <iostream>
#include <vector>
using namespace std;
int n, res;

int main(void) {

	cin >> n;

	for (int i = 1; i <= n; i*=10) {
		res += n - i + 1;
	}

	cout << res;



	return 0;
