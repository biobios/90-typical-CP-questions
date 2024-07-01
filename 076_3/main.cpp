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
    vector<uint64_t> Sum_A(N);
    cin >> Sum_A[0];
    for (size_t i = 1; i < N; i++)
    {
        cin >> Sum_A[i];
        Sum_A[i] += Sum_A[i - 1];
    }

    if (Sum_A[N - 1] % 10 != 0 || N == 1)
    {
        cout << "No" << endl;
        return 0;
    }

    uint64_t one_tenth = Sum_A[N - 1] / 10;
    uint64_t r = 0;

    for (size_t i = 0; i < N; i++)
    {
        uint64_t l_A = Sum_A[i];
        while (true)
        {
            uint64_t r_A = Sum_A[r % N];
            if (r_A < l_A)
                r_A += Sum_A[N - 1];
            if (r_A - l_A > one_tenth)
                break;

            if (r_A - l_A == one_tenth)
            {
                cout << "Yes" << endl;
                return 0;
            }

            r++;
        }
    }

    cout << "No" << endl;
    return 0;
}