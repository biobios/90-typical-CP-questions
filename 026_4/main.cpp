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

    vector<vector<size_t>> connection(N);

    for (size_t i = 0; i < N - 1; i++)
    {
        uint64_t A, B;
        cin >> A >> B;
        A--, B--;
        connection[A].push_back(B);
        connection[B].push_back(A);
    }

    stack<tuple<size_t, size_t, bool>> S;
    vector<size_t> A;
    vector<size_t> B;
    S.push({0, 0, true});
    while (!S.empty())
    {
        auto [prev, current, parity] = S.top();
        S.pop();
        for (auto &&next : connection[current])
        {
            if (next == prev)
                continue;

            S.push({current, next, !parity});
            if (parity)
                A.push_back(next);
            else
                B.push_back(next);
        }
    }

    if (A.size() > B.size())
    {
        for (size_t i = 0; i < N / 2; i++)
        {
            cout << A[i] + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        for (size_t i = 0; i < N / 2; i++)
        {
            cout << B[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}