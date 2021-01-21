#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <vector>
#include <string>
using namespace std;

/** Crée le tableau de squadro
 *  @param t: tableau de string
 *  @return ne retourne rien, modifie le parametre.
 */
void create(std::vector<std::vector<std::string>> &t);

/** affiche le tableau sur la console
 *  @param t : tableau de string
 *  @param ligne : nombre de lignes du tableau
 *  @param colonne : nombre de colonnes
 *  @return ne retourne rien
 */
void draw(std::vector<std::vector<std::string>> t, int ligne, int colone);

/** déplace horizontalement le pion choisi par l'utilisateur
 *  @param tabl :tableau de string
 *  @return ne retourne rien , modofie le parametre
 */
void deplacement1(int indicatif1, std::vector<std::vector<std::string>> &tab1);

/** déplace verticalement le pion choisi par l'utilisateur
 *  @param tabl : tableau de string
 *  @return ne retourne rien
 */
void deplacement2(int indicatif2, std::vector<std::vector<std::string>> &tab2);

/** determine le maximum entre deux entiers
 *  @param a et b deux entiers
 *  @return retourne un entier
 */
int max(int a, int b);

/** determine le minimum entre a et b
 *  @param a et b  deux entiers
 *  @return retourne un entier
 */
int min(int a, int b);

/** trouve la position d'un pion verticale
 *  @param tabl : tableau de string
 *  @return retourne un entier
 */
int trouve_joueur2(int indicatif1, vector<vector<string>> tab1);

/** trouve la position d'un pion vertical
 *  @param tabl : tableau de string
 *  @return retourne un entier
 */

int trouve_joueur1(int indicatif1, vector<vector<string>> tab1);

/** trouves la position d'un point horizontale
 *  @param tabl : tableau de string
 *  @return retourne un entier
 */

int etat_joueur2(int indicatif1, vector<vector<string>> tab1);
/** indique dans quel sens le pion verticale est soit l'all�e soit le retour
 *  @param tabl : tableau de string
 *  @return retourne un entier
 */

int etat_joueur1(int indicatif1, vector<vector<string>> tab1);
/** indique dans quel sens le pion horizontal est soit l'all�e soit le retour
 *  @param tabl : tableau de string
 *  @return retourne un entier
 */

bool gameOver1(vector<vector<string>> tab1);
/* indique que la partie est finie */

bool gameOver2(vector<vector<string>> tab1);
/* indique que la partie est finie */

#endif // PLATEAU_H_INCLUDED
