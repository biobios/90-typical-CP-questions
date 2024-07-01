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
    uint64_t L, R;
    cin >> L >> R;

    uint64_t digits_count_L = 0;
    uint64_t digits_count_R = 0;

    uint64_t L_c = L;
    uint64_t R_c = R;

    while (L_c != 0)
    {
        L_c /= 10;
        digits_count_L++;
    }

    while (R_c != 0)
    {
        R_c /= 10;
        digits_count_R++;
    }

    uint64_t pow_digits_count = 1;
    for (size_t i = 0; i < digits_count_L; i++)
    {
        pow_digits_count *= 10;
    }
    uint64_t result = 0;
    constexpr uint64_t inv_2 = 500000004;

    if (digits_count_L == digits_count_R)
    {

        result = (R + L) % MOD * ((R - L + 1) % MOD) % MOD * inv_2 * digits_count_L % MOD;

        cout << result << endl;
        return 0;
    }

    result += (pow_digits_count - L) % MOD * ((pow_digits_count + L - 1) % MOD) % MOD * inv_2 % MOD * digits_count_L % MOD;
    result %= MOD;
    digits_count_L++;

    while (digits_count_L != digits_count_R)
    {
        result += 9 * pow_digits_count % MOD * ((11 * pow_digits_count - 1) % MOD) % MOD * inv_2 % MOD * digits_count_L % MOD;
        result %= MOD;
        pow_digits_count *= 10;
        digits_count_L++;
    }

    result += (R - pow_digits_count + 1) % MOD * ((R + pow_digits_count) % MOD) % MOD * inv_2 % MOD * digits_count_L % MOD;
    result %= MOD;

    cout << result << endl;

    return 0;
}