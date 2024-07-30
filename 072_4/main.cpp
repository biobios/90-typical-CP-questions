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

uint64_t calcBit(uint64_t i, uint64_t j, uint64_t W)
{
    return i * W + j;
}

bool hasBeen(uint64_t s, uint64_t u, uint64_t v)
{
    return (((s >> u) & 1) != 0) && (((s >> v) & 1) == 0);
}

int main()
{
    uint64_t H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for (auto &&row : grid)
    {
        for (auto &&node : row)
        {
            cin >> node;
        }
    }

    uint64_t result = 0;
    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            if (grid[i][j] == '#')
                continue;

            //             i         j      hasbeen     length
            stack<tuple<uint64_t, uint64_t, uint64_t, uint64_t>> S;
            S.push({i, j, 0, 0});
            while (!S.empty())
            {
                auto [y, x, hasbeen_flag, length] = S.top();
                S.pop();
                if (i == y && j == x && result < length)
                {
                    result = length;
                    continue;
                }
                uint64_t u = 0b1 << calcBit(y, x, W);
                if ((hasbeen_flag & u) != 0)
                {
                    continue;
                }
                hasbeen_flag |= u;

                if (y > 0 && grid[y - 1][x] != '#')
                {
                    S.push({y - 1, x, hasbeen_flag, length + 1});
                }
                if (x > 0 && grid[y][x - 1] != '#')
                {
                    S.push({y, x - 1, hasbeen_flag, length + 1});
                }
                if (y < H - 1 && grid[y + 1][x] != '#')
                {
                    S.push({y + 1, x, hasbeen_flag, length + 1});
                }
                if (x < W - 1 && grid[y][x + 1] != '#')
                {
                    S.push({y, x + 1, hasbeen_flag, length + 1});
                }
            }
        }
    }

    if (result < 3)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}