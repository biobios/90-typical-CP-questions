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

    vector<uint64_t> valency(N);
    vector<vector<size_t>> adjacency(N);

    for (size_t i = 0; i < N - 1; i++)
    {
        uint64_t A, B;
        cin >> A >> B;
        A--;
        B--;
        valency[A]++;
        valency[B]++;

        adjacency[A].push_back(B);
        adjacency[B].push_back(A);
    }

    size_t max_index = 0;
    uint64_t max_length = 0;
    stack<tuple<size_t, size_t, uint64_t>> P;
    P.push({-1ull, 0, 0});
    while (!P.empty())
    {
        auto [prev, current, current_length] = P.top();
        P.pop();

        if (current_length > max_length)
        {
            max_length = current_length;
            max_index = current;
        }

        for (auto &&to : adjacency[current])
        {
            if (prev == to)
                continue;
            P.push({current, to, current_length + 1});
        }
    }

    uint64_t result = 0;
    P.push({-1ull, max_index, 0});
    while (!P.empty())
    {
        auto [prev, current, current_length] = P.top();
        P.pop();

        if (current_length > result)
        {
            result = current_length;
        }

        for (auto &&to : adjacency[current])
        {
            if (prev == to)
                continue;
            P.push({current, to, current_length + 1});
        }
    }

    cout << result + 1 << endl;

    return 0;
}