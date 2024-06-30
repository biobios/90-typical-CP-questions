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
    uint64_t A, B;
    cin >> A >> B;

    uint64_t gcd = __gcd(A, B);
    uint64_t lcm = A / gcd * B;

    if (lcm > 1000000000000000000 || lcm / B != A / gcd)
    {
        cout << "Large" << endl;
    }
    else
    {
        cout << lcm << endl;
    }

    return 0;
}