
///
/// @brief source de la classe CGraphe
/// @file CGraphe.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-05/28
///

#include "CGraphe.h"

///@brief Constructeur de CGraph par defaut
///@param RIEN
///@return RIEN
CGraphe::CGraphe()
{
	pSOMtabSommets = nullptr;
	uinbSommets = 0;
}

///@brief  constructeur de CGraphe confort 
///@param pSOMsommets : CSommet** tableau de pointeurs vers les sommets du CGraph
///@param uinbSommets : unsigned int correspondant au nombre de sommets du CGraph
///@return RIEN
CGraphe::CGraphe(CSommet** pSOMsommets, unsigned int uinbSommets)
{
	CException *EXCException = new CException();
	EXCException->EXCSetOperation((char*)"creation d'un graphe");

	for (unsigned int uicompteSommets = 0; uicompteSommets < uinbSommets-1; uicompteSommets++) {
		for (unsigned int uicompareSommets = uicompteSommets+1; uicompareSommets < uinbSommets; uicompareSommets++) {
			if (pSOMsommets[uicompteSommets]->SOMGetIndice() == pSOMsommets[uicompareSommets]->SOMGetIndice()) {
				EXCException->EXCSetMessage((char*)"un indice apparait 2 fois dans le graphe");
				throw EXCException;
			}

		}

	}

	pSOMtabSommets = pSOMsommets;
	this->uinbSommets = uinbSommets;
}

///@brief constructeur de CGraphe de recopie
///@param  CGraphe &GRAgraphe : CGraphe a recopier
///@return RIEN
CGraphe::CGraphe(const CGraphe &GRAgraphe)
{
	pSOMtabSommets = GRAgraphe.pSOMtabSommets;
	uinbSommets = GRAgraphe.uinbSommets;
}

///@brief destructeur de CGraphe
///@param RIEN
///@return RIEN
CGraphe::~CGraphe()
{
}

///@brief  getter de l’attribut pSOMtabSommets
///@param RIEN
///@return CSommet** pSOMtabSommets : tableau des sommets du CGraphe
CSommet** CGraphe::GRAGetTabSommets()
{
	return pSOMtabSommets;
}

///@brief getter de l’attribut uinbSommets
///@param RIEN
///@return unsigned int uinbSommets : nombre de sommets du CGraphe
unsigned int CGraphe::GRAGetnbSommets()
{
	return uinbSommets;
}

///@brief setter de l’attribut pSOMtabSommets
///@param CSommet** ptabSommets : nouveau tableau de sommets 
///@return RIEN
void CGraphe::GRASetTabSommets(CSommet** ptabSommets)
{
	pSOMtabSommets = ptabSommets;
}

///@brief setter setter de l’attribut uinbSommets
///@param unsigned int uinbSommets : nouveau nombre de sommets
///@return RIEN
void CGraphe::GRASetnbSommets(unsigned int uinbSommets)
{
	this->uinbSommets = uinbSommets;
}

///@brief modifie le sommet d’indice uiindice du graphe actuel, on lui donne l’indice uinewIndice
///@detail ATTENTION : cette méthode ne modifie pas les tableaux d’arcs partants et arrivants des autres sommets, nous considérons que la modification de ceux-ci dépend de l’utilisation souhaitée
///@param unsigned int uindice : indice du CSommet a modifier
///@param unsigned int uinewIndice : nouvel indice assigne au CSommet
///@return RIEN
void CGraphe::GRAModSommet(unsigned int uiindice, unsigned int uinewIndice)
{
	if (uiindice != uinewIndice) {
		CException *EXCException = new CException();
		EXCException->EXCSetOperation((char*)"modification d'un sommet dans un graphe");

		for (unsigned int uicompteSommets = 0; uicompteSommets < uinbSommets; uicompteSommets++) {
			if (pSOMtabSommets[uicompteSommets]->SOMGetIndice() == uinewIndice) {
				EXCException->EXCSetMessage((char*)"le nouvel indice de ce somment existe deja dans ce graphe");
				throw EXCException;
			}

		}

		for (unsigned int uicompteSommets = 0; uicompteSommets < uinbSommets; uicompteSommets++) {
			if (pSOMtabSommets[uicompteSommets]->SOMGetIndice() == uiindice) {
				pSOMtabSommets[uicompteSommets]->SOMSetIndice(uinewIndice);
			}

		}

	}

}

///@brief ajoute le sommet au graphe
///@param CSommet* pSOMsommet : pointeur vers le CSommet a ajouter
///@return RIEN
void CGraphe::GRAAddSommet(CSommet* pSOMsommet)
{
	CException *EXCException = new CException();
	EXCException->EXCSetOperation((char*)"ajout d'un sommet dans un graphe");

	for (unsigned int uicompteSommets = 0; uicompteSommets < uinbSommets; uicompteSommets++) {
		if (pSOMtabSommets[uicompteSommets]->SOMGetIndice() == pSOMsommet->SOMGetIndice()) {
			EXCException->EXCSetMessage((char*)"l'indice de ce somment existe deja dans ce graphe");
			throw EXCException;
		}

	}

	uinbSommets++;
	realloc(pSOMtabSommets, uinbSommets * sizeof(CSommet*));

	pSOMtabSommets[uinbSommets] = pSOMsommet;
}

///@brief retire le CSommet d’indice uisomm du CGraphe actuel
///@param unsigned int uisomm : indice du CSommet a retirer
///@return RIEN
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

///@brief affiche le graphique dans la sortie par défaut 
///@detail affichage du nombre de sommets, leurs indices et les arcs sortants de chaque sommets
///@param RIEN
///@return RIEN
void CGraphe::GRAAfficherGraphe()
{
	
	std::cout << "Ce graphique contient " << uinbSommets << " sommets d'indices:" << std::endl;

	unsigned int uicompteSommets;
	unsigned int uicompteArcs;
	
	for (uicompteSommets = 0 ; uicompteSommets < uinbSommets; uicompteSommets++) {
		std::cout << pSOMtabSommets[uicompteSommets]->SOMGetIndice();
		
		if (uicompteSommets < uinbSommets-1) {
			std::cout<< " ; ";
		}

	}

	std::cout << "\n\n";
	std::cout << "Liste des sommets et les destinations de leurs arcs partants:" << std::endl;

	for (uicompteSommets = 0; uicompteSommets < uinbSommets; uicompteSommets++) {
		std::cout << "Sommet " << pSOMtabSommets[uicompteSommets]->SOMGetIndice() << " : ";
		CArc ** partants = pSOMtabSommets[uicompteSommets]->SOMGetTabPartants();
		for (uicompteArcs = 0 ; uicompteArcs < pSOMtabSommets[uicompteSommets]->SOMGetTabNbDeparts(); uicompteArcs++) {
			std::cout << pSOMtabSommets[uicompteSommets]->SOMGetIndice() << "->" << partants[uicompteArcs]->ARCGetDestination() << " ; ";
		}

		std::cout << std::endl;

	}
	std::cout << std::endl;
}

///@brief inverse tous les arcs du graphe actuel
///@param RIEN
///@return RIEN
void CGraphe::GRAInverserGraphe() {
	for (unsigned int uiCompteSommets = 0 ; uiCompteSommets < GRAGetnbSommets() ; uiCompteSommets++) {
		pSOMtabSommets[uiCompteSommets]->SOMInverseTableaux();
	}

}