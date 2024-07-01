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

constexpr uint64_t MOD = 1000000007;

int main()
{
    uint64_t N, K;
    cin >> N >> K;

    if (N == 1)
    {
        cout << K << endl;
        return 0;
    }

    uint64_t result = K * (K - 1) % MOD;
    N -= 2;

    uint64_t count = 0;
    uint64_t N_copied = N;
    while (N_copied != 0)
    {
        count++;
        N_copied >>= 1;
    }

    vector<uint64_t> pow(count + 1);
    pow[0] = 1;
    pow[1] = (K - 2) % MOD;
    for (size_t i = 2; i < count + 1; i++)
    {
        pow[i] = pow[i - 1] * pow[i - 1] % MOD;
    }

    for (size_t i = 1; i < count + 1; i++, N >>= 1)
    {
        if ((N & 0b1) != 0)
        {
            result = result * pow[i] % MOD;
        }
    }

    cout << result << endl;

    return 0;
}