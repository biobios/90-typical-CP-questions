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

    uint64_t result = 0;
    if (H == 1 || W == 1)
    {
        result = H * W;
    }
    else
    {
        result = ((H + 1) / 2) * ((W + 1) / 2);
    }

    cout << result << endl;

    return 0;
}