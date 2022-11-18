#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// (2, 2) (5, 4)
// (2, 2), (2, 3), (2, 4)
// (3, 4), (4, 4), (5, 4)
// (5, 4), (5, 3), (5, 2)
// (5, 2), (4, 2), (3, 2), (2, 2)

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // 배열 생성
    vector<vector<int>> array(rows+1, vector<int>(columns+1));
    
    int cnt = 0;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            array[i][j] = ++cnt;
        }
    }
    
    
    // queries에서 추출
    for(int i = 0; i < queries.size(); i++){
        int x1 = queries[i][0]; int y1 = queries[i][1];
        int x2 = queries[i][2]; int y2 = queries[i][3];
        
        // 변경사항 저장
        vector<int> tmp;
        
        // 이동할 배열
        for(int i = y1; i <=y2; i++){
            tmp.push_back(array[x1][i]);
        }
        for(int i = x1 + 1; i <= x2; i++){
            tmp.push_back(array[i][y2]);
        }
        for(int i = y2-1; i >= y1; i--){
            tmp.push_back(array[x2][i]);
        }
        for(int i = x2-1; i > x1; i--){
            tmp.push_back(array[i][y1]);
        }
        
        // TEST: 변경 예정 element 출력
        /*
        for(int i = 0; i < tmp.size(); i++){
            cout << tmp[i] << " ";
        }
        cout << "\n";
        */
        
        int idx= -1;
        for(int i = y1 +1; i <=y2; i++){
            array[x1][i] = tmp[++idx];
        }
        for(int i = x1 + 1; i <= x2; i++){
            array[i][y2] = tmp[++idx];
        }
        for(int i = y2-1; i >= y1; i--){
            array[x2][i] = tmp[++idx];
        }
        for(int i = x2-1; i >= x1; i--){
            array[i][y1] = tmp[++idx];
        }
        
        int ans = *std::min_element(tmp.begin(), tmp.end());
        answer.push_back(ans);
        
    }
    
    return answer;
}
