#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <string>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    uint64_t N;
    cin >> N;
    string S;
    cin >> S;

    uint64_t result = N * (N - 1) / 2;
    uint64_t current_streak = 1;
    char current_char = 0;
    for (auto &&c : S)
    {
        if (c == current_char)
        {
            current_streak++;
            continue;
        }
        result -= current_streak * (current_streak - 1) / 2;
        current_streak = 1;
        current_char = c;
    }

    result -= current_streak * (current_streak - 1) / 2;

    cout << result << endl;
    return 0;
}