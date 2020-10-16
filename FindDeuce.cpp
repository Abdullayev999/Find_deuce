#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    cout << R"(    Welcome to the game - <<Find a deuce>>

    Rules of the game :

1) Array must be at least 4 characters
2) You have 3 attempts to refuse a number 2
3) You cannot go beyond the size of the array

    Good luck
)";
    int sizeRows,      //  размер строки и столбца динамического массива
        sizeCols,

        iRand,         //  размер 1-ого рандомного элемента в массива
        jRand,

        col,           //  для поиска значение в массиве
        row,

        counter = 3;   //  счетчик для 3-ёх попыток

    srand(time(nullptr));

    cout << "\nEnter rows size - \n";
    cin >> sizeRows;

    cout << "Enter cols size - \n";
    cin >> sizeCols;

    int sum = sizeCols + sizeRows;
    if ((sum <= 3))
    {
        cout << "Array size is too small to play\n";
        return -1;
    }
    else if (sizeRows == 0)
    {
        cout << "Row size cannot be 0 \n";
        return -1;
    }
    else if (sizeCols == 0)
    {
        cout << "Col size cannot be 0 \n";
        return -1;
    }

    int** arr = new int* [sizeRows];

    for (size_t i = 0; i < sizeRows; i++)
    {
        arr[i] = new int[sizeCols];

        for (size_t j = 0; j < sizeCols; j++)
        {
            arr[i][j] = rand();
        }
    }

    iRand = rand() % sizeRows;
    jRand = rand() % sizeCols;

    arr[iRand][jRand] = 2;

    enum { EASY, NORMAL, HARD };

    int action;
    cout << "Select game level\n";
    cout << "Easy - " << EASY << "\nNormal - " << NORMAL << "\nHard - " << HARD << endl;

    cin >> action;

    if (action == EASY)
    {
        cout << "You have selected EASY level\n\n";
        cout << "Number is in column - " << jRand << endl;

        for (size_t i = 0; i < sizeRows; i++)
        {
            for (size_t j = 0; j < sizeCols; j++)
            {

                cout << "    |";

                if (arr[i][j] % 2 == 0)
                {
                    cout << "_+_";
                }
                else {

                    cout << "___";
                }
                cout << "|    ";
            }
            cout << endl;
        }
    }
    else if (action == NORMAL)
    {
        cout << "You have selected NORMAL level\n\n";
        cout << "Number is in\n\n";
        for (size_t i = 0; i < sizeRows; i++)
        {
            for (size_t j = 0; j < sizeCols; j++)
            {

                cout << "    |";

                if (arr[i][j] % 2 == 0)
                {
                    cout << "_+_";
                }
                else {

                    cout << "___";
                }
                cout << "|    ";
            }
            cout << endl;
        }
    }
    else if (action == HARD)
    {
        cout << "You have selected HARD level\n\n";
        for (size_t i = 0; i < sizeRows; i++)
        {
            for (size_t j = 0; j < sizeCols; j++)
            {

                cout << "    |";
                cout << "___";
                cout << "|    ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Incorrect choice";
        return 0;
    }

    while (counter != 0)
    {
        cout << "Find the number 2\n" << "You have " << counter << " attempts\n\n";

        cout << "Enter row - ";
        cin >> row;
        if (row >= sizeRows)
        {
            cout << "You are out of size array";
            break;
        }

        cout << "Enter col - ";
        cin >> col;
        if (col >= sizeCols)
        {
            cout << "You are out of size array";
            break;
        }

        if (arr[row][col] == arr[iRand][jRand]) {
            cout << "You win!!!!\n";
            break;
        }
        else {
            cout << "wrong\n\n";
        }
        counter--;
        if (counter == 0)
        {
            cout << "Game over";
        }
    }


    for (size_t i = 0; i < sizeRows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}
