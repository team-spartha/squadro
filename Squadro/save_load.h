#ifndef SAVE_LOAD_H_INCLUDED
#define SAVE_LOAD_H_INCLUDED
#include <vector>
#include <string>
using namespace std;

void save_plateau(vector<vector<string>> tab1);
/* sauvegard l'état du plateau dans un fichier texte ! */

void load_plateau(string chemin, vector<vector<string>> &tab1);
/* en ouvrant un fichier contenant l'état du plateau, remplit un tableau */
#endif // AI_H_INCLUDED
