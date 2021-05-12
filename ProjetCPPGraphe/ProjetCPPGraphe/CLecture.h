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
///fmyFile, ifstream représentant le flux d'entrée du fichier
class CLecture
{
private:
	char* pLECnomFichier;

	ifstream fmyFile;

	unsigned int uinbArcs;
	
	unsigned int uinbSommets;

	int *itabSommets;

	int *itabArcsDepart;

	int *itabArcsArrivee;


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

	int LECGetNbSommets();

	int LECGetNbArcs();

	int *LECGetSommets();

	int *LECGetArcsDepart();
	
	int *LECGetArcsArrivee();

	void LECSetNbSommets();

	void LECSetNbArcs();

	void LECSetSommets();

	void LECSetArcs();

	void LECLireFichier();

};
