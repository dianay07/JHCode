#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    vector<int> v;

	string tmp;
    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] != ' ') 
        {
            tmp += s[i];
        }
        else 
        {
            v.push_back(stoi(tmp));
            tmp.clear();
        }
    }

    v.push_back(stoi(tmp));

    sort(v.begin(), v.end());

    answer += to_string(v.front()) + " " + to_string(v.back());

    return answer;
}

int main()
{
    string s = "-1 -2 -3 -4";
    solution(s);

    return 0;
}