#include <iostream>
#include <math.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    // 4 -> 2 -> 1
    // 7 -> 4 -> 2
    
    while(a != b)
    {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        
        answer++;
    }
    
    return answer;
}