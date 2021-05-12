#include <string>
#include <iostream>

#include "CGraphe.h"


CGraphe::CGraphe()
{
	pSOMtabSommets = nullptr;
	uinbSommets = 0;
}

CGraphe::CGraphe(CSommet** pSOMsommets, unsigned int uinbSommets)
{
	pSOMtabSommets = pSOMsommets;
	this->uinbSommets = uinbSommets;
}

CGraphe::CGraphe(const CGraphe &GRAgraphe)
{
	pSOMtabSommets = GRAgraphe.pSOMtabSommets;
	uinbSommets = GRAgraphe.uinbSommets;
}

CGraphe::~CGraphe()
{
}

CSommet** CGraphe::GRAGetTabSommets()
{
	return pSOMtabSommets;
}

unsigned int CGraphe::GRAGetnbSommets()
{
	return uinbSommets;
}

void CGraphe::GRASetTabSommets(CSommet** ptabSommets)
{
	pSOMtabSommets = ptabSommets;
}

void CGraphe::GRASetnbSommets(unsigned int uinbSommets)
{
	this->uinbSommets = uinbSommets;
}

void CGraphe::GRAAddSommet(CSommet* pSOMsommet)
{
	uinbSommets++;
	realloc(pSOMtabSommets, uinbSommets * sizeof(CSommet*));

	pSOMtabSommets[uinbSommets] = pSOMsommet;
}

void CGraphe::GRAModSommet(unsigned int uisomm)
{
}

void CGraphe::GRADelSommet(unsigned int uisomm)
{

	for (unsigned int uicompteSommets = 0 ; uicompteSommets < uinbSommets ; uicompteSommets++) {
		if (pSOMtabSommets[uicompteSommets]->SOMGetIndice() == uisomm) {
			//suppression du sommet
			delete pSOMtabSommets[uicompteSommets];

			//suppression de l'element du tableau des arrivees
			for (unsigned int uicompteSuppr = uicompteSommets; uicompteSuppr < uinbSommets; uicompteSuppr++) {
				pSOMtabSommets[uicompteSuppr] = pSOMtabSommets[uicompteSuppr + 1];
			}

			uinbSommets--;
			realloc(pSOMtabSommets, uinbSommets * sizeof(CSommet*));
		}

	}
	

}

void CGraphe::GRAAfficherGraphe()
{
}
