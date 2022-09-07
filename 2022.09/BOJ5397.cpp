#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

vector<string> answer;

void solve(string input) {
    int len = input.length();
    // debug
    // cout << len;
    list<char> l;
    auto cur = l.begin();
    for (int i = 0; i < len; i++) {
        // 백스페이스 && 앞에 글자가 있을 때
        if (input[i] == '-' && !l.empty()) {
            l.pop_back();
            continue;
        }

        // 화살표 이동
        if (input[i] == '<') {
            if (cur != l.begin()) {
                cur--;
            }
            continue;
        }
        else if (input[i] == '>') {
            cur++;
            continue;
        }
        

        l.insert(cur, input[i]);
        cur++;
    }
    string tmp = "";
    
    while (!l.empty()) {
        tmp.push_back(l.front());
        l.pop_front();
    }

    answer.push_back(tmp);
}

void solution(int l) {
    while (l--) {
        string input;
        cin >> input;
        solve(input);
    }
}

int main(void) {
    int l;
    cin >> l;
    solution(l);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
