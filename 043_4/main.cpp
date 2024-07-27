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
    uint64_t H, W;
    cin >> H >> W;

    uint64_t rs, cs;
    cin >> rs >> cs;
    rs--, cs--;
    uint64_t rt, ct;
    cin >> rt >> ct;
    rt--, ct--;

    vector<vector<char>> grid(H, vector<char>(W));
    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<uint64_t>> costs(H, vector<uint64_t>(W, -1ull));
    using node_t = tuple<uint64_t, uint64_t, uint64_t, uint64_t>;
    priority_queue<node_t, vector<node_t>, greater<node_t>> q;
    q.push({0, rs, cs, 0b10000});
    while (!q.empty())
    {
        auto [cost, i, j, direction] = q.top();
        q.pop();
        if (cost > costs[i][j])
            continue;

        costs[i][j] = cost;

        uint64_t new_cost;

        if (i > 0 && grid[i - 1][j] != '#' && ((direction & 0b0100) == 0))
        {
            new_cost = cost;
            if ((direction & 0b10001) == 0)
            {
                new_cost++;
            }
            q.push({new_cost, i - 1, j, 0b0001});
        }
        if (j > 0 && grid[i][j - 1] != '#' && ((direction & 0b1000) == 0))
        {
            new_cost = cost;
            if ((direction & 0b10010) == 0)
            {
                new_cost++;
            }
            q.push({new_cost, i, j - 1, 0b0010});
        }
        if (i < H - 1 && grid[i + 1][j] != '#' && ((direction & 0b0001) == 0))
        {
            new_cost = cost;
            if ((direction & 0b10100) == 0)
            {
                new_cost++;
            }
            q.push({new_cost, i + 1, j, 0b0100});
        }
        if (j < W - 1 && grid[i][j + 1] != '#' && ((direction & 0b0010) == 0))
        {
            new_cost = cost;
            if ((direction & 0b11000) == 0)
            {
                new_cost++;
            }
            q.push({new_cost, i, j + 1, 0b1000});
        }
    }

    cout << costs[rt][ct] << endl;
    return 0;
}