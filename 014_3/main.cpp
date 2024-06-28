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

    vector<uint64_t> B(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    uint64_t result = 0;

    for (size_t i = 0; i < N; i++)
    {
        uint64_t a = A[i];
        uint64_t b = B[i];
        uint64_t def;
        if (a > b)
        {
            def = a - b;
        }
        else
        {
            def = b - a;
        }

        result += def;
    }

    cout << result << endl;

    return 0;
}