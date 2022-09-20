#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int board[102][102][2];
int N;

// 설치
// 보 설치 - 한쪽 끝이 기둥 위, 양쪽 끝 부분이 다른 보와 연결
// 기둥 설치 - 바닥 위, 보의 한쪽 끝 부분 위, 다른 기둥 위
bool install_frame(int x, int y, int a){
    if(a == 0){ // 기둥 설치
        if(y == 0) return true; // 바닥 위
        if(x > 0 && board[x-1][y][1]) return true; // 보의 왼쪽 끝
        if(y < N && board[x][y][1]) return true; // 보의 오른쪽 끝
        if(y > 0 && board[x][y-1][0]) return true; // 다른 기둥 위
    }
    else{ // 보 설치
        if(y > 0 && board[x][y-1][0]) return true;
        if(x < N && y > 0 && board[x+1][y-1][0]) return true;
        if(x > 0 && x < N && board[x-1][y][1] && board[x+1][y][1]) return true;
    }
    return false;
}


// 삭제
bool remove_frame(int x, int y, int a){
    board[x][y][a] = 0; // 일단 삭제
    
    if(a == 0){ // 기둥 삭제 요청 시
        if(y < N && board[x][y+1][0] && !install_frame(x, y+1, 0)) return false;
        if(y < N && board[x][y+1][1] && !install_frame(x, y+1, 1)) return false;
        if(x > 0 && y < N && !install_frame(x-1, y+1, 1) && board[x-1][y+1][1]) return false;
    }
    else{ // 보 삭제 요청 시
        // 위에 기둥
        if(board[x][y][0] && !install_frame(x, y, 0)) return false;
        if(x < N && board[x+1][y][0] && !install_frame(x+1, y, 0)) return false;
        
        // 다른 보와 연결(x, y, a)
        if(x > 0 && board[x-1][y][1] && !install_frame(x-1, y, 1)) return false;
        if(x < N && board[x+1][y][1] && !install_frame(x+1, y, 1)) return false;
    }
    return true;
}

// x, y, a, b
// x, y: 기둥/보를 설치 또는 삭제할 교차점의 좌표
// a는 종류: 0은 기둥, 1은 보
// b는 구조물 설치 여부: 0은 삭제, 1은 설치
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    
    for(auto frame: build_frame){
        int x = frame[0];
        int y = frame[1];
        int a = frame[2];
        int b = frame[3];
        
        if(b == 0){
            if(!remove_frame(x, y, a)){
                board[x][y][a] = 1;
            }
        }
        else{
            if(install_frame(x, y, a)){
                board[x][y][a] = 1;
            }
        }
    }
    
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            if(board[i][j][0]){
                answer.push_back({i, j, 0});
            }
            if(board[i][j][1]){
                answer.push_back({i, j, 1});
            }
        }
    }
    
    return answer;
}
