///
/// @brief header de la classe CLecture
/// @file CLecture.h
/// @author Blumstein Thomas
/// @date 2021-05-12
///
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

///@brief un objet CLecture représente la lecture d'un fichier texte
///@details un CLecture contient l'attribut pLECnomFichier, char* du nom du fichier; 
///fmyFile, ifstream représentant le flux d'entrée du fichier;
/// uinbArcs unsigned int représentant le nombre d'arcs;
/// uinbSommets unsigned int représentant le nombre de sommets;
/// *itabSommets, tableau dynamique de int contenant les différents sommets;
/// *itabArcsDepart, tableau dynamique de int contenant les différents sommets de départ d'arcs;
/// *itabArcsArrivee, tableau dynamique de int contenant les différents sommets d'arrivée d'arcs;
class CLecture
{
private:
	char* pLECnomFichier;

	ifstream fLECmyFile;

	unsigned int uiLECnbArcs;
	
	unsigned int uiLECnbSommets;

	int *iLECtabSommets;

	int *iLECtabArcsDepart;

	int *iLECtabArcsArrivee;


public:
	///@brief Constructeur de CLecture par defaut
	///@param RIEN
	///@return RIEN
	CLecture();

	///@brief Constructeur de CLecture en spécifiant un nom de fichier
	///@param char* cnF : char* nom du fichier à lire 
	///@return RIEN
	CLecture(char* cnF);

	///@brief Constructuer de CLecture de recopie
	///@param LECLecture : CLecture a copier
	///@return RIEN
	CLecture(const CLecture &LECLecture);

	///@brief Destructeur de CLecture
	///@param RIEN
	///@return RIEN
	~CLecture();

	///@brief Getter du nombre de sommets
	///@param Rien
	///@return uinbSommets
	unsigned int LECGetNbSommets();

	///@brief Getter du nombre d'arcs
	///@param Rien
	///@return uinbArcs
	unsigned int LECGetNbArcs();

	///@brief Getter du tableau de sommets
	///@param Rien
	///@return *itabSommets
	int *LECGetSommets();

	///@brief Getter du tableau des Arcs Partants
	///@param Rien
	///@return *itabArcsDepart
	int *LECGetArcsDepart();
	
	///@brief Getter du tableau des Arcs d'Arrivée
	///@param Rien
	///@return*itabArcsArrivee
	int *LECGetArcsArrivee();

	///@brief Setter du nombre de sommets depuis un fichier
	///@param Rien
	///@return Rien 
	void LECSetNbSommets();

	///@brief Setter du nombre d'arc depuis un fichier
	///@param Rien
	///@return Rien
	void LECSetNbArcs();

	///@brief Setter du tableau de sommets depuis un fichier
	///@param Rien
	///@return Rien
	void LECSetSommets();

	///@brief Setter des tableaux d'arcs arrivants et partants
	///@param Rien
	///@return Rien
	void LECSetArcs();

	///@brief Fonction de lecture du fichier 
	///@param Rien
	///@return Rien
	void LECLireFichier();

};
