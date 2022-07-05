#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int len = s.length();
    bool isSpace = true; // 첫번째 단어를 위해 true로 시작
    
    
    for(int i = 0; i < len; i++){
        
        // 공백 확인
        if(s[i] == ' '){
            isSpace = true;
            answer += s[i]; // 스페이스를 한 번 넣어주고
            continue; // 이번 반복문 종료
        }
        
        // 공백이 아닐 시 == 단어의 첫번째 글자가 아닐 때
        if(!isSpace){
            if(s[i] >= 65 && s[i] <= 90){ // 대문자라면
                answer += s[i] + 32; // 소문자로 바꾼다
            }
            else{
                answer += s[i]; // 이외에는 그냥 추갸해주기
            }
        }
        else{ // 공백일 때 == 단어의 첫글자일 때
            if(s[i] >= 97 && s[i] <= 122){ // 소문자라면
                answer += s[i] - 32; // 대문자로 바꿔준다
                isSpace = false; // 이후 공백 표시를 지워줌
            }
            else{
                // 공백이 연속되지 않으면서 단어의 첫글자가 소문자가 아닐 때
                answer += s[i];
                
                // 공백이 연속되지 않을때만 공백 표시를 지워준다
                if(s[i] != ' '){ 
                    isSpace = false;
                }
            }
            
       }
        
    }
    
    
    return answer;
}
