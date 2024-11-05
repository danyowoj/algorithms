#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, R;
    cin >> N >> R;

    vector<int> statueDistance(N);
    for (int i = 0; i < N; i++)
    {
        cin >> statueDistance[i];
    }

    long long counter = 0; // Изменили тип на long long для предотвращения переполнения
    for (int i = N - 1; i > 0; --i)
    {
        int j = i;
        while (j < i && statueDistance[i] - statueDistance[j] <= R)
        {
            j++;
        }
        counter += N + j;
    }

    cout << counter << endl;
    return 0;
}
