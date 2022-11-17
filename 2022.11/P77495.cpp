#include <string>
#include <vector>

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
    
    // 변경사항 저장을 위한 2차원배열
    vector<vector<int>> tmp = array;
    
    // queries에서 추출
    for(int i = 0; i < queries.size(); i++){
        int x1 = queries[i][0]; int y1 = queries[i][1];
        int x2 = queries[i][2]; int y2 = queries[i][3];
        
        // 시작점 저장
        int tmp = array[x1][y1];
        int tmp2 = 변경 위한 변수 저장
        
        // (x1 + 1, y1 ~ y2) 변경
        for(int j = y1; j < y2; j++){
            array[x1][j] = ;
            tmp = 
        }
        
    }
    
    return answer;
}
