#include <iostream>
#include <vector>

using namespace std;

int main()
{
    uint64_t H, W;
    cin >> H >> W;
    vector<uint64_t> horizontal(H);
    vector<uint64_t> vertical(W);
    vector<vector<uint64_t>> grid(H, vector<uint64_t>(W));

    for (size_t y = 0; y < H; y++)
    {
        for (size_t x = 0; x < W; x++)
        {
            cin >> grid[y][x];
            horizontal[y] += grid[y][x];
            vertical[x] += grid[y][x];
        }
    }

    for (size_t y = 0; y < H; y++)
    {
        for (size_t x = 0; x < W; x++)
        {
            cout << (horizontal[y] + vertical[x] - grid[y][x]) << " ";
        }
        cout << endl;
    }
    return 0;
}