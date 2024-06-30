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

    vector<uint64_t> dp(6);
    for (auto &d : dp)
    {
        d = 1;
    }
    for (size_t i = 0; i < N; i++)
    {
        uint64_t sum = 0;

        for (size_t j = 0; j < 6; j++)
        {
            uint64_t a;
            cin >> a;
            uint64_t product = dp[j] * a;

            sum += product;
        }
        sum %= 1000000007;
        for (size_t j = 0; j < 6; j++)
        {
            dp[j] = sum;
        }
    }

    cout << dp[0] << endl;

    return 0;
}