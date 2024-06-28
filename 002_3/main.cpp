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
    if (N % 2 != 0)
        return 0;

    string S;
    for (size_t i = 0; i < N / 2; i++)
    {
        S += '(';
    }
    for (size_t i = N / 2; i < N; i++)
    {
        S += ')';
    }

    do
    {
        uint64_t depth = 1;
        for (size_t i = 0; i < N; i++)
        {
            if (S[i] == '(')
                depth++;
            else
                depth--;
            if (depth == 0)
                break;
        }

        if (depth != 0)
            cout << S << endl;
    } while (next_permutation(S.begin(), S.end()));

    return 0;
}