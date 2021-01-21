#include "plateau.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int rand_a_b(int a, int b)
{
    return rand() % (b - a) + a;
}

void mouvement_ai(vector<vector<string>> &tab)
{
    /* L'AI a toujours le pion ^ V */
    int jeton_a_bouge = rand_a_b(1, 6);
    deplacement2(jeton_a_bouge, tab);
}
