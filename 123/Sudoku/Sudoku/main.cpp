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

    //��R��4��
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
    //��R��3��
    for (int i = 3; i <= 5; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            num[i][j] = num[(i - 1 + 3) % 3 + 3][j + 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[3][x] = 1;
        }
    }
    //��R��5��
    for (int i = 3; i <= 5; i++)
    {
        for (int j = 6; j <= 8; j++)
        {
            num[i][j] = num[(i + 1 + 3) % 3 + 3][j - 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[5][x] = 1;
        }
    }
    //��R��1��
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 3; j <= 5; j++)
        {
            num[i][j] = num[i + 3][(j - 1 + 3) % 3 + 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[1][x] = 1;
        }
    }
    //��R��7��
    for (int i = 6; i <= 8; i++)
    {
        for (int j = 3; j <= 5; j++)
        {
            num[i][j] = num[i - 3][(j + 1 + 3) % 3 + 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[7][x] = 1;
        }
    }
    //��R��0��
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            num[i][j] = num[i + 3][(j - 1 + 3) % 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[0][x] = 1;
        }
    }
    //��R��6��
    for (int i = 6; i <= 8; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            num[i][j] = num[i - 3][(j + 1 + 3) % 3];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[6][x] = 1;
        }
    }

    //��R��2��
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 6; j <= 8; j++)
        {
            num[i][j] = num[i + 3][(j - 1 + 3) % 3 + 6];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[2][x] = 1;
        }
    }
    //��R��8��
    for (int i = 6; i <= 8; i++)
    {
        for (int j = 6; j <= 8; j++)
        {
            num[i][j] = num[i - 3][(j + 1 + 3) % 3 + 6];

            x = num[i][j];
            countRow[i][x] = countCol[j][x] = countGe[8][x] = 1;
        }
    }

    //�⵪�׽L���s��O���a��
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            num1[i][j] = num[i][j];
        }
    }

    //�H����Ʀr�ܦ�32
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int a = rand() % 10;

            if (a < 2)
                num[i][j] = 32;
        }
    }
    cout << "�ƿW�C��" << endl << endl;

    //�N �Ʀr32�ܦ��ť�,�D32���Ʀr�h��X
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

    //���a��J�Ʀr
    cout << endl;
    cout << "�п�J����" << endl << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int a;
            if (num[i][j] == 32)
            {

                do
                {
                    cout << "��" << i + 1 << "�� ��" << j + 1 << "�C: ";
                    cin >> a;
                } while (a > 9 or a < 1);

                num[i][j] = a;
                cout << endl;
            }
        }
    }

    //��X���a��J�᪺�L��
    cout << "�A������:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    //�P�_�O�_�ŦX�ƿW
    int sum = 0;
    bool b = 1;
    for (int i = 0; i < 9; i++)
    {     //�P�_��V�O�_�ŦX�ƿW 
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
    {      //�P�_���V�O�_�ŦX�ƿW 
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

    //�P�_9�Ӯ�l�O�_�ŦX�ƿW
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
        cout << "You lose..." << endl << endl << "���T����:" << endl;
        num2.printStringArray(num);
    }

    system("pause");
    return 0;


}