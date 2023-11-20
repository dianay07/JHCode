#include <array>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    array<int, 5> num1 = { 1,2,3,4,5 };
    array<int, 8> num2 = { 2,1,2,3,2,4,2,5 };
    array<int, 10> num3 = { 3,3,1,1,2,2,4,4,5,5 };


    // 1번
    int answerNum = 0;
    for(int i = 0; i < answers.size(); i++)
    {
    	if (answers[i] == num1[answerNum])
            count1++;

        answerNum++;

        if (answerNum == num1.size())
            answerNum = 0;
    }

    // 2번
    answerNum = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == num2[answerNum])
            count2++;

        answerNum++;

        if (answerNum == num2.size())
            answerNum = 0;
    }

    // 3
    answerNum = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == num3[answerNum])
            count3++;

        answerNum++;

        if (answerNum == num3.size())
            answerNum = 0;
    }

    int ret = max(count1, max(count2, count3));

	if (ret == count1)
        answer.push_back(1);
    if (ret == count2)
        answer.push_back(2);
    if (ret == count3)
        answer.push_back(3);


    return answer;
}
