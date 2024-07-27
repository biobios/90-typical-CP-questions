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
    uint64_t H, W;
    cin >> H >> W;
    vector<vector<uint64_t>> grid(H, vector<uint64_t>(W, 0));
    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            cin >> grid[i][j];
        }
    }

    uint64_t result = 0;
    uint64_t finding_bits = pow(2, H) - 1;
    for (; finding_bits > 0; finding_bits--)
    {
        vector<size_t> finding_index;
        for (uint64_t finding_bit = 0b1, i = 0; i < H; finding_bit <<= 1, i++)
        {
            if ((finding_bits & finding_bit) == 0)
                continue;
            finding_index.push_back(i);
        }
        map<uint64_t, uint64_t> count;
        for (size_t j = 0; j < W; j++)
        {
            bool same = true;
            uint64_t num = grid[finding_index[0]][j];
            for (size_t i = 1; i < finding_index.size(); i++)
            {
                if (num != grid[finding_index[i]][j])
                {
                    same = false;
                    break;
                }
            }
            if (same)
                count[num] += finding_index.size();
        }

        for (auto [key, c] : count)
        {
            if (result < c)
                result = c;
        }
    }

    cout << result << endl;

    return 0;
}