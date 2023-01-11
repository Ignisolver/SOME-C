#include <stdio.h>
#include "fun.c"
void bubble(int tab[ ], int size)
{
    int temp;
    for (int z=size; z>1; z--)
    {
        for(int w = 0;w < z;w++)
        {
            if(tab[w+1]<tab[w])
            {
                temp = tab[w];
                tab[w] = tab[w+1];
                tab[w+1] = temp;
            }
        }
    }
}
int main()
{
    char a;
    scanf("%c",&a);
    if (a=='z')
        putchar('a');
    else
        printf("%c",(char)((int)a+1));

}