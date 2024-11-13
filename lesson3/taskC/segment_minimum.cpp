#include <iostream>
#include <vector>
#include <deque>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    std::cout << std::endl;

    std::deque<int> dq;      // Дек для хранения индексов
    std::vector<int> result; // Вектор для хранения минимальных значений

    for (int i = 0; i < n; i++)
    {
        // Если индекс выходит за пределы окна
        if (!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front(); // удаляем его из начала дека

        // удаляем из дека элементы, которые больше текущего (arr[i])
        while (!dq.empty() && arr[dq.back()] > arr[i])
            dq.pop_back();

        // добавляем текущий индекс в дек
        dq.push_back(i);

        // если мы достигли размера окна
        if (i >= k - 1)
            // добавляем минимум в массив результата
            result.push_back(arr[dq.front()]);
    }

    // Вывод результата
    for (int min : result)
    {
        std::cout << min << std::endl;
    }

    return 0;
}
