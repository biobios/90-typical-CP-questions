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

    set<string> registered;
    for (size_t i = 1; i <= N; i++)
    {
        string S;
        cin >> S;
        if (!registered.contains(S))
        {
            cout << i << endl;
            registered.insert(S);
        }
    }

    return 0;
}