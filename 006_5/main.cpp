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
    uint64_t N, K;
    cin >> N >> K;

    vector<vector<size_t>> index_by_char(26);

    for (size_t i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        index_by_char[c - 'a'].push_back(i);
    }

    size_t current_index = 0;
    for (size_t i = 0; i < K; i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            auto begin = index_by_char[c - 'a'].begin();
            auto end = index_by_char[c - 'a'].end();
            auto it = lower_bound(begin, end, current_index);
            if (it == end || N - *it < K - i)
                continue;

            cout << c;
            current_index = *it + 1;

            break;
        }
    }

    cout << endl;

    return 0;
}