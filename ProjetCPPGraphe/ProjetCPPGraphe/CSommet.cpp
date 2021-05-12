#include <string>
#include <iostream>
#include "CSommet.h"


CSommet::CSommet()
{
	uiSOMnbSommets++;

	pARCarrivants = nullptr;
	pARCpartants = nullptr;

	uiSOMindice = uiSOMnbSommets;
	uiSOMnbArrivees = 0;
	uiSOMnbDeparts = 0;
}

CSommet::CSommet(unsigned int uiindice)
{
	uiSOMnbSommets++;

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
	uiSOMnbSommets++;

	pARCarrivants = SOMsommet.pARCarrivants;
	pARCpartants = SOMsommet.pARCpartants;

	uiSOMindice = SOMsommet.uiSOMindice;
	uiSOMnbArrivees = SOMsommet.uiSOMnbArrivees;
	uiSOMnbDeparts = SOMsommet.uiSOMnbDeparts;
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

void CSommet::SOMAddArcArrivant(CSommet SOMdepart)
{
	CArc* pARCarc = new CArc(SOMdepart.uiSOMindice);

	uiSOMnbArrivees++;

	pARCarrivants[uiSOMnbArrivees] = pARCarc;

	SOMdepart.SOMAddArcPartant(*this);
}

void CSommet::SOMAddArcPartant(CSommet SOMarrive)
{
	CArc* pARCarc = new CArc(SOMarrive.uiSOMindice);

	uiSOMnbDeparts++;

	pARCpartants[uiSOMnbDeparts] = pARCarc;
}

void CSommet::SOMModArcArrivant(CSommet SOMdest, CSommet SOMnouvelleDest)
{
	unsigned int uicompteArc;
	for (uicompteArc = 0; uicompteArc<uiSOMnbArrivees ;uicompteArc++) {
		if (pARCarrivants[uicompteArc]->ARCGetDestination() == SOMdest.uiSOMindice) {
			pARCarrivants[uicompteArc]->ARCSetDestination(SOMnouvelleDest.uiSOMindice);
		}

	}

}

void CSommet::SOMModArcPartant(CSommet SOMdest, CSommet SOMnouvelleDest)
{
	unsigned int uicompteArc;
	for (uicompteArc = 0; uicompteArc < uiSOMnbDeparts; uicompteArc++) {
		if (pARCpartants[uicompteArc]->ARCGetDestination() == SOMdest.uiSOMindice) {
			pARCpartants[uicompteArc]->ARCSetDestination(SOMnouvelleDest.uiSOMindice);
		}

	}

}

void CSommet::SOMDelArcArrivant(unsigned int uidest)
{
	for (unsigned int uicompteArc = 0; uicompteArc < uiSOMnbArrivees ; uicompteArc++) {
		if (pARCarrivants[uicompteArc]->ARCGetDestination == uidest) {
			//suppression de l'element du tableau des arrivees
			for (unsigned int uicompteSuppr = uicompteArc ; uicompteSuppr < uiSOMnbArrivees; uicompteSuppr++) {
				pARCarrivants[uicompteSuppr] = pARCarrivants[uicompteSuppr];
			}

		}

	}

}

void CSommet::SOMDelArcPartant(unsigned int uidest)
{

}

void CSommet::SOMRechercherArcArrivant(unsigned int uidest)
{

}

void CSommet::SOMRechercherArcPartant(unsigned int uidest)
{

}
