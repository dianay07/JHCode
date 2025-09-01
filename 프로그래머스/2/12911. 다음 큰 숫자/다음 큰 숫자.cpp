#include <string>
#include <vector>
#include <iostream>

using namespace std;

int convert(int n)
{
    int count = 0;
    
    while(n != 0)
    {
        if(n% 2 == 1)
            count++;
        
        n = n /2;
    }
    
    return count;
}

int solution(int n) 
{
    int answer = 0;
    int count = convert(n);
    int compare = 0;
    
    n = n + 1;
    while(true)
    {
        compare = convert(n);
    
        if(compare != count)
             n = n + 1;   
        else
        {
            answer = n;
            break;
        }
            
    }
    
    return answer;
}