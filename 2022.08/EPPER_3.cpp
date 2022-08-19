#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solution(string input) {
	int answer = 0;

	stack<char> s;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			s.push(input[i]);
		}
		if (input[i] == ')') {
			if (i > 0 && input[i-1] == '(') {
				s.pop();
				answer += s.size();
			}
			else {
				s.pop();
				answer++;
			}
		}
	}
	return answer;
}

int main(void) {
	string input;
	cin >> input;
	cout << solution(input);
}
