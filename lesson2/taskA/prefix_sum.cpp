#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "File opening error!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    if (inputFile.fail() || n <= 0)
    {
        cerr << "An error reading the number of elements or an incorrect value of n." << endl;
        inputFile.close();
        return 1;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        if (!(inputFile >> a[i]))
        {
            cerr << "Error reading sequence elements." << endl;
            inputFile.close();
            return 1;
        }

    inputFile.close();

    for (int i = 0; i < n; i++)
    {
        int b = 0;
        for (int j = 0; j <= i; j++)
        {
            b += a[j];
        }
        cout << b << " ";
    }
    cout << endl;

    return 0;
}
