#include <iostream>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
    while (b != 0)
    {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    uint64_t A, B, C;
    cin >> A >> B >> C;

    uint64_t gcd_abc = gcd(gcd(A, B), C);
    uint64_t result = 0;

    result += A / gcd_abc - 1;
    result += B / gcd_abc - 1;
    result += C / gcd_abc - 1;

    cout << result << endl;
    return 0;
}