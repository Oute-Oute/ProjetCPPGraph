#include "CLecture.h"
#include "CException.h"
using namespace std;

///@brief Constructeur de CLecture par defaut
///@param RIEN
///@return RIEN
CLecture::CLecture()
{
	pLECnomFichier = nullptr;
	uinbArcs = 0;
	uinbSommets = 0;
	itabArcsArrivee = nullptr;
	itabArcsDepart = nullptr;
	itabSommets = nullptr;
}

///@brief Constructeur de CLecture en spécifiant un nom de fichier
///@param char* cnF : char* nom du fichier à lire 
///@return RIEN
CLecture::CLecture(char* cnF)
{
	pLECnomFichier = cnF;
}

///@brief Constructuer de CLecture de recopie
///@param LECLecture : CLecture a copier
///@return RIEN
CLecture::CLecture(const CLecture &LECLecture)
{
	pLECnomFichier = LECLecture.pLECnomFichier;
	uinbArcs = LECLecture.uinbArcs;
	uinbSommets = LECLecture.uinbSommets;
	itabArcsArrivee = LECLecture.itabArcsArrivee;
	itabArcsDepart = LECLecture.itabArcsDepart;
	itabSommets = LECLecture.itabSommets;
}

///@brief Destructeur de CLecture
///@param RIEN
///@return RIEN
CLecture::~CLecture()
{
}

///@brief Getter du nombre de sommets
///@param Rien
///@return uinbSommets
unsigned int CLecture::LECGetNbSommets()
{
	return uinbSommets;
}

///@brief Getter du nombre d'arcs
///@param Rien
///@return uinbArcs
unsigned int CLecture::LECGetNbArcs()
{
	return uinbArcs;
}

///@brief Getter du tableau de sommets
///@param Rien
///@return *itabSommets
int * CLecture::LECGetSommets()
{
	return itabSommets;
}

///@brief Getter du tableau des Arcs Partants
///@param Rien
///@return *itabArcsDepart
int * CLecture::LECGetArcsDepart()
{
	return itabArcsDepart;
}

///@brief Getter du tableau des Arcs d'Arrivée
///@param Rien
///@return*itabArcsArrivee
int * CLecture::LECGetArcsArrivee()
{
	return itabArcsArrivee;
}

///@brief Setter du nombre de sommets depuis un fichier
///@param Rien
///@return Rien 
void CLecture::LECSetNbSommets()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);
	uinbSommets=(atoi(cParse));
	
}

///@brief Setter du nombre d'arc depuis un fichier
///@param Rien
///@return Rien
void CLecture::LECSetNbArcs()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);
	uinbArcs=(atoi(cParse));
}

///@brief Setter du tableau de sommets depuis un fichier
///@param Rien
///@return Rien
void CLecture::LECSetSommets()
{
	char cLigne[50];
	char* cParse = new char[50];
	char* context = NULL;
	unsigned int uiBoucle;
	itabSommets = new int[uinbSommets];
	fmyFile.getline(cLigne, 50);
	fmyFile.getline(cLigne, 50);
	for (uiBoucle = 0; uiBoucle < uinbSommets; uiBoucle++) {
		//cParse = strtok_s(cLigne, "\t", &context);
		cParse = strtok_s(cLigne, "=", &context);
		cParse = strtok_s(NULL, " ", &context);
		itabSommets[uiBoucle] = atoi(cParse);
		

		
		fmyFile.getline(cLigne, 50);
	}
}

///@brief Setter des tableaux d'arcs arrivants et partants
///@param Rien
///@return Rien
void CLecture::LECSetArcs()
{
	char cLigne[50];
	char* cParse = new char[50];
	char* context = NULL;
	unsigned int uiBoucle;
	itabArcsDepart = new int[uinbArcs];
	itabArcsArrivee = new int[uinbArcs];
	fmyFile.getline(cLigne, 50);
	fmyFile.getline(cLigne, 50);
	for (uiBoucle = 0; uiBoucle < uinbSommets; uiBoucle++) {
		//cParse = strtok_s(cLigne, "\t", &context);
		cParse = strtok_s(cLigne, "=", &context);
		cParse = strtok_s(NULL, ",", &context);
		itabArcsDepart[uiBoucle] = atoi(cParse);
		cParse = strtok_s(NULL, "=", &context);
		cParse = strtok_s(NULL, ",", &context);
		itabArcsArrivee[uiBoucle] = atoi(cParse);

		fmyFile.getline(cLigne, 50);
	}
}

///@brief Fonction de lecture du fichier 
///@param Rien
///@return Rien
void CLecture::LECLireFichier()
{
	CException *EXCExceptionLecture = new CException();
	EXCExceptionLecture->EXCSetOperation((char*)"Lecture de fichier");

	
	try {
		fmyFile.open(pLECnomFichier);

		if (fmyFile.is_open()) {
			LECSetNbSommets();
			LECSetNbArcs();
			LECSetSommets();
			LECSetArcs();
			fmyFile.close();
		}

		else {
			EXCExceptionLecture->EXCSetMessage((char*)"Erreur lors de l'ouverture du fichier");
			throw(EXCExceptionLecture);
		}

	}

	catch (CException *EXCExceptionLecture) {
		EXCExceptionLecture->EXCAfficherException();
		delete EXCExceptionLecture;
	}
}


