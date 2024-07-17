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
    vector<vector<int64_t>> grid(1001, vector<int64_t>(1001, 0));
    for (size_t i = 0; i < N; i++)
    {
        uint64_t lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        grid[lx][ly] += 1;
        grid[rx][ry] += 1;
        grid[lx][ry] -= 1;
        grid[rx][ly] -= 1;
    }

    for (size_t i = 0; i < 1001; i++)
    {
        int64_t sum = 0;
        for (size_t j = 0; j < 1001; j++)
        {
            sum += grid[i][j];
            grid[i][j] = sum;
        }
    }

    vector<uint64_t> result(N + 1, 0);

    for (size_t i = 0; i < 1001; i++)
    {
        int64_t sum = 0;
        for (size_t j = 0; j < 1001; j++)
        {
            sum += grid[j][i];
            result[sum]++;
        }
    }

    for (size_t i = 1; i <= N; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}