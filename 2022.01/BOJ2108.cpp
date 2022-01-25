#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main(void) {

	int n;
	cin >> n;
	vector<int> array(n);

	int sum = 0;
	
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		array[i] = input;
		sum += input;
	}
	int mean = sum / n;
	
	sort(array.begin(), array.end(), compare);

	

	cout << mean << '\n' << array[n / 2] << '\n' << sum  << '\n' << array[n-1] - array[0];

	return 0;
}
