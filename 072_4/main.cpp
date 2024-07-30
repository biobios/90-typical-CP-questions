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

    int64_t result = 0;
    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            if (grid[i][j] == '#')
                continue;

            vector<vector<int64_t>> costs(pow(2, H * W), vector<int64_t>(H * W, -10000));
            costs[1 << calcBit(i, j, W)][calcBit(i, j, W)] = 0;
            for (uint64_t s = 0; s < pow(2, H * W); s++)
                for (size_t y = 0; y < H; y++)
                    for (size_t x = 0; x < W; x++)
                    {
                        uint64_t u = y * W + x;
                        if (y > 0 && grid[y - 1][x] != '#')
                        {
                            uint64_t v = calcBit(y - 1, x, W);
                            if (hasBeen(s, u, v))
                            {
                                uint64_t ns = s | (1 << v);
                                costs[ns][v] = max(costs[ns][v], costs[s][u] + 1);
                            }
                        }
                        if (x > 0 && grid[y][x - 1] != '#')
                        {
                            uint64_t v = calcBit(y, x - 1, W);
                            if (hasBeen(s, u, v))
                            {
                                uint64_t ns = s | (1 << v);
                                costs[ns][v] = max(costs[ns][v], costs[s][u] + 1);
                            }
                        }
                        if (y < H - 1 && grid[y + 1][x] != '#')
                        {
                            uint64_t v = calcBit(y + 1, x, W);
                            if (hasBeen(s, u, v))
                            {
                                uint64_t ns = s | (1 << v);
                                costs[ns][v] = max(costs[ns][v], costs[s][u] + 1);
                            }
                        }
                        if (x < W - 1 && grid[y][x + 1] != '#')
                        {
                            uint64_t v = calcBit(y, x + 1, W);
                            if (hasBeen(s, u, v))
                            {
                                uint64_t ns = s | (1 << v);
                                costs[ns][v] = max(costs[ns][v], costs[s][u] + 1);
                            }
                        }
                    }

            for (uint64_t s = 0; s < pow(2, H * W); s++)
            {
                if (i > 0)
                {
                    uint64_t u = calcBit(i - 1, j, W);
                    if (costs[s][u] + 1 > result)
                        result = costs[s][u] + 1;
                }
                if (j > 0)
                {
                    uint64_t u = calcBit(i, j - 1, W);
                    if (costs[s][u] + 1 > result)
                        result = costs[s][u] + 1;
                }
                if (i < H - 1)
                {
                    uint64_t u = calcBit(i + 1, j, W);
                    if (costs[s][u] + 1 > result)
                        result = costs[s][u] + 1;
                }
                if (j < W - 1)
                {
                    uint64_t u = calcBit(i, j + 1, W);
                    if (costs[s][u] + 1 > result)
                        result = costs[s][u] + 1;
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