#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
       vector<int> answer;

    int convertCount = 0;
    int removeCount = 0;

    while (s != "1") 
    {
        convertCount++;
        int size = 0;

        for (char c : s) 
        {
            if (c == '1') 
                size++;
            else 
                removeCount++;
        }

        string binaryString;
        if (size == 0) 
            binaryString = "0";
        else 
            while (size > 0) 
            {
                binaryString += to_string(size % 2);
                size /= 2;
            }
        

        reverse(binaryString.begin(), binaryString.end());
        s = binaryString;
    }

    answer.push_back(convertCount);
    answer.push_back(removeCount);

    return answer;
}