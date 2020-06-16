#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"Sudoku.h"
using namespace std;

int main()
{
    srand(time(0));
    int x, y, num[9][9] = { 0 }, countGe[9][9] = { 0 }, countRow[9][9] = { 0 }, countCol[9][9] = { 0 }, num1[9][9];
    Sudoku num2(num[9][9]);

    //填充第4格
    for (int i = 3; i <= 5; i++)
    {
        for (int j = 3; j <= 5; j++)
        {
            do
            {
                x = rand() % 9 + 1;
            } while (countGe[4][x]);
            num[i][j] = x;
            countRow[i][x] = countCol[j][x] = countGe[4][x] = 1;
        }
    }
    //填充第3格
    for (int i = 3; i <= 5; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            num[i][j] = num[(i - 1 + 3) % 3 + 3][j + 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[3][x] = 1;
        }
    }
    //填充第5格
    for (int i = 3; i <= 5; i++)
    {
        for (int j = 6; j <= 8; j++)
        {
            num[i][j] = num[(i + 1 + 3) % 3 + 3][j - 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[5][x] = 1;
        }
    }
    //填充第1格
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 3; j <= 5; j++)
        {
            num[i][j] = num[i + 3][(j - 1 + 3) % 3 + 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[1][x] = 1;
        }
    }
    //填充第7格
    for (int i = 6; i <= 8; i++)
    {
        for (int j = 3; j <= 5; j++)
        {
            num[i][j] = num[i - 3][(j + 1 + 3) % 3 + 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[7][x] = 1;
        }
    }
    //填充第0格
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            num[i][j] = num[i + 3][(j - 1 + 3) % 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[0][x] = 1;
        }
    }
    //填充第6格
    for (int i = 6; i <= 8; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            num[i][j] = num[i - 3][(j + 1 + 3) % 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[6][x] = 1;
        }
    }

    //填充第2格
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 6; j <= 8; j++)
        {
            num[i][j] = num[i + 3][(j - 1 + 3) % 3 + 6];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[2][x] = 1;
        }
    }
    //填充第8格
    for (int i = 6; i <= 8; i++)
    {
        for (int j = 6; j <= 8; j++)
        {
            num[i][j] = num[i - 3][(j + 1 + 3) % 3 + 6];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[8][x] = 1;
        }
    }

    //把答案盤面存到別的地方
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            num1[i][j] = num[i][j];
        }
    }

    //隨機把數字變成32
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int a = rand() % 10;

            if (a < 2)
                num[i][j] = 32;
        }
    }
    cout << "數獨遊戲" << endl << endl;

    //將 數字32變成空白,非32的數字則輸出
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (num[i][j] == 32)
                cout << "  ";
            else
                cout << num[i][j] << " ";
        }
        cout << endl;
    }

    //玩家輸入數字
    cout << endl;
    cout << "請輸入答案" << endl << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int a;
            if (num[i][j] == 32)
            {

                do
                {
                    cout << "第" << i + 1 << "行 第" << j + 1 << "列: ";
                    cin >> a;
                } while (a > 9 or a < 1);

                num[i][j] = a;
                cout << endl;
            }
        }
    }

    //輸出玩家輸入後的盤面
    cout << "你的答案:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    //判斷是否符合數獨
    int sum = 0;
    bool b = 1;
    for (int i = 0; i < 9; i++)
    {     //判斷橫向是否符合數獨 
        sum = 0;
        for (int j = 0; j < 9; j++)
        {
            sum += num[i][j];
        }
        if (sum != 45)
        {
            b = 0;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {      //判斷直向是否符合數獨 
        sum = 0;
        for (int j = 0; j < 9; j++)
        {
            sum += num[j][i];
        }
        if (sum != 45)
        {
            b = 0;
            break;
        }
    }

    //判斷9個格子是否符合數獨
    for (int m = 0; m < 9; m = m + 3)
    {
        sum = 0;
        for (int i = m; i < m + 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum += num[i][j];
            }
        }
        if (sum != 45)
        {
            b = 0;
            break;
        }
    }

    for (int m = 0; m < 9; m = m + 3)
    {
        sum = 0;
        for (int i = m; i < m + 3; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                sum += num[i][j];
            }
        }
        if (sum != 45)
        {
            b = 0;
            break;
        }
    }
    for (int m = 0; m < 9; m = m + 3)
    {
        sum = 0;
        for (int i = m; i < m + 3; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                sum += num[i][j];
            }
        }
        if (sum != 45)
        {
            b = 0;
            break;
        }
    }
    cout << endl;

    if (b == 1)
        cout << "Condritulation!You are win!!!" << endl;
    else
    {
        cout << "You lose..." << endl << endl << "正確答案:" << endl;
        num2.printStringArray(num);
    }

    system("pause");
    return 0;


}