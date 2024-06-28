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

uint64_t gcd(uint64_t a, uint64_t b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

uint64_t lcm(uint64_t a, uint64_t b)
{
    uint64_t d = gcd(a, b);
    return a / d * b;
}

int main()
{
    uint64_t N;
    cin >> N;
    vector<uint64_t> Coins(3);
    for (size_t i = 0; i < 3; i++)
    {
        cin >> Coins[i];
    }

    sort(Coins.rbegin(), Coins.rend());

    vector<pair<uint64_t, uint64_t>> rate(3);
    for (size_t i = 0; i < 3; i++)
    {
        uint64_t l = lcm(Coins[i], Coins[(i + 1) % 3]);
        rate[i] = {l / Coins[i], l / Coins[(i + 1) % 3]};
    }

    uint64_t result = -1ull;
    uint64_t use0;
    use0 = N / Coins[0];
    for (int64_t i = use0; i >= 0; i--)
    {
        uint64_t N_left = N - i * Coins[0];
        for (int64_t j = N_left / Coins[1]; j >= 0; j--)
        {
            if ((N_left - j * Coins[1]) % Coins[2] == 0)
            {
                uint64_t k = ((N_left - j * Coins[1]) / Coins[2]);

                result = min(result, i + j + k);
            }
        }
    }

    cout << result << endl;

    return 0;
}