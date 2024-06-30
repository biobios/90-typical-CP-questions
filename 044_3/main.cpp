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
    uint64_t N, Q;
    cin >> N >> Q;

    vector<uint64_t> A(N);
    for (uint64_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    uint64_t current_base = 0;

    for (size_t i = 0; i < Q; i++)
    {
        uint64_t T, X, Y;
        cin >> T >> X >> Y;

        if (T == 1)
        {
            uint64_t temp = A[(X - 1 + current_base) % N];
            A[(X - 1 + current_base) % N] = A[(Y - 1 + current_base) % N];
            A[(Y - 1 + current_base) % N] = temp;
        }
        else if (T == 2)
        {
            current_base = (current_base + N - 1) % N;
        }
        else
        {
            cout << A[(X - 1 + current_base) % N] << endl;
        }
    }

    return 0;
}