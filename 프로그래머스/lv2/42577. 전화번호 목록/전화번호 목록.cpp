#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> phone_book;

bool solution(vector<string> phone_book) {
    bool answer = true;

    set<string> input;

    for (int i = 0; i < phone_book.size(); i++)
    {
        input.insert(phone_book[i]);
    }
        
    for (auto start = input.begin(); start != input.end(); ++start)
    {
        for (auto next = start; next != input.end(); ++next)
        {
            if (start != next)
            {
                if (next->find(*start) == 0)
                    return false;
                else
                    break;
            }
        }
    }
     
    return answer;
}