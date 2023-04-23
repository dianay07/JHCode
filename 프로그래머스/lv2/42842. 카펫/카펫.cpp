#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 카펫 총 타일 수
    int carpet = brown + yellow;

    for (int i = 1; i < carpet; i++)
    {
        // 가로가 세로보다 크니까 세로가 무조건 작게
        int height = i;                 //
        int width = carpet / height;    //

        if(yellow == ((width - 2) * (height - 2)))
        {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }

    return answer;
}