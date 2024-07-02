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

    string S;
    cin >> S;

    map<char, size_t> char_index_map;
    char_index_map['a'] = 1;
    char_index_map['t'] = 2;
    char_index_map['c'] = 3;
    char_index_map['o'] = 4;
    char_index_map['d'] = 5;
    char_index_map['e'] = 6;
    char_index_map['r'] = 7;

    vector<uint64_t> dp(8);

    dp[0] = 1;

    for (auto &&c : S)
    {
        size_t index = char_index_map[c];
        if (index == 0)
            continue;

        dp[index] += dp[index - 1];
        dp[index] %= 1000000007;
    }

    cout << dp[7] << endl;
    return 0;
}