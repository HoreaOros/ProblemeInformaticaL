// determinarea numarului de zile dintre 2 date calendaristice
#include <iostream>

using namespace std;

enum LunileAnului
{
    Ianuarie = 1,
    Februarie,
    Martie,
    Aprilie,
    Mai,
    Iunie,
    Iulie,
    August,
    Septembrie,
    Octombrie,
    Noiembrie,
    Decembrie
};

struct DC
{
    int zi, an;
    enum LunileAnului luna;
};

int DateEgale(struct DC d1, struct DC d2)
{
    if(d1.zi == d2.zi && d1.luna == d2.luna && d1.an == d2.an)
        return 1;
    return 0;
}

int Comparare(struct DC d1, struct DC d2)
{
    if(d1.an < d2.an)
        return -1;
    else if(d1.an > d2.an)
        return 1;
    else if(d1.luna < d2.luna)
        return -1;
    else if(d1.luna > d2.luna)
        return 1;
    else if(d1.zi < d2.zi)
        return -1;
    else if(d1.zi > d2.zi)
        return 1;
    else return 0;
}

void ScadOZi(struct DC &d)
{
    if(d.zi > 1)
        d.zi--;
    else
    {
        switch (d.luna)
        {
        case Ianuarie:
            d.luna = Decembrie;
            d.zi =31;
            d.an--;
            break;
        case Februarie: case Aprilie: case Iunie: case August: case Septembrie: case Noiembrie:
            d.luna = (enum LunileAnului)((int)d.luna - 1);
            d.zi = 31;
            break;
        case Martie:
            if((d.an % 4 == 0 && d.an % 100 != 0) || (d.an % 400 == 0))
                d.zi = 29;
            else
                d.zi = 28;
            d.luna = (enum LunileAnului)((int)d.luna - 1);
            break;
        case Mai: case Iulie: case Octombrie: case Decembrie:
            d.zi = 30;
            d.luna = (enum LunileAnului)((int)d.luna - 1);
            break;
        }
    }
}

int DiferentaZile(struct DC d1, struct DC d2)
{
    int contor = 0;
    while(!DateEgale(d1, d2))
    {
        contor++;
        ScadOZi(d1);
    }
    return contor;
}

int main()
{
    struct DC d1;
    struct DC d2;

    d1.zi = 15;
    d1.luna = Decembrie;
    d1.an = 2014;

    d2.zi = 17;
    d2.luna = Aprilie;
    d2.an = 1996;
    cout << DiferentaZile(d1, d2);

    return 0;
}
