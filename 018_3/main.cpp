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
#include <numbers>
#include <iomanip>

using namespace std;

int main()
{
    uint64_t T;
    cin >> T;
    uint64_t L, X, Y;
    cin >> L >> X >> Y;
    uint64_t Q;
    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        uint64_t E;
        cin >> E;

        double rot = 2 * numbers::pi * E / T;

        double g_y = -sin(rot) * L / 2;
        double g_z = -cos(rot) * L / 2 + (double)L / 2;
        double base = sqrt(X * X + (g_y - Y) * (g_y - Y));

        double degree = atan(g_z / base) / numbers::pi * 180;

        cout << fixed << setprecision(16) << degree << endl;
    }
}