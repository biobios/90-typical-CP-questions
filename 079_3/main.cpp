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

    vector<vector<int64_t>> grid(H, vector<int64_t>(W));

    for (size_t y = 0; y < H; y++)
    {
        for (size_t x = 0; x < W; x++)
        {
            cin >> grid[y][x];
        }
    }

    for (size_t y = 0; y < H; y++)
    {
        for (size_t x = 0; x < W; x++)
        {
            uint64_t b;
            cin >> b;
            grid[y][x] -= b;
        }
    }

    vector<int64_t> filter(W);
    uint64_t result = 0;

    for (size_t y = 0; y < H - 1; y++)
    {
        vector<int64_t> next(W);
        for (size_t x = 0; x < W - 1; x++)
        {
            int64_t diff = grid[y][x] - filter[x];
            result += abs(diff);
            filter[x + 1] += diff;
            next[x] += diff;
            next[x + 1] = diff;
        }

        if (filter[W - 1] != grid[y][W - 1])
        {
            cout << "No" << endl;
            return 0;
        }

        filter = next;
    }

    for (size_t x = 0; x < W; x++)
    {
        if (filter[x] != grid[H - 1][x])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << result << endl;

    return 0;
}