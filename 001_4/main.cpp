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
#include <list>

using namespace std;

int main()
{
    uint64_t N, L;
    cin >> N >> L;
    uint64_t K;
    cin >> K;

    vector<uint64_t> A(N);
    for (auto &&a : A)
    {
        cin >> a;
    }

    uint64_t piece_size_min = 1;
    uint64_t piece_size_max = L / (K + 1);

    while (piece_size_max != piece_size_min)
    {
        uint64_t piece_size_avg = (piece_size_min + piece_size_max) / 2;
        uint64_t prev_x = 0;
        uint64_t piece_count = 0;
        for (size_t i = 0; i < N; i++)
        {
            if (A[i] - prev_x > piece_size_avg)
            {
                piece_count++;
                prev_x = A[i];
            }

            if (piece_count >= K)
                break;
        }
        if (L - prev_x > piece_size_avg && piece_count >= K)
        {
            piece_size_min = piece_size_avg + 1;
        }
        else
        {
            piece_size_max = piece_size_avg;
        }
    }

    cout << piece_size_max << endl;

    return 0;
}