#include "plateau.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void create(std::vector<std::vector<std::string>> &t)
{
    t[1][7] = "X", t[0][2] = "1", t[8][2] = "3"; t[0][0] = " ";
    t[1][1] = "X", t[0][3] = "3", t[8][3] = "1"; t[0][1] = " ";
    t[7][1] = "X", t[0][4] = "2", t[8][4] = "2"; t[1][0] = " ";
    t[7][7] = "X", t[0][5] = "3", t[8][5] = "1"; t[7][0] = " ";
    t[0][6] = "1", t[2][0] = "1", t[8][6] = "3", t[6][0] = "1";
    t[3][0] = "3", t[4][0] = "2", t[2][8] = "3"; t[8][0] = " ";
    t[5][0] = "3", t[6][1] = "1", t[3][8] = "1"; t[8][1] = " ";
    t[4][8] = "2", t[5][8] = "1", t[6][8] = "3"; t[7][8] = " ";
    t[8][8] = " ";
    t[0][7] = " ", t[0][8] = " ", t[1][0] = " ";
    t[1][8] = " ", t[8][7] = " ";

    for (int i = 2; i <= 6; i++)
        t[i][1] = ">";

    for (int c = 2; c <= 6; c++)
        t[7][c] = "^";

    for (int v = 2; v <= 6; v++)
        for (int a = 2; a <= 6; a++)
            t[v][a] = "*";

    for (int f = 2; f <= 6; f++)
        t[1][f] = "*";

    for (int r = 2; r <= 6; r++)
        t[r][7] = "*";
}

void draw(std::vector<std::vector<std::string>> t, int ligne, int colone)
{
    for (int c = 0; c < ligne; c++)
    {
        for (int a = 0; a < colone; a++)
            std::cout << " " << t[c][a] << " ";

        std::cout << std::endl;
    }
}

int etat_joueur1(int indicatif1, vector<vector<string>> tab1)
{
    for (int i = 1; i <= 7; i++)
    {
        if (tab1[indicatif1 + 1][i] == ">")
            return 0;
        if (tab1[indicatif1 + 1][i] == "<")
            return 1;
    }
}

int etat_joueur2(int indicatif1, vector<vector<string>> tab1)
{
    for (int i = 7; i >= 1; i--)
    {
        if (tab1[i][indicatif1 + 1] == "^")
            return 0;
        if (tab1[i][indicatif1 + 1] == "v")
            return 1;
    }
}

int trouve_joueur1(int indicatif1, vector<vector<string>> tab1)
{
    for (int i = 1; i <= 7; i++)
        if (tab1[indicatif1 + 1][i] == ">" || tab1[indicatif1 + 1][i] == "<")
            return i;
}

int trouve_joueur2(int indicatif1, vector<vector<string>> tab1)
{
    for (int i = 7; i >= 1; i--)
        if (tab1[i][indicatif1 + 1] == "^" || tab1[i][indicatif1 + 1] == "v")
            return i;
}

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void deplacement1(int indicatif1, std::vector<std::vector<std::string>> &tab1)
{
    vector<vector<int>> mouvements = {{1, 3, 2, 3, 1}, {3, 1, 2, 1, 3}};
    int etat1 = etat_joueur1(indicatif1, tab1);
    int index1 = trouve_joueur1(indicatif1, tab1);
    if (tab1[indicatif1 + 1][1] == "-")
        cout << "Ce pion n'est plus disponible! " << endl;
    else
    {
        if (etat1 == 0)
        {
            int index_deplace = min(index1 + mouvements[0][indicatif1 - 1], 7);
            tab1[indicatif1 + 1][index1] = "*";
            for (int i = index1; i <= index_deplace; i++)
            {
                if (tab1[indicatif1 + 1][i] == "^")
                {
                    tab1[7][i] = "^";
                    tab1[indicatif1 + 1][i] = "*";
                    index_deplace = i + 1;
                }
                else if (tab1[indicatif1 + 1][i] == "v")
                {
                    tab1[1][i] = "v";
                    tab1[indicatif1 + 1][i] = "*";
                    index_deplace = i + 1;
                }
            }
            tab1[indicatif1 + 1][index_deplace] = ">";
            if (index_deplace == 7)
                tab1[indicatif1 + 1][index_deplace] = "<";
        }
        else
        {
            int index_deplace = max(index1 - mouvements[1][indicatif1 - 1], 1);
            tab1[indicatif1 + 1][index1] = "*";
            for (int i = index1; i <= index_deplace; i++)
            {
                if (tab1[indicatif1 + 1][i] == "^")
                {
                    tab1[7][i] = "^";
                    tab1[indicatif1 + 1][i] = "*";
                    index_deplace = i + 1;
                }
                else if (tab1[indicatif1 + 1][i] == "v")
                {
                    tab1[1][i] = "v";
                    tab1[indicatif1 + 1][i] = "*";
                    index_deplace = i + 1;
                }
            }
            tab1[indicatif1 + 1][index_deplace] = "<";
            if (index_deplace == 1)
                tab1[indicatif1 + 1][index_deplace] = "-";
        }
    }
}

