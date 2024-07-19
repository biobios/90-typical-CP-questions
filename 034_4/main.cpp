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
    uint64_t N, K;
    cin >> N >> K;

    map<uint64_t, uint64_t> count;
    queue<pair<uint64_t, uint64_t>> q;

    uint64_t prev;
    cin >> prev;
    uint64_t kind_count = 0;
    uint64_t current_sequense = 1;
    uint64_t current_length = 0;
    uint64_t result = 0;
    for (size_t i = 1; i < N; i++)
    {
        uint64_t a;
        cin >> a;
        if (prev != a)
        {
            q.push({current_sequense, prev});
            current_length += current_sequense;
            current_sequense = 0;
            if (count[prev] == 0)
            {
                kind_count++;
                while (kind_count > K)
                {
                    auto f = q.front();
                    q.pop();
                    current_length -= f.first;
                    count[f.second]--;
                    if (count[f.second] > 0)
                        continue;
                    kind_count--;
                }
            }
            count[prev]++;
            if (result < current_length)
                result = current_length;
            prev = a;
        }

        current_sequense++;
    }

    q.push({current_sequense, prev});
    current_length += current_sequense;
    current_sequense = 0;
    if (count[prev] == 0)
    {
        kind_count++;
        while (kind_count > K)
        {
            auto f = q.front();
            q.pop();
            current_length -= f.first;
            count[f.second]--;
            if (count[f.second] > 0)
                continue;
            kind_count--;
        }
    }
    count[prev]++;
    if (result < current_length)
        result = current_length;

    cout << result << endl;

    // vector<uint64_t> sc;

    // uint64_t prev = -1ull;
    // for (size_t i = 0; i < N; i++)
    // {
    //     uint64_t a;
    //     cin >> a;
    //     if (prev != a)
    //     {
    //         sc.push_back(i);
    //         prev = a;
    //     }
    // }

    // sc.push_back(N);

    // uint64_t result = 0;
    // for (uint64_t i = 0; i + K < sc.size(); i++)
    // {
    //     uint64_t length = sc[i + K] - sc[i];
    //     if (length > result)
    //         result = length;
    // }

    // if (result == 0)
    //     result = N;
    // cout << result << endl;

    return 0;
}