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
    uint64_t N, L;
    cin >> N >> L;

    vector<uint32_t> dp(N + L);
    dp[0] = 1;
    for (size_t i = 0; i < N; i++)
    {
        dp[i + 1] += dp[i];
        dp[i + 1] %= 1000000007;
        dp[i + L] += dp[i];
        dp[i + L] %= 1000000007;
    }

    cout << dp[N] << endl;

    return 0;
}