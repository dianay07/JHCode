#include <string>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;

    int start = 0, end = 0;
    int sum = sequence[0];
    int length = INT_MAX; 

    while (end < sequence.size())
    {
        if (sum < k) {
            if (++end < sequence.size()) 
                sum += sequence[end];
        }
        else {
            if (sum == k && end - start + 1 < length)
            { 
                length = end - start + 1;
                answer.clear(); 
                answer.push_back(start);
                answer.push_back(end);
            }

            sum -= sequence[start++];
        }
    }

    return answer;
}

int main()
{
    vector<int> sequence = { 1,2,3,4,5 };
    int k = 7;

    solution(sequence, k);


	return 0;
}