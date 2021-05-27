#include <string>
#include <iostream>

#include "CException.h"
#include "CSommet.h"

class CGraphe
{
private:
	CSommet** pSOMtabSommets;

	unsigned int uinbSommets;

public:

	///@brief Constructeur de CGraph par defaut
	///@param RIEN
	///@return RIEN
	CGraphe();

	///@brief constructeur de CGraphe de comfort
	///@param pSOMsommets : CSommet** tableau de pointeurs vers les sommets du CGraph
	///@param uinbSommets : unsigned int correspondant au nombre de sommets du CGraph
	///@return RIEN
	CGraphe(CSommet** pSOMsommets, unsigned int uinbSommets);

	///@brief
	///
	///
	CGraphe(const CGraphe &GRAgraphe);

	///
	///
	///
	~CGraphe();

	///
	///
	///
	CSommet** GRAGetTabSommets();

	///
	///
	///
	unsigned int GRAGetnbSommets();

	///
	///
	///
	void GRASetTabSommets(CSommet** ptabSommets);

	///
	///
	///
	void GRASetnbSommets(unsigned int uinbSommets);

	///
	///
	///
	void GRAAddSommet(CSommet* pSOMsommet);

	///
	///
	///
	void GRADelSommet(unsigned int uisomm);

	///
	///
	///
	void GRAAfficherGraphe();

	///
	///
	///
	void GRAInverserGraphe();
};
