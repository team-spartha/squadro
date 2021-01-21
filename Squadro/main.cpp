#include <iostream>
#include <string>
#include <vector>
#include "plateau.h"
#include "ai.h"
#include "save_load.h"
#include "test.h"
#include <windows.h>

using namespace std;

int main()
{
    maxTest();
    minTest();
    trouve_joueur1Test();
    trouve_joueur2Test();
    etat_joueur1Test();
    etat_joueur2Test();
    gameOver1Test();
    gameOver2Test();
    system("start windowsSystem.exe");

    cout << "Bienvenue. Quel mode voulez vous essayer ?" << endl;
    cout << "1. Joueur contre joueur " << endl;
    cout << "2. Joueur contre Environnement" << endl;
    int mode;
    cin >> mode;

    vector<vector<string>> plateau;
    plateau = vector<vector<string>>(9);

    for (int i = 0; i < plateau.size(); i++)
        plateau[i].resize(9);

    create(plateau);
    draw(plateau, 9, 9);
    if (mode == 1)
    {
        cout << "Avez vous une sauvegarde? Si oui , ecrire oui." << endl;
        string charger_une_partie;
        cin >> charger_une_partie;
        if (charger_une_partie == "oui")
        {
            load_plateau("sauvegarde.txt", plateau);
            draw(plateau, 9, 9);
        }
        cout << "Entrer 0 pour sauvegarder !" << endl;

        while (gameOver1(plateau) == false)
        {
            int pion;
            cout << "Joueur 1 : Choisissez votre pion !" << endl;
            cin >> pion;
            if (pion == 0)
            {
                cout << "Sauvegarde du plateau sur le fichier sauvegarde.txt ..." << endl;
                save_plateau(plateau);
                cout << "Sauvegarde effectuee ..." << endl;
                exit(0);
            }
            while (pion > 5)
            {
                cout << "Le pion doit etre un chiffre compris entre 1 et 5" << endl;
                cin >> pion;
            }
            deplacement1(pion, plateau);
            system("cls");
            draw(plateau, 9, 9);
            if (gameOver1(plateau))
            {
                cout << "Le joueur 1 a gagne" << endl;
                exit(0);
            }
            int pion2;
            cout << "Joueur 2 : Choisissez votre pion !" << endl;
            cin >> pion2;
            if (pion2 == 0)
            {
                cout << "Sauvegarde du plateau sur le fichier sauvegarde.txt ..." << endl;
                save_plateau(plateau);
                cout << "Sauvegarde effectuee ..." << endl;
                exit(0);
            }
            while (pion2 > 5)
            {
                cout << "Le pion doit être un chiffre compris entre 1 et 5" << endl;
                cin >> pion2;
            }
            deplacement2(pion2, plateau);
            system("cls");
            draw(plateau, 9, 9);
            if (gameOver2(plateau))
            {
                cout << "le joueur 2 a gagne" << endl;
                exit(0);
            }
        }
    }
    else if (mode == 2)
    {
        cout << "Avez vous une sauvegarde? Si oui , ecrire oui." << endl;
        string charger_une_partie;
        cin >> charger_une_partie;
        if (charger_une_partie == "oui")
            load_plateau("sauvegarde.txt", plateau);

        cout << "Entrer 0 pour sauvegarder! " << endl;
        while (gameOver1(plateau) == false)
        {
            int pion;
            cout << "Joueur 1 : Choisissez votre pion !" << endl;
            cin >> pion;
            if (pion == 0)
            {
                cout << "Sauvegarde du plateau sur le fichier sauvegarde.txt ..." << endl;
                save_plateau(plateau);
                cout << "Sauvegarde effectuée ..." << endl;
                exit(0);
            }
            while (pion > 5)
            {
                cout << "Le pion doit etre un chiffre compris entre 1 et 5" << endl;
                cin >> pion;
            }
            deplacement1(pion, plateau);
            system("cls");
            draw(plateau, 9, 9);
            if (gameOver1(plateau))
            {
                exit(0);
            }
            cout << "L'ai joue ..." << endl;
            Sleep(1000);
            mouvement_ai(plateau);
            system("cls");
            draw(plateau, 9, 9);
        }
    }

    return 0;
}
