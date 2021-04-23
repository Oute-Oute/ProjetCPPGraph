#include <string>
#include <iostream>
#include "CSommet.h"


CSommet::CSommet()
{
}

CSommet::CSommet(unsigned int uiindice)
{
}

CSommet::~CSommet()
{
}

CSommet::CSommet(const CSommet &SOMsommet)
{
}

unsigned int CSommet::SOMGetIndice()
{
	return 0;
}

CArc** CSommet::SOMGetTabArrivants()
{
	return 0;
}

CArc** CSommet::SOMGetTabPartants()
{
	return 0;
}

unsigned int CSommet::SOMGetTabNbDeparts()
{
	return 0;
}

unsigned int CSommet::SOMGetTNbArrivees()
{
	return 0;
}

void CSommet::SOMSetIndice(unsigned int uiindice)
{
}

void CSommet::SOMSetTabArrivants(CArc** pARCtab)
{
}

void CSommet::SOMSetTabPartants(CArc** pARCtab)
{
}

void CSommet::SOMSetTabNbDeparts(unsigned int uinb)
{
}

void CSommet::SOMSetTNbArrivees(unsigned int uinb)
{
}

void CSommet::SOMAddArcArrivant(CArc* pARCarc)
{
}

void CSommet::SOMAddArcPartant(CArc* pARCarc)
{
}

void CSommet::SOMModArcArrivant(unsigned int uidest, unsigned int uinouvelleDest)
{
}

void CSommet::SOMModArcPartant(unsigned int uidest, unsigned int uinouvelleDest)
{
}

void CSommet::SOMDelArcArrivant(unsigned int uidest)
{
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
