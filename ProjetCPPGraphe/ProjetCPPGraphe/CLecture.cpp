#include "CLecture.h"
#include "CException.h"
using namespace std;

///@brief Constructeur de CLecture par defaut
///@param RIEN
///@return RIEN
CLecture::CLecture()
{
	pLECnomFichier = nullptr;
	uiLECnbArcs = 0;
	uiLECnbSommets = 0;
	iLECtabArcsArrivee = nullptr;
	iLECtabArcsDepart = nullptr;
	iLECtabSommets = nullptr;
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
	uiLECnbArcs = LECLecture.uiLECnbArcs;
	uiLECnbSommets = LECLecture.uiLECnbSommets;
	iLECtabArcsArrivee = LECLecture.iLECtabArcsArrivee;
	iLECtabArcsDepart = LECLecture.iLECtabArcsDepart;
	iLECtabSommets = LECLecture.iLECtabSommets;
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
	return uiLECnbSommets;
}

///@brief Getter du nombre d'arcs
///@param Rien
///@return uinbArcs
unsigned int CLecture::LECGetNbArcs()
{
	return uiLECnbArcs;
}

///@brief Getter du tableau de sommets
///@param Rien
///@return *itabSommets
int * CLecture::LECGetSommets()
{
	return iLECtabSommets;
}

///@brief Getter du tableau des Arcs Partants
///@param Rien
///@return *itabArcsDepart
int * CLecture::LECGetArcsDepart()
{
	return iLECtabArcsDepart;
}

///@brief Getter du tableau des Arcs d'Arrivée
///@param Rien
///@return*itabArcsArrivee
int * CLecture::LECGetArcsArrivee()
{
	return iLECtabArcsArrivee;
}

///@brief Setter du nombre de sommets depuis un fichier
///@param Rien
///@return Rien 
void CLecture::LECSetNbSommets()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fLECmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);
	uiLECnbSommets=(atoi(cParse));
	
}

///@brief Setter du nombre d'arc depuis un fichier
///@param Rien
///@return Rien
void CLecture::LECSetNbArcs()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fLECmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);
	uiLECnbArcs=(atoi(cParse));
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
	iLECtabSommets = new int[uiLECnbSommets];
	fLECmyFile.getline(cLigne, 50);
	fLECmyFile.getline(cLigne, 50);
	for (uiBoucle = 0; uiBoucle < uiLECnbSommets; uiBoucle++) {
		//cParse = strtok_s(cLigne, "\t", &context);
		cParse = strtok_s(cLigne, "=", &context);
		cParse = strtok_s(NULL, " ", &context);
		iLECtabSommets[uiBoucle] = atoi(cParse);
		

		
		fLECmyFile.getline(cLigne, 50);
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
	iLECtabArcsDepart = new int[uiLECnbArcs];
	iLECtabArcsArrivee = new int[uiLECnbArcs];
	fLECmyFile.getline(cLigne, 50);
	fLECmyFile.getline(cLigne, 50);
	for (uiBoucle = 0; uiBoucle < uiLECnbArcs; uiBoucle++) {
		//cParse = strtok_s(cLigne, "\t", &context);
		cParse = strtok_s(cLigne, "=", &context);
		cParse = strtok_s(NULL, ",", &context);
		iLECtabArcsDepart[uiBoucle] = atoi(cParse);
		cParse = strtok_s(NULL, "=", &context);
		cParse = strtok_s(NULL, ",", &context);
		iLECtabArcsArrivee[uiBoucle] = atoi(cParse);

		fLECmyFile.getline(cLigne, 50);
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
		fLECmyFile.open(pLECnomFichier);

		if (fLECmyFile.is_open()) {
			LECSetNbSommets();
			LECSetNbArcs();
			LECSetSommets();
			LECSetArcs();
			fLECmyFile.close();
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


