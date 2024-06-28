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
    string N_eight;
    uint64_t K;

    cin >> N_eight >> K;

    uint64_t N = 0;
    uint64_t base = 1;
    for (int i = N_eight.size() - 1; i >= 0; i--, base *= 8)
    {
        N += (N_eight[i] - '0') * base;
    }

    for (size_t i = 0; i < K; i++)
    {
        uint64_t N_prev = N;
        N = 0;
        for (base = 1; N_prev != 0; base *= 8)
        {
            uint64_t left = N_prev % 9;
            if (left == 8)
            {
                N += 5 * base;
            }
            else
            {
                N += left * base;
            }
            N_prev /= 9;
        }
    }

    string result = "";
    if (N == 0)
    {
        result = "0";
    }
    while (N != 0)
    {
        result = (char)(N % 8 + '0') + result;
        N /= 8;
    }

    cout << result << endl;

    return 0;
}