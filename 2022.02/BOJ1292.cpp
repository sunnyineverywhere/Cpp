#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	vector<int> v;

	v.push_back(0);

	int i = 1;

	while (v.size() <= 1001) {
		for (int j = i; j > 0; j--) {
			v.push_back(i);
		}
		i++;
	}

	/*
	* 	for (int i = 1; i < 100; i++) {
		cout << v[i] << " ";
	}	
	*/


	int a, b;
	cin >> a >> b;


	int sol = 0;
	for (int k = a; k <= b; k++) {
		sol += v[k];
	}

	cout << sol;

	return 0;
}
