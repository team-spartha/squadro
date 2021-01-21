#include <iostream>
#include <string>
#include <vector>
#include "plateau.h"
#include "ai.h"
#include <fstream>

using namespace std;

void save_plateau(vector<vector<string>> tab1)
{
    ofstream fichier;
    fichier.open("sauvegarde.txt");
    if (not fichier)
        throw runtime_error("Fichier non trouve: sauvegarde.txt");

    for (int i = 0; i < tab1.size(); i++)
    {
        for (int j = 0; j < tab1[i].size(); j++)
        {
            if (tab1[i][j] == " ")
                fichier << ".";
            else
                fichier << tab1[i][j];
        }
    }

    fichier.close();
}

void load_plateau(string chemin, vector<vector<string>> &tab)
{
    ifstream fichier;
    fichier.open(chemin);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char a;
            fichier.get(a);
            tab[i][j] = a;
            if (tab[i][j] == ".")
                tab[i][j] = " ";
        }
    }
}
