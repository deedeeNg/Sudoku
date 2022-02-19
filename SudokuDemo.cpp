// SudokuDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <string>
#include <windows.h>
#include <iomanip>
#include <Windows.h>
#include "Algorithm.h"

using namespace std;

string Grid[19][19];
Board newBoard = MakeBoard();
vector<Board> Solutions;
int hours = 0, minutes = 0, seconds = 0;
clock_t start, finish;

struct Time
{
    int minutes;
    int seconds;
};
int elapsed_time(clock_t start, clock_t finish) {
    // returns elapsed time in milliseconds
    return (finish - start) / (CLOCKS_PER_SEC);
}

Time changeTime(int sec)
{
    Time t;
    t.minutes = sec / 60;
    t.seconds = sec % 60;
    return t;
}
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
void playAgain();
void showSolution();*/

/*bool checkSolutions() // con` dang do?
{
    for (int i = 0; i < Solutions.size(); i++)
    {
        for (int j = 0; j < 9; j++)
            for (int k = 0; k < 9; k++)
            {
                if (to_string(Solutions[i][j][k]) == Grid[j * 2 + 1][k * 2 + 1]);
            }
    }
}*/

void CongratulationMenu()
{
    system("CLS");
    printUwU();
    cout << "Congratulation, you are a genius UwU" << endl;
    return;
}

bool checkInput(int num)
{
    if ((num <= 9) && (num >= 1))
        return true;
    else
        return false;
}

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
            if (Grid[i][j] != "|" && Grid[i][j] != "=") 
            {
                if (newBoard[(i - 1) / 2][(j - 1) / 2] != 0)
                    cout << "\x1b[33m" << Grid[i][j] << "\x1b[37m";
                else
                    cout << Grid[i][j];
            }
            else {
                cout << Grid[i][j];
            }
        }
        cout << endl;
    }

    int row, column, number;
    while (true)
    {
        finish = clock();
        cout << "Your time is: " << changeTime(elapsed_time(start, finish)).minutes << " Minutes " << changeTime(elapsed_time(start, finish)).seconds << " Seconds" << endl;
        cout << "Enter the number of Row, Column and Number" << endl;
        cout << "If you've finished, Please Enter only 0" << endl;
        //cout << "If you wanna see timer, Please Enter only 1" << endl;
        cin >> row;
        if (row == 0)
        {
            //Check solution if right
            CongratulationMenu();
            break;
            //if Wrong ....
        }
        cin >> column >> number;
        if (!((checkInput(row)) && (checkInput(column)) && (checkInput(number))))
        {
            cout << "Invalid answer, please try again!" << endl;
        }
        else
        {
            if ((Grid[(row - 1) * 2 + 1][(column - 1) * 2 + 1] == " ") || (newBoard[row - 1][column - 1] == 0))
            {
                PrintNumber(row, column, number);
                generate_sudoku();
            }
            else {
                cout << "Invalid answer, please try again!" << endl;
            }
        }
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
        Solutions = TestUnique(newBoard, Solutions);
        GridCreating();
        start = clock();
        generate_sudoku();
    }
    if (NumberMode == 2)
    {
        newBoard = NormalMode();
        Solutions = TestUnique(newBoard, Solutions);
        GridCreating();
        generate_sudoku();
    }
    if (NumberMode == 3)
    {
        newBoard = HardMode();
        Solutions = TestUnique(newBoard, Solutions);
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
