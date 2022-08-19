#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 모든 학생들이 체육복 하나를 갖고 있다고 가정하고 배열 선언
    vector<int> student(n + 2, 1); // 1번, n번 학생 탐색할 거 대비하여 n+2로 생성
    student[0] = 0; // 예외처리: 0번 학생은 없음
    student[n+1] = 0;

    // 가져오지 않은 학생들의 체육복 개수 차감
    for(int i = 0; i < lost.size(); i++){
        student[lost[i]]--;
    }
    
    // 여분 학생복 가져온 학생들의 체육복 개수 증가
    for(int i = 0; i < reserve.size(); i++){
        student[reserve[i]]++;
    }
    
    // 전체 탐색
    for(int i = 1; i<=n; i++){
        // 학생복 가지고 있으면 넘어감
        if(student[i]){
            continue;
        }
        else{
            if(student[i-1] == 2){
                student[i-1]--;
                student[i]++;
            }
            else if(student[i+1] == 2){
                student[i+1]--;
                student[i]++;
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        if(student[i]){
            answer++;
        }
    }
    
    return answer;
}