void deplacement2(int indicatif2, std::vector<std::vector<std::string>> &tab1)
{
    vector<vector<int>> mouvements = {{3, 1, 2, 1, 3}, {1, 3, 2, 3, 1}};
    int etat2 = etat_joueur2(indicatif2, tab1);
    int index2 = trouve_joueur2(indicatif2, tab1);

    if (tab1[7 - index2][indicatif2 + 1] == "-")
        cout << "Ce pion n'est plus disponible !" << endl;
    else
    {
        if (etat2 == 0)
        {
            int index_deplace = max(index2 - mouvements[0][indicatif2 - 1], 1);
            for (int i = index2; i >= index_deplace; i--)
            {
                if (tab1[i][indicatif2 + 1] == ">")
                {
                    tab1[i][1] = ">";
                    tab1[i][indicatif2 + 1] = "*";
                    index_deplace = i - 1;
                }
                else if (tab1[i][indicatif2 + 1] == "<")
                {
                    tab1[i][7] = "<";
                    tab1[i][indicatif2 + 1] = "*";
                    index_deplace = i + 1;
                }
            }
            tab1[index2][indicatif2 + 1] = "*";
            tab1[index_deplace][indicatif2 + 1] = "^";
            if (index_deplace == 1)
                tab1[index_deplace][indicatif2 + 1] = "v";
        }
        else
        {
            int index_deplace = min(index2 + mouvements[1][indicatif2 - 1], 7);
            tab1[index2][indicatif2 + 1] = "*";
            for (int i = index2; i >= index_deplace; i--)
            {
                if (tab1[i][indicatif2 + 1] == ">")
                {
                    tab1[i][1] = ">";
                    tab1[i][indicatif2 + 1] = "*";
                    index_deplace = i - 1;
                }
                else if (tab1[i][indicatif2 + 1] == "<")
                {
                    tab1[i][7] = "<";
                    tab1[i][indicatif2 + 1] = "*";
                    index_deplace = i + 1;
                }
            }
            tab1[index_deplace][indicatif2 + 1] = "v";
            if (index_deplace == 7)
                tab1[index_deplace][indicatif2 + 1] = "-";
        }
    }
}

bool gameOver1(vector<vector<string>> tab1)
{
    int compteur1 = 0;

    for (int i = 2; i < 7; i++)
        if (tab1[i][1] == "-")
            compteur1++;
    
    if (compteur1 == 4)
        return true;
    else
        return false;
}

bool gameOver2(vector<vector<string>> tab1)
{
    int compteur2 = 0;
    for (int i = 2; i < 7; i++)
        if (tab1[7][i] == "-")
            compteur2++;
    
    if (compteur2 == 4)
        return true;
    else
        return false;
}
// oumaima.el-joubari@u-psud.fr
