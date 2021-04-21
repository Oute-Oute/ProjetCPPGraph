
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

	CLecture(char* pnF);

	CLecture(const CLecture &LECLecture);

	~CLecture();

	int LECGetNbSommets();

	int LECGetNbArcs();

	CSommet* LECGetSommets();

	CArc* LECGetArcs();

	void LECSetNbSommets();

	void LECSetNbArcs();

	void LECSetSommets();

	void LECSetArcs();

	void LECLireFichier();

	CLecture(CGraphe* GRAgraphe, char* cnF);

};
