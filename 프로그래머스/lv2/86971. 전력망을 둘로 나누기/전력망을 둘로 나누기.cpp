#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for (int i = 0; i < wires.size(); i++) {
        vector<int> first;
        first.push_back(wires[i][0]);
        int f_ind = 0;

        while (f_ind < first.size()) {
            for (int j = 0; j < wires.size(); j++) {
                if (i != j) {
                    if (first[f_ind] == wires[j][0]) {
                        if (find(first.begin(), first.end(), wires[j][1]) == first.end())
                            first.push_back(wires[j][1]);
                    }
                    else if (first[f_ind] == wires[j][1]) {
                        if (find(first.begin(), first.end(), wires[j][0]) == first.end())
                            first.push_back(wires[j][0]);
                    }
                }
            }
            ++f_ind;
        }

        int result = abs(n - 2 * (f_ind));
        if (result < answer) {
            answer = result;
        }
        else if (result == 0) {
            return 0;
        }

    }

    return answer;
}