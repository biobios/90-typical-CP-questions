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
    uint64_t N, K;
    cin >> N >> K;
    map<uint64_t, uint64_t> calc;
    uint64_t current_num = N;
    for (; K != 0; K--)
    {
        if (calc.contains(current_num))
            break;

        uint64_t &next = calc[current_num];
        next += current_num;
        for (size_t i = 0; i < 5; i++)
        {
            next += current_num % 10;
            current_num /= 10;
        }
        next %= 100000;
        current_num = next;
    }

    if (K == 0)
    {
        cout << current_num << endl;
        return 0;
    }

    uint64_t loop_start = current_num;
    vector<uint64_t> loop;
    do
    {
        loop.push_back(current_num);
        current_num = calc[current_num];
    } while (loop_start != current_num);

    uint64_t result = loop[K % loop.size()];
    cout << result << endl;

    return 0;
}