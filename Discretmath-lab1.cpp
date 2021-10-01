#include<iostream>
#include <Windows.h>
using namespace std;

bool bNOT(bool const b1, bool const b2)     // bNOT - denial.
{

    if (b1 == true && b2 == true) return false;
    else return true;
}

bool bAnd(bool const b1, bool const b2)     // bAnd - logical and.
{
    if (b1 == true && b2 == true) return true;
    else return false;
}

bool bImpl(bool const b1, bool const b2)     // bImpl - implication.
{
    if (b1 == true && b2 == false) return false;
    else return true;
}

const char* GetBoolString(bool const b)
{
    return b ? "T" : "F";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string expression;

    expression = "(x -> (y -> z)) -> ((x ^ y) -> z)";

    cout << "Expression: " << expression << endl;
    cout << "Steps: " << endl;

    bool v1;
    bool v2;
    bool v3;
    bool v4;
    bool v5;
    bool v6;
    bool v7;

    cout << "1| !y" << endl;
    cout << "2| !z" << endl;
    cout << "3| y -> z" << endl;
    cout << "4| x -> (y -> z)" << endl;
    cout << "5| x ^ y" << endl;
    cout << "6| (x ^ y) -> z" << endl;
    cout << "7| (x -> (y -> z)) -> ((x ^ y) -> z)" << endl;


    for (size_t x = 0; x < 2; x++)
    {
        for (size_t y = 0; y < 2; y++)
        {
            for (size_t z = 0; z < 2; z++)
            {
                cout << x << " ";
                cout << y << " ";
                cout << z << "    ";

                cout << "|";
                v1 = bImpl(y, z); cout << v1 << "|";
                v2 = bImpl(x, v1); cout << v2 << "|";
                v3 = bAnd(x, y); cout << v3 << "|";
                v4 = bImpl(v3, z); cout << v4 << "|";
                v5 = bImpl(v2, v4); cout << v5 << "|";
                v6 = bNOT(y, y); cout << v6 << "|";
                cout << endl;
            }
        }
    }

    cout << endl;
    system("pause");

    return 0;
}