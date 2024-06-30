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
    uint64_t N, K;
    cin >> N >> K;

    vector<uint64_t> Score(2 * N);

    for (size_t i = 0; i < N; i++)
    {
        uint64_t a, b;
        cin >> a >> b;
        Score[2 * i] = b;
        Score[2 * i + 1] = a - b;
    }

    sort(Score.rbegin(), Score.rend());

    uint64_t result = 0;
    for (size_t i = 0; i < K; i++)
    {
        result += Score[i];
    }

    cout << result << endl;

    return 0;
}