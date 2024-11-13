/* Для одного типа скобок:
В цикле проходимся по введенной строке
 При каждой открывающейся скобке "(" добавляем +1 к Балансу
 При каждой закрывающейся скобке ")" отнимаем -1 от Баланса
 Как только Баланс стал отрицаиельным, выходим из цикла с ощибкой
 Если на момент конца строки баланс положительный, выводим ошибку
 Если на конец цикла Баланс равен нуля, выводим успех */

/* Для нескольких типов скобок:
Открывающие скобки кладем в стек
Встретили закрывающую - проверили, что стек не пуст, на вершине стека лежит соответствующая открывающая, убрали ее
В конце стек должен оказаться пустым
Если мы пытаемся вытащить эелемент из пустого стека - выводим no
*/
#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::string input;
    std::cin >> input;
    std::stack<int> backlog;

    for (int i = 0; i < (int)input.length(); i++)
    {
        switch (input[i])
        {
        case '(':
            backlog.push('(');
            break;
        case '[':
            backlog.push('[');
            break;
        case '{':
            backlog.push('{');
            break;
        case ')':
            if (!backlog.empty() && backlog.top() == '(')
            {
                backlog.pop();
                break;
            }
            std::cout << "no" << std::endl;
            return 0;
        case ']':
            if (!backlog.empty() && backlog.top() == '[')
            {
                backlog.pop();
                break;
            }
            std::cout << "no" << std::endl;
            return 0;
        case '}':
            if (!backlog.empty() && backlog.top() == '{')
            {
                backlog.pop();
                break;
            }
            std::cout << "no" << std::endl;
            return 0;
        default:
            std::cout << "yes" << std::endl;
        }
    }

    if (backlog.empty())
    {
        std::cout << "yes" << std::endl;
        return 0;
    }
    std::cout << "no" << std::endl;
    return 0;
}
