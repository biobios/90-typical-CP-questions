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
#include <deque>

using namespace std;

int main()
{
    uint64_t Q;
    cin >> Q;
    deque<uint64_t> A;
    for (size_t i = 0; i < Q; i++)
    {
        uint64_t t, x;
        cin >> t >> x;
        if (t == 1)
        {
            A.push_front(x);
        }
        else if (t == 2)
        {
            A.push_back(x);
        }
        else
        {
            cout << A[x - 1] << endl;
        }
    }

    return 0;
}