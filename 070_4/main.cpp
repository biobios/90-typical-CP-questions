#include <iostream>
#include <vector>
#include <array>
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

    vector<int64_t> X(N);
    vector<int64_t> Y(N);

    int64_t sum_X = 0;
    int64_t sum_Y = 0;

    for (size_t i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
        sum_X += X[i];
        sum_Y += Y[i];
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int64_t X_L_sum = 0;
    int64_t Y_L_sum = 0;
    for (size_t i = 0; i < N / 2; i++)
    {
        X_L_sum += X[i];
        Y_L_sum += Y[i];
    }

    uint64_t result = abs((int64_t)(N / 2 * X[N / 2] - X_L_sum)) + abs((int64_t)(sum_X - X_L_sum - (N + 1) / 2 * X[N / 2]));
    result += abs((int64_t)(N / 2 * Y[N / 2] - Y_L_sum)) + abs((int64_t)(sum_Y - Y_L_sum - (N + 1) / 2 * Y[N / 2]));

    cout << result << endl;
    return 0;
}