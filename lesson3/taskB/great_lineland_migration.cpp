#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> cost(N);
    for (int i = 0; i < N; i++)
        std::cin >> cost[i];

    std::vector<int> result(N, -1); // Инициализируем результат -1
    std::stack<int> indexStack;     // Стек для хранения индексов

    for (int i = 0; i < N; i++)
    {
        // Пока стек не пуст и текущий элемент меньше элемента на вершине стека
        while (!indexStack.empty() && cost[indexStack.top()] > cost[i])
        {
            result[indexStack.top()] = i; // Сохраняем индекс меньшего элемента
            indexStack.pop();             // Убираем индекс из стека
        }
        indexStack.push(i); // Добавляем текущий индекс в стек
    }

    // Печатаем результаты
    for (int i = 0; i < N; i++)
    {
        std::cout << (result[i] != -1 ? result[i] : -1) << " ";
    }
    std::cout << std::endl;

    return 0;
}
