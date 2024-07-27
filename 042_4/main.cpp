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
#include <atcoder/all>

using namespace std;

constexpr uint64_t MOD = 1e9 + 7;

int main()
{
    uint64_t K;
    cin >> K;

    if (K % 9 != 0)
    {
        cout << "0" << endl;
        return 0;
    }

    vector<uint64_t> dp(K + 1);

    // dp[i][k] i桁までの桁の合計がkである組み合わせの数
    // dp

    dp[0] = 1;
    vector<uint64_t> next(K + 1);
    uint64_t result = 0;

    // for (size_t i = 0; i < K; i++)
    // {
    //     for (int64_t j = K /*min(9 * i, K - 1)*/; j >= 0; j--)
    //     {
    //         uint64_t a = dp[j];
    //         dp[j] = 0;
    //         for (size_t k = j + 1; k <= K && k <= j + 9; k++)
    //         {
    //             next[k] += a;
    //             next[k] %= MOD;
    //         }
    //     }
    //     result += next[K];
    //     result %= MOD;
    //     dp.swap(next);
    // }

    for (int64_t i = 1; i <= K; i++)
    {
        int B = min(i, (int64_t)9);
        for (int64_t j = 1; j <= B; j++)
        {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }

    cout << dp[K] << endl;

    return 0;
}