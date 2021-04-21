
#include <string>
#include <iostream>

#include "CSommet.h"
#include "const CGraphe.h"

class CGraphe
{
private:
	CSommet** pSOMsommets;

	unsigned int uinbSommets;


public:
	CGraph();

	CGraph(CSommet** pSOMsommets, unsigned int uinbSommets);

	CGraph(const CGraphe &GRAgraphe);

	~CGraphe();

	CSommet** GRAGetTabSommets();

	unsigned int GRAGetnbSommets();

	void GRASetTabSommets(CSommet** ptabSommets);

	void GRASetnbSommets(unsigned int uinbSommets);

	void GRAAddSommet(CSommet* pSOMsommet);

	void GRAModSommet(unsigned int uisomm);

	void GRADelSommet(unsigned int uisomm);

	void GRAAfficherGraphe();

};
