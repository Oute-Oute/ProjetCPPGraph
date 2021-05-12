
#include <string>
#include <iostream>

#include "CGraphe.h"

class CLecture
{
private:
	char* pLECnomFichier;

	CGraphe* pGRAgraphe;

	ifstream fmyFile;
	unsigned int uinbArcs;

public:
	CLecture();

	CLecture(char* pnF);

	CLecture(const CLecture &LECLecture);

	CLecture(CGraphe* GRAgraphe, char* cnF);

	~CLecture();

	void LECSetNbSommets();

	void LECSetNbArcs();

	void LECSetSommets();

	void LECSetArcs();

	void LECLireFichier();

};
