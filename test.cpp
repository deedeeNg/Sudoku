// SudokuDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <string>
#include <windows.h>
#include "Algorithm.cpp"
#include <iomanip>
#include <Windows.h>

using namespace std;

string Grid[19][19];
Board newBoard = MakeBoard();
int hours = 0, minutes = 0, seconds = 0;

void printSudokuLogo()
{
    cout << "\x1b[32m **  \x1b[31m  *   * \x1b[32m  * * *   \x1b[31m   * *  \x1b[32m  *   *  \x1b[31m  *   *             *   * \x1b[37m" << endl;
    cout << "\x1b[32m*  * \x1b[31m  *   * \x1b[32m  *    *   \x1b[31m*     * \x1b[32m *  *    \x1b[31m *   *             *   * \x1b[37m" << endl;
    cout << "\x1b[32m *    \x1b[31m *   * \x1b[32m  *     *  \x1b[31m*     * \x1b[32m * *     \x1b[31m *   *             *   * \x1b[37m" << endl;
    cout << "\x1b[32m  *   \x1b[31m *   *  \x1b[32m *     *  \x1b[31m*     * \x1b[32m * *    \x1b[31m  *   * \x1b[32m *   *   * \x1b[31m *   * \x1b[37m" << endl;
    cout << "\x1b[32m*  *  \x1b[31m *   *  \x1b[32m *    *   \x1b[31m*     *  \x1b[32m*   *   \x1b[31m *   * \x1b[32m  * * * *  \x1b[31m *   * \x1b[37m" << endl;
    cout << "\x1b[32m **   \x1b[31m  * *   \x1b[32m * * *     \x1b[31m * *    \x1b[32m*     * \x1b[31m  * *   \x1b[32m  *   *    \x1b[31m * * \x1b[37m" << endl << endl;
}
void printUwU()
{
    cout << "                .         `            `         `" << endl;
    cout << "               /y        :y.          .h:        +:" << endl;
    cout << "               yh        oN-          -No        yy" << endl;
    cout << "               sm`       dN`          `Nd       `Ny" << endl;
    cout << "               .mh.    .yN+            +Ny.    .hm." << endl;
    cout << "          `----..+hdyydmy-  ``      ``  -ymdyydh+..----`" << endl;
    cout << "        `//+++++/- `..`     +o  ..  o+     `..` :+////++/`" << endl;
    cout << "        -+/+++++++.         -d++hy++d-         .++//////+-" << endl;
    cout << "        .////++++/`          `--``--`          ./////////." << endl;
    cout << "         `-:////:.                              `://///:`" << endl;
    cout << "            ````                                  `````" << endl << endl;
}
void rules()
{
    system("CLS");
    /// <summary>
    cout << "                     Game Rules" << endl;
    cout << "1. Within the rows and columns are 9 squares (3x3 spaces)\n2. Each rows and columns needs to be filled out with the numbers \n1-9 without repeating numbers within the rows or columns\n";

    /// </summary>
    system("pause");
} // Nguyen

//void generate_sudoku(Board b);

/*
void checkSolution();
void playAgain();
void showSolution();*/

void displayClock()
{
    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n";
}

void Timer()
{
    while (true)
    {
        system("CLS");
        displayClock();
        Sleep(1000);
        seconds++;
        if (seconds == 60)
        {
            seconds = 0;
            minutes++;
            if (minutes == 60)
            {
                minutes == 0;
                hours++;
            }
        }
    }
}

void PrintNumber(int row, int col, int num)
{
    Grid[(row - 1) * 2 + 1][(col - 1) * 2 + 1] = to_string(num);
}
void GridCreating()
{
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            Grid[i][j] = " ";
}
void generate_sudoku()
{
    system("CLS");
    for (int i = 1; i < 18; i += 2)
        for (int j = 0; j <= 18; j += 2)
        {
            Grid[i][j] = "|";
        }
    for (int i = 0; i <= 18; i += 2)
        for (int j = 1; j < 18; j += 2)
        {
            Grid[i][j] = "=";
        }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (newBoard[i][j] != 0)
                PrintNumber(i + 1, j + 1, newBoard[i][j]);
        }
    }

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++) {
            if (Grid[i][j] != "|" && Grid[i][j] != "=") {
                cout << "\x1b[33m" << Grid[i][j] << "\x1b[37m";
            }
            else {
                cout << Grid[i][j];
            }
        }
        cout << endl;
    }

    bool check = true;
    int row, column, number;
    while (check)
    {
        cout << "Enter the number of Row, Column and Number" << endl;
        cin >> row >> column >> number;
        PrintNumber(row, column, number);
        generate_sudoku();
    }
    system("pause");
}
void playInterface()
{
    system("CLS");
    printUwU();
    cout << "Choose the level you want to UwU" << endl;
    cout << "1_Easy" << endl;
    cout << "2_Normal" << endl;
    cout << "3_Hard" << endl;
    int NumberMode;
    cout << "Your number is: ";
    cin >> NumberMode;
    if (NumberMode == 1)
    {
        newBoard = EasyMode();
        GridCreating();
        generate_sudoku();
    }
    if (NumberMode == 2)
    {
        newBoard = NormalMode();
        GridCreating();
        generate_sudoku();
    }
    if (NumberMode == 3)
    {
        newBoard = HardMode();
        GridCreating();
        generate_sudoku();
    }
}
void ExitMenu()
{
    system("CLS");
    printUwU();
    cout << "Thank you for playing our game UwU" << endl;
    system("pause");
}

void start_menu()
{
    bool check = true;
    while (check)
    {
        system("CLS");

        printSudokuLogo();
        printUwU();

        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = 0;  // Width of each character in the font
        cfi.dwFontSize.Y = 24; // Height
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;
        wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

        cout << "                       Welcome to SudokUwU" << endl;
        //cout << "(´꒳`)" << endl;
        cout << "                             1_Rules " << endl;
        cout << "                             2_Play" << endl;
        cout << "                             3_Exit" << endl;
        cout << "                        Enter your Number: ";
        int NUMBER;
        cin >> NUMBER;
        if (NUMBER == 1)
        {
            rules();
        }
        if (NUMBER == 2)
        {
            playInterface();
        }
        if (NUMBER == 3)
        {
            check = false;
            ExitMenu();
        }
    }
}

int main()
{
    start_menu();
    return 0;
}
