
#include <string>
#include <iostream>

#include "CArc.h"
#include "const CSommet.h"

class CSommet
{
private:
	unsigned int uiSOMindice;

	CArc** pARCarrivants;

	CArc** pARCpartants;

	unsigned int uiSOMnbDeparts;

	unsigned int uiSOMnbArrivees;


public:
	CSommet();

	CSommet(unsigned int uiindice);

	~CSommet();

	CSommet(const CSommet &SOMsommet);

	unsigned int SOMGetIndice();

	CArc** SOMGetTabArrivants();

	CArc** SOMGetTabPartants();

	unsigned int SOMGetTabNbDeparts();

	unsigned int SOMGetTNbArrivees();

	void SOMSetIndice(unsigned int uiindice);

	void SOMSetTabArrivants(CArc** pARCtab);

	void SOMSetTabPartants(CArc** pARCtab);

	void SOMSetTabNbDeparts(unsigned int uinb);

	void SOMSetTNbArrivees(unsigned int uinb);

	void SOMAddArcArrivant(CArc* pARCarc);

	void SOMAddArcPartant(CArc* pARCarc);

	void SOMModArcArrivant(unsigned int uidest, unsigned int uinouvelleDest);

	void SOMModArcPartant(unsigned int uidest, unsigned int uinouvelleDest);

	void SOMDelArcArrivant(unsigned int uidest);

	void SOMDelArcPartant(unsigned int uidest);

	void SOMRechercherArcArrivant(unsigned int uidest);

	void SOMRechercherArcPartant(unsigned int uidest);

};
