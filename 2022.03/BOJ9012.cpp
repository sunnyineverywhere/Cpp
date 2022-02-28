/* 괄호 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {



	int n;
	cin >> n;

	while (n--) {
		bool isVPS = true;
		stack<char> s;
		string input;
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(') {
				s.push(input[i]);
			}
			else if (!s.empty() && input[i] == ')') {
				s.pop();
			}
			else if (s.empty() && input[i] == ')') {
				isVPS = false;
				break;
			}

			/*
			* if (!isVPS) {
				cout << "NO ";
			}
			else {
				cout << "YES ";
			}
			*/
			
		}


		if (s.empty() && isVPS) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
