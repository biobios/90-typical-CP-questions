#include <iostream>
#include <vector>
#include <array>
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
    uint64_t K;
    cin >> K;

    map<uint64_t, size_t> prime_factor;

    for (size_t i = 2; i * i <= K; i++)
    {
        while (K % i == 0)
        {
            K /= i;
            prime_factor[i]++;
        }
    }
    if (K != 1)
        prime_factor[K]++;

    uint64_t result = 1;
    uint64_t count_same_2 = 1;
    bool same_3 = true;
    for (auto [prime, count] : prime_factor)
    {
        result *= (count + 2) * (count + 1) / 2;
        count_same_2 *= 1 + count / 2;
        if (count % 3 != 0)
            same_3 = false;
    }
    if (same_3)
    {
        result += 5;
        count_same_2 -= 1;
    }
    result += count_same_2 * 3;
    result /= 6;

    cout << result << endl;

    return 0;
}