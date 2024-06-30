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

    vector<vector<uint64_t>> Nums(3, vector<uint64_t>(N));
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> Nums[i][j];
        }
    }

    vector<uint64_t> dp(46);
    dp[0] = 1;

    for (size_t i = 0; i < 3; i++)
    {
        vector<uint64_t> next(46);
        for (size_t j = 0; j < N; j++)
        {
            uint64_t ab = Nums[i][j];
            for (size_t k = 0; k < 46; k++)
            {
                next[(k + ab) % 46] += dp[k];
            }
        }
        dp = next;
    }

    uint64_t result = dp[0];

    cout << result << endl;

    return 0;
}