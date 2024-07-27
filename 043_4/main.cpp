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
#include <array>

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

    vector<vector<array<uint64_t, 4>>> costs(H, vector<array<uint64_t, 4>>(W, array<uint64_t, 4>{-1ull, -1ull, -1ull, -1ull}));
    //                     cost       i        j         direction
    using node_t = tuple<uint64_t, uint64_t, uint64_t, uint64_t>;
    priority_queue<node_t, vector<node_t>, greater<node_t>> q;
    q.push({0, rs, cs, 0});
    q.push({0, rs, cs, 1});
    q.push({0, rs, cs, 2});
    q.push({0, rs, cs, 3});
    while (!q.empty())
    {
        auto [cost, i, j, direction] = q.top();
        q.pop();
        if (cost >= costs[i][j][direction])
            continue;

        for (auto &&c : costs[i][j])
        {
            c = min(c, cost + 1);
        }

        costs[i][j][direction] = cost;

        if (i > 0 && grid[i - 1][j] != '#' && direction != 2)
        {
            q.push({costs[i][j][0], i - 1, j, 0});
        }
        if (j > 0 && grid[i][j - 1] != '#' && direction != 3)
        {
            q.push({costs[i][j][1], i, j - 1, 1});
        }
        if (i < H - 1 && grid[i + 1][j] != '#' && direction != 0)
        {
            q.push({costs[i][j][2], i + 1, j, 2});
        }
        if (j < W - 1 && grid[i][j + 1] != '#' && direction != 1)
        {
            q.push({costs[i][j][3], i, j + 1, 3});
        }
    }

    sort(costs[rt][ct].begin(), costs[rt][ct].end());

    cout << costs[rt][ct][0] << endl;
    return 0;
}