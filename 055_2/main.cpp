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
    uint64_t N, P, Q;
    cin >> N >> P >> Q;
    vector<uint64_t> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    uint64_t result = 0;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            for (size_t k = j + 1; k < N; k++)
            {
                for (size_t l = k + 1; l < N; l++)
                {
                    for (size_t m = l + 1; m < N; m++)
                    {
                        if (A[i] * A[j] % P * A[k] % P * A[l] % P * A[m] % P == Q)
                        {
                            result++;
                        }
                    }
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}