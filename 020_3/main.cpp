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
    uint64_t a, b, c;

    cin >> a >> b >> c;

    uint64_t powered_c = c;

    for (size_t i = 0; i < b; i++)
    {
        if (a < powered_c)
        {
            cout << "Yes" << endl;
            return 0;
        }
        powered_c *= c;
    }

    cout << "No" << endl;
    return 0;
}