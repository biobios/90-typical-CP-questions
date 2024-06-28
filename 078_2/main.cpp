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
    uint64_t N, M;
    cin >> N >> M;

    vector<uint64_t> C(N);
    for (size_t i = 0; i < M; i++)
    {
        uint64_t a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a > b)
        {
            C[a]++;
        }
        else
        {
            C[b]++;
        }
    }

    uint64_t result = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (C[i] == 1)
            result++;
    }

    cout << result << endl;

    return 0;
}