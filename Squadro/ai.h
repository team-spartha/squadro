#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED
#include <vector>
#include <string>
using namespace std;

int rand_a_b(int a, int b);
/* renvoie un entier compris entre a et b-1 */

void mouvement_ai(vector<vector<string>> &tab);
/* mouvement ai , pour l'instant marche en pure random ! */

#endif // AI_H_INCLUDED
