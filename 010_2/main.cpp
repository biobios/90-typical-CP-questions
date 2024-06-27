#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    uint64_t N;
    cin >> N;
    vector<pair<uint64_t, uint64_t>> C_1;
    vector<pair<uint64_t, uint64_t>> C_2;

    C_1.push_back({0, 0});
    C_2.push_back({0, 0});

    for (size_t i = 1; i <= N; i++)
    {
        uint64_t C, P;
        cin >> C >> P;
        if (C == 1)
        {
            C_1.push_back({i, P + C_1.back().second});
        }
        else
        {
            C_2.push_back({i, P + C_2.back().second});
        }
    }

    uint64_t Q;
    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        uint64_t L, R;
        cin >> L >> R;
        pair<uint64_t, uint64_t> L_pair(L, 0);
        pair<uint64_t, uint64_t> R_pair(R + 1, 0);
        auto &&l_1 = lower_bound(C_1.begin(), C_1.end(), L_pair); // >= L. l_r-- < L
        auto &&r_1 = lower_bound(l_1, C_1.end(), R_pair);         // >= R + 1. r_1-- <= R
        auto &&l_2 = lower_bound(C_2.begin(), C_2.end(), L_pair);
        auto &&r_2 = lower_bound(l_2, C_2.end(), R_pair);

        l_1--;
        r_1--;
        l_2--;
        r_2--;

        uint64_t sum_1 = r_1->second - l_1->second;
        uint64_t sum_2 = r_2->second - l_2->second;

        cout << sum_1 << " " << sum_2 << endl;
    }
    return 0;
}