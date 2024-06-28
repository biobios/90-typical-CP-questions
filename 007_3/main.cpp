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

    vector<uint64_t> A(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    uint64_t Q;
    cin >> Q;

    vector<pair<uint64_t, uint64_t>> B(Q);
    for (size_t i = 0; i < Q; i++)
    {
        uint64_t b;
        cin >> b;
        B[i] = {b, i};
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<uint64_t> result(Q);

    auto &&it = A.begin();
    for (size_t i = 0; i < Q; i++)
    {
        uint64_t b = B[i].first;
        it = lower_bound(it, A.end(), b);

        uint64_t def = -1ull;
        if (it != A.end())
            def = *it - b;
        if (it != A.begin())
            def = min(def, b - *(--it));

        result[B[i].second] = def;
    }

    for (size_t i = 0; i < Q; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}