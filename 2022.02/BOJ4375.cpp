#include <iostream>
using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int input;
	
	while (cin >> input) {
		int i = 1;
		int result = 1;
		while (1) {
			if(i % input == 0){
				break;
			}
			else {
				result++;
				i = i * 10 + 1;
				i = i% input;
			}
		}
		cout << result << "\n";
	}

	return 0;
}
