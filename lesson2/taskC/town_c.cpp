#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; // amount of statues
    int R; // max distance to see
    std::cin >> N >> R;

    // a vector if distance from the street start
    std::vector<int> statueDistance(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> statueDistance[i];
    }

    long long counter = 0;

    int last = 0;
    for (int first = 0; first < N; first++)
    {
        while (last < N && statueDistance[last] - statueDistance[first] <= R)
            last++;
        counter += N - last;
    }

    cout << counter << endl;

    return 0;
}
