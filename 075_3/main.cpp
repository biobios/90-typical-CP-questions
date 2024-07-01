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

    uint64_t sqrt_N = sqrt(N);
    uint64_t count = 1;
    for (uint64_t i = 2; i <= sqrt_N; i++)
    {
        if (N % i == 0)
        {
            count++;
            N /= i;
            sqrt_N = sqrt(N);
            i--;
        }
    }

    uint64_t result = ceil(log2(count));

    cout << result << endl;

    return 0;
}