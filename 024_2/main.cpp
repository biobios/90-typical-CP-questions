#include <iostream>
#include <vector>

using namespace std;

int main()
{
    uint64_t N, K;
    cin >> N >> K;

    vector<uint64_t> A(N);
    vector<uint64_t> B(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (size_t i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    uint64_t def_sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        uint64_t a = A[i];
        uint64_t b = B[i];
        if (a > b)
            def_sum += a - b;
        else
            def_sum += b - a;
    }

    if (def_sum > K)
    {
        cout << "No" << endl;
        return 0;
    }

    if ((K - def_sum) % 2 != 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}