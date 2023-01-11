#include <stdlib.h>
#include <stdio.h>
#define SIZE 20

struct baza
{
    int max_size;
    int act_size;
    struct wpis* tab;
};

struct wpis
{
    char imie[20];
    char nazwisko[30];
    long int numer;
};

int dodaj( struct baza *a_bazy, struct wpis *a_wpisu)
{
    if (a_bazy->act_size >= a_bazy->max_size)
    {
        struct wpis* ptr_temp = realloc(a_bazy,(a_bazy->max_size+10)*sizeof(struct wpis));
        if (ptr_temp != NULL)
        {
            a_bazy->tab = ptr_temp;
            a_bazy->max_size += 10;
        }
        else
        {
            return -1;
        }
    }

    a_bazy->tab[a_bazy->act_size++] = *a_wpisu;
    return 0;

}

struct baza usun( struct baza par_baza, int indeks)
{
    if(0 <= indeks < par_baza.act_size)
    {
        for(int i = indeks;i+1<par_baza.act_size;i++)
        {
                par_baza.tab[i] = par_baza.tab[i+1];
        }

        par_baza.act_size--;
        return par_baza;
    }
    else
    {
        puts("nie udało się zmienić elementu");
        return par_baza;
    }
}

void wypisz(struct baza* a_bazy)
{
    for(int i = 0; i < a_bazy->act_size;i++)
    {
        printf("index: %i\n",i);
        puts(a_bazy->tab[i].imie);
        puts(a_bazy->tab[i].nazwisko);
        printf("%li\n\n",a_bazy->tab[i].numer);
    }
}
int main()
{
    struct baza b;
    b.max_size = SIZE;
    b.act_size = 0;
    b.tab = malloc(SIZE * sizeof(struct wpis));
    if(b.tab == NULL)
    {
        puts("blad alokacji");
        return 0;
    }
    struct baza *a_bazy = &b;
    struct wpis *a_wpisu = NULL;
    int index = 0;
    struct wpis nowy ={"Piotr", "Pawlik", 123456789L};
    int operacja = 0;

    do {
        printf("Co mam zrobić? (1 - wypisanie, 2 - dodawanie, 3 - usuwanie, 0 - koniec)\n");
        scanf("%d", &operacja);
        switch (operacja) {
            case 1:
            {
                wypisz(a_bazy);
                break;
            }
            case 2:
            {
                scanf("%s",nowy.imie);
                scanf("%s",nowy.nazwisko);
                scanf("%li",&(nowy.numer));
                if (dodaj(a_bazy, &nowy) == -1)
                    puts("nie udało się");
            }
                break;
            case 3:
            {
                scanf("%i",&index);
                b = usun(b, index);
                break;
            }
        }
    } while (operacja != 0);
    free(b.tab);
    return  0;
}