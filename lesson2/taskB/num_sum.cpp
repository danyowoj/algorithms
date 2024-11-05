#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarraysWithSumK(const vector<int> &A, int K)
{
    int count = 0;
    int currentSum = 0;

    // hash table for storing the number of sums encountered
    unordered_map<int, int> sumCount;
    sumCount[0] = 1; // for the case when the current sum is K

    for (int num : A)
    {
        currentSum += num; // updating current sum

        // checking if there was a difference (currentSum - K) in the hash table
        count += sumCount[currentSum - K];

        // increasing the counter of the current sum in the hash table
        sumCount[currentSum]++;
    }

    return count;
}

int main()
{
    int N; // amount of cars
    int K; // lucky number
    std::cin >> N >> K;

    std::vector<int> carNumbers(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> carNumbers[i];
    }

    int result = countSubarraysWithSumK(carNumbers, K);

    cout << result << endl;

    return 0;
}
