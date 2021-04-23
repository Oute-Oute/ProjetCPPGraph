<<<<<<< Updated upstream
=======
#include <string>
#include <iostream>
#include <fstream>

>>>>>>> Stashed changes
#include "CLecture.h"
#include "CException.h"
using namespace std;


CLecture::CLecture()
{
}

CLecture::CLecture(char* pnF)
{
}

CLecture::CLecture(const CLecture &LECLecture)
{
}

CLecture::CLecture(CGraphe* GRAgraphe, char* cnF)
{
}

CLecture::~CLecture()
{
}

void CLecture::LECSetNbSommets()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);
	pGRAgraphe->GRASetnbSommets(atoi(cParse));
	
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
	unsigned int uiBoucleLignes;
	unsigned int uiBoucleColonnes;
	unsigned int uiboucleTab;
	int itabSommets[pGRAgraphe->GRAGetnbSommets()];
	for (uiboucleTab = 0; uiboucleTab < uiLECnbLignes; uiboucleTab++) {
		pLECtabValeurs[uiboucleTab] = new double[uiLECnbColonnes];
	}

	fmyFile.getline(cLigne, 50);
	fmyFile.getline(cLigne, 50);
	for (uiBoucleLignes = 0; uiBoucleLignes < uiLECnbLignes; uiBoucleLignes++) {
		cParse = strtok_s(cLigne, "\t", &context);
		cParse = strtok_s(cParse, " ", &context);
		for (uiBoucleColonnes = 0; uiBoucleColonnes < uiLECnbColonnes; uiBoucleColonnes++) {

			pLECtabValeurs[uiBoucleLignes][uiBoucleColonnes] = atof(cParse);
			cParse = strtok_s(NULL, " ", &context);
		}
		fmyFile.getline(cLigne, 50);
	}
}

void CLecture::LECSetArcs()
{
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


