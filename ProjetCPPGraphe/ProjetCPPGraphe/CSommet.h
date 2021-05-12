
#include <string>
#include <iostream>

#include "CArc.h"

class CSommet
{
private:
	static unsigned int uiSOMnbSommets;

	unsigned int uiSOMindice;


	CArc** pARCarrivants;

	CArc** pARCpartants;

	unsigned int uiSOMnbDeparts;

	unsigned int uiSOMnbArrivees;

public:

	///
	///
	///
	CSommet();

	///
	///
	///
	CSommet(unsigned int uiindice);

	///
	///
	///
	~CSommet();

	///
	///
	///
	CSommet(const CSommet &SOMsommet);

	///
	///
	///
	unsigned int SOMGetIndice();

	///
	///
	///
	CArc** SOMGetTabArrivants();

	///
	///
	///
	CArc** SOMGetTabPartants();

	///
	///
	///
	unsigned int SOMGetTabNbDeparts();

	///
	///
	///
	unsigned int SOMGetTNbArrivees();

	///
	///
	///
	void SOMSetIndice(unsigned int uiindice);

	///
	///
	///
	void SOMSetTabArrivants(CArc** pARCtab);

	///
	///
	///
	void SOMSetTabPartants(CArc** pARCtab);

	///
	///
	///
	void SOMSetTabNbDeparts(unsigned int uinb);

	///
	///
	///
	void SOMSetTNbArrivees(unsigned int uinb);

	///
	///
	///
	void SOMAddArcArrivant(CSommet SOMdepart);

	///
	///
	///
	void SOMAddArcPartant(CSommet SOMarrive);

	///
	///
	///
	void SOMModArcArrivant(CSommet SOMdest, CSommet SOMnouvelleDest);

	///
	///
	///
	void SOMModArcPartant(CSommet SOMdest, CSommet SOMnouvelleDest);

	///
	///
	///
	void SOMDelArcArrivant(unsigned int uidest);

	///
	///
	///
	void SOMDelArcPartant(unsigned int uidest);

	///
	///
	///
	void SOMRechercherArcArrivant(unsigned int uidest);

	///
	///
	///
	void SOMRechercherArcPartant(unsigned int uidest);

};
