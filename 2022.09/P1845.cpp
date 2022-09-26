#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    answer = nums.size() / 2;
    
    set<int> s;
    
    for(int i = 0; i < nums.size(); i++){
        if(s.count(nums[i]) == 0){
            s.insert(nums[i]);
        }
    }
    
    cout << answer << " " << s.size();
    
    // s에는 포켓몬의 종류가 들어있다
    // 포켓몬 종류 수가 answer보다 작다면, 포켓몬 종류 수만큼 리턴
    if(s.size() < answer){
        answer = s.size();
    }
    
    return answer;
}
