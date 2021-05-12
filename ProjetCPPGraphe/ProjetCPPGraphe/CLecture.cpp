#include "CLecture.h"
#include "CException.h"
using namespace std;


CLecture::CLecture()
{
	pLECnomFichier = nullptr;
	uinbArcs = 0;
	uinbSommets = 0;
	itabArcsArrivee = nullptr;
	itabArcsDepart = nullptr;
	itabSommets = nullptr;
}

CLecture::CLecture(char* cnF)
{
	pLECnomFichier = cnF;
	uinbArcs = 0;
	uinbSommets = 0;
	itabArcsArrivee = nullptr;
	itabArcsDepart = nullptr;
	itabSommets = nullptr;
}

CLecture::CLecture(const CLecture &LECLecture)
{
	pLECnomFichier = LECLecture.pLECnomFichier;
	uinbArcs = LECLecture.uinbArcs;
	uinbSommets = LECLecture.uinbSommets;
	itabArcsArrivee = LECLecture.itabArcsArrivee;
	itabArcsDepart = LECLecture.itabArcsDepart;
	itabSommets = LECLecture.itabSommets;
}

CLecture::~CLecture()
{
}

int CLecture::LECGetNbSommets()
{
	return uinbSommets;
}

int CLecture::LECGetNbArcs()
{
	return uinbArcs;
}

int * CLecture::LECGetSommets()
{
	return itabSommets;
}

int * CLecture::LECGetArcsDepart()
{
	return itabArcsDepart;
}

int * CLecture::LECGetArcsArrivee()
{
	return itabArcsArrivee;
}

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
		cParse = strtok_s(cParse, " ", &context);
		itabSommets[uiBoucle] = atoi(cParse);
		cParse = strtok_s(NULL, " ", &context);
		
		fmyFile.getline(cLigne, 50);
	}
}

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
		cParse = strtok_s(cParse, " ", &context);
		itabArcsDepart[uiBoucle] = atoi(cParse);
		cParse = strtok_s(cParse, " ", &context);
		itabArcsDepart[uiBoucle] = atoi(cParse);

		fmyFile.getline(cLigne, 50);
	}
}

void CLecture::LECLireFichier()
{
	CException *EXCExceptionLecture = new CException();
	EXCExceptionLecture->EXCSetOperation('L');

	
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


