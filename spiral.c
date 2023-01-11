//
// Created by ignacy on 26.11.2019.
//
#include <stdlib.h>
#define spir 10
void spirala()
{
    int tab[spir][spir] = {0};
    int krok = spir - 1, k = 0, w = 0, licz = 1;
    char kier = 'g';
    for (int i = 0; i < spir; i++)
    {
        tab[0][i] = licz++;
    }

    while (1)
    {
        switch (kier)
        {
            case 'p':
                for (int kol = k; kol <= k + krok; kol++)
                {
                    tab[w][kol] = licz;
                    licz++;
                }
                kier = 'g';
                break;
            default:
                break;
        }
        if (spir % 2 == 0)
        {
            if (tab[(int) (spir / 2)][(int) (spir / 2) + 1] != 0)
                {
                    break;
                }
        }
        else if (spir % 2 == 1)
        {
            if (tab[(int) (spir / 2)+1][(int) (spir / 2)+1] != 0)
            {
                break;
            }
        }
    }
}
/*if (tab[w+kpo][k] == 0 && w+1 < spir && w-1 >=0)
        {
            if (kier == 'i')
            {
                kier = 'o';
            }
            else
            {
                kpo *= -1;
            }
            tab[w+kpo][k] = licz;
            w+=1;
            licz+=1;
        }
        if (tab[w][k+kpi] == 0 && k+kpi < spir&& w-kpi >=0)
        {
            if (kier == 'o')
            {
                kier = 'i';
            }
            else
            {
                kpi *= -1;
            }
            tab[w][k+kpi] = licz;
            k+=1;
            licz+=1;
        }
        else
            break;
    }
    for (int i =0;i<spir;i++)
    {
        for (int j = 0; j<spir;j++)
        {
            printf("%i ",tab[i][j]);
        }*/

void nast(char a)
{
    //printf("%i",atoi(a) + 1);
}