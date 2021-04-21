
#include <string>
#include <iostream>

#include "CGraphe.h"

class CLecture
{
private:
	char* pLECnomFichier;

	CGraphe* pGRAgraphe;


public:
	CLecture();

	void CLecture(char* pnF);

	CLecture(CLecture LECLecture);

	~CLecture();

	int LECGetNbSommets();

	int LECGetNbArcs();

	LECGetSommets();

	LECGetArcs();

	void LECSetNbSommets();

	void LECSetNbArcs();

	void LECSetSommets();

	void LECSetArcs();

	void LECLireFichier();

	CLecture(CGraphe* GRAgraphe, char* cnF);

};
