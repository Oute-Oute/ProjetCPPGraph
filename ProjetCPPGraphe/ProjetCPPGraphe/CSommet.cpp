#include "CSommet.h"


CSommet::CSommet()
{
	pARCarrivants = nullptr;
	pARCpartants = nullptr;

	uiSOMindice = 0;
	uiSOMnbArrivees = 0;
	uiSOMnbDeparts = 0;
}

CSommet::CSommet(unsigned int uiindice)
{
	pARCarrivants = nullptr;
	pARCpartants = nullptr;

	uiSOMindice = uiindice;
	uiSOMnbArrivees = 0;
	uiSOMnbDeparts = 0;
}

CSommet::~CSommet()
{
}

CSommet::CSommet(const CSommet &SOMsommet)
{
	uiSOMindice = SOMsommet.uiSOMindice;
	uiSOMnbArrivees = SOMsommet.uiSOMnbArrivees;
	uiSOMnbDeparts = SOMsommet.uiSOMnbDeparts;

	for (unsigned int uiCompteArc = 0; uiCompteArc < uiSOMnbArrivees; uiCompteArc ++) {
		pARCarrivants[uiCompteArc] = SOMsommet.pARCarrivants[uiCompteArc];
	}

	for (unsigned int uiCompteArc = 0; uiCompteArc < uiSOMnbDeparts; uiCompteArc++) {
		pARCpartants[uiCompteArc] = SOMsommet.pARCpartants[uiCompteArc];
	}

}

unsigned int CSommet::SOMGetIndice()
{
	return uiSOMindice;
}

CArc** CSommet::SOMGetTabArrivants()
{
	return pARCarrivants;
}

CArc** CSommet::SOMGetTabPartants()
{
	return pARCpartants;
}

unsigned int CSommet::SOMGetTabNbDeparts()
{
	return uiSOMnbDeparts;
}

unsigned int CSommet::SOMGetTNbArrivees()
{
	return uiSOMnbArrivees;
}

void CSommet::SOMSetIndice(unsigned int uiindice)
{
	uiSOMindice = uiindice;
}

void CSommet::SOMSetTabArrivants(CArc** pARCtab)
{
	pARCarrivants = pARCtab;
}

void CSommet::SOMSetTabPartants(CArc** pARCtab)
{
	pARCpartants = pARCtab;
}

void CSommet::SOMSetTabNbDeparts(unsigned int uinb)
{
	uiSOMnbDeparts = uinb;
}

void CSommet::SOMSetTNbArrivees(unsigned int uinb)
{
	uiSOMnbArrivees = uinb;
}

void CSommet::SOMAddArcArrivant(unsigned int uiIndice)
{
	CArc* pARCarc = new CArc(uiIndice);

	uiSOMnbArrivees++;

	pARCarrivants = (CArc**)realloc(pARCarrivants, uiSOMnbArrivees * sizeof(CArc*));

	pARCarrivants[uiSOMnbArrivees-1] = pARCarc;
}

void CSommet::SOMAddArcPartant(unsigned int uiIndice)
{
	CArc* pARCarc = new CArc(uiIndice);

	uiSOMnbDeparts ++;

	pARCpartants = (CArc**)realloc(pARCpartants, uiSOMnbDeparts * sizeof(CArc*));

	pARCpartants[uiSOMnbDeparts-1] = pARCarc;
}

void CSommet::SOMModArcArrivant(unsigned int uiIndice, unsigned int uiNouvelIndice)
{
	unsigned int uicompteArc;
	for (uicompteArc = 0; uicompteArc<uiSOMnbArrivees ;uicompteArc++) {
		if (pARCarrivants[uicompteArc]->ARCGetDestination() == uiIndice) {
			pARCarrivants[uicompteArc]->ARCSetDestination(uiNouvelIndice);
		}

	}

}

void CSommet::SOMModArcPartant(unsigned int uiIndice, unsigned int uiNouvelIndice)
{
	unsigned int uicompteArc;
	for (uicompteArc = 0; uicompteArc < uiSOMnbDeparts; uicompteArc++) {
		if (pARCpartants[uicompteArc]->ARCGetDestination() == uiIndice) {
			pARCpartants[uicompteArc]->ARCSetDestination(uiNouvelIndice);
		}

	}

}

void CSommet::SOMDelArcArrivant(unsigned int uidest)
{
	for (unsigned int uicompteArc = 0; uicompteArc < uiSOMnbArrivees ; uicompteArc++) {
		if (pARCarrivants[uicompteArc]->ARCGetDestination() == uidest) {
			//suppression de l'arc
			delete pARCpartants[uicompteArc];
			//suppression de l'element du tableau des arrivees
			for (unsigned int uicompteSuppr = uicompteArc ; uicompteSuppr < uiSOMnbArrivees; uicompteSuppr++) {
				pARCarrivants[uicompteSuppr] = pARCarrivants[uicompteSuppr+1];
			}

			uiSOMnbArrivees --;
			pARCarrivants = (CArc**)realloc(pARCarrivants, uiSOMnbArrivees * sizeof(CArc*));

		}

	}

}

void CSommet::SOMDelArcPartant(unsigned int uidest)
{
	for (unsigned int uicompteArc = 0; uicompteArc < uiSOMnbDeparts; uicompteArc++) {
		if (pARCpartants[uicompteArc]->ARCGetDestination() == uidest) {
			//suppression de l'arc
			delete pARCpartants[uicompteArc];
			//suppression de l'element du tableau des arrivees
			for (unsigned int uicompteSuppr = uicompteArc; uicompteSuppr < uiSOMnbDeparts; uicompteSuppr++) {
				pARCpartants[uicompteSuppr] = pARCpartants[uicompteSuppr + 1];
			}

			uiSOMnbDeparts --;
			pARCpartants = (CArc**)realloc(pARCpartants, uiSOMnbDeparts * sizeof(CArc*));

		}

	}

}

void CSommet::SOMInverseTableaux() {
	
	CArc** pARCTemp = nullptr;
	
	pARCTemp = (CArc**)realloc(pARCarrivants, uiSOMnbArrivees * sizeof(CArc*));
	for (unsigned int uicompteArc = 0; uicompteArc < uiSOMnbArrivees; uicompteArc++) {
		pARCTemp[uicompteArc] = pARCarrivants[uicompteArc];
	}
	unsigned int uiLenARCTemp = uiSOMnbArrivees;

	pARCarrivants = (CArc**)realloc(pARCpartants, uiSOMnbDeparts * sizeof(CArc*));
	for (unsigned int uicompteArc = 0; uicompteArc < uiSOMnbDeparts; uicompteArc++) {
		pARCarrivants[uicompteArc] = pARCpartants[uicompteArc];
	}
	uiSOMnbArrivees = uiSOMnbDeparts;

	pARCpartants = (CArc**)realloc(pARCTemp, uiLenARCTemp * sizeof(CArc*));
	for (unsigned int uicompteArc = 0; uicompteArc < uiLenARCTemp; uicompteArc++) {
		pARCpartants[uicompteArc] = pARCTemp[uicompteArc];
	}
	uiSOMnbDeparts = uiLenARCTemp;

}
