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
    vector<int64_t> A(N);
    uint64_t E = 0;
    cin >> A[0];
    for (size_t i = 1; i < N; i++)
    {
        cin >> A[i];
        if (A[i] > A[i - 1])
        {
            E += A[i] - A[i - 1];
        }
        else
        {
            E += A[i - 1] - A[i];
        }
    }

    for (size_t i = 0; i < Q; i++)
    {
        uint64_t L, R;
        int64_t V;
        cin >> L >> R >> V;
        L--;
        R--;
        if (L != 0)
        {
            int64_t def_prev = A[L] - A[L - 1];
            if (def_prev < 0)
                def_prev = -def_prev;
            int64_t after_a = A[L] + V;
            int64_t def_current = after_a - A[L - 1];
            if (def_current < 0)
                def_current = -def_current;
            E += def_current - def_prev;
        }
        if (R != N - 1)
        {
            int64_t def_prev = A[R] - A[R + 1];
            if (def_prev < 0)
                def_prev = -def_prev;
            int64_t after_a = A[R] + V;
            int64_t def_current = after_a - A[R + 1];
            if (def_current < 0)
                def_current = -def_current;
            E += def_current - def_prev;
        }
        for (size_t j = L; j <= R; j++)
        {
            A[j] += V;
        }

        cout << E << endl;
    }

    return 0;
}