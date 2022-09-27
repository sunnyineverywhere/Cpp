#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int width = 0;
    int height = 0;
    
    for(int i = 0; i < sizes.size(); i++){
        int biggest = max(sizes[i][0], sizes[i][1]);
        int smallest = min(sizes[i][0], sizes[i][1]);
        
        width = max(width, smallest);
        height = max(height, biggest);        
    }
    
    answer = width * height;
    
    cout << width << " " << height << " " << answer;
    
    return answer;
}
