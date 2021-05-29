///
/// @brief source de la classe CSommet
/// @file CSommet.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-05/28
///
#include "CSommet.h"

///@brief Constructeur de CSommet par defaut
///@param RIEN
///@return RIEN
CSommet::CSommet()
{
	pARCarrivants = nullptr;
	pARCpartants = nullptr;

	uiSOMindice = 0;
	uiSOMnbArrivees = 0;
	uiSOMnbDeparts = 0;
}

///@brief constructeur de CSommet de confort
///@param unsigned int uiindice : indice du nouveau CSommet
///@return RIEN
CSommet::CSommet(unsigned int uiindice)
{
	pARCarrivants = nullptr;
	pARCpartants = nullptr;

	uiSOMindice = uiindice;
	uiSOMnbArrivees = 0;
	uiSOMnbDeparts = 0;
}

///@brief destructeur de CSommet par defaut
///@return RIEN
///@return RIEN
CSommet::~CSommet()
{
}

///@brief constructeur de CSommet de recopie
///@param const CSommet &SOMsommet : CSommet a copier
///@return RIEN
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

///@brief getter de l’attribut uiSOMindice
///@param RIEN
///@return unsigned int uiSOMindice : indice du CSommet actuel
unsigned int CSommet::SOMGetIndice()
{
	return uiSOMindice;
}

///@brief getter de l’attribut pARCarrivants
///@param RIEN
///@return CArc** pARCarrivants : tableau des CArcs entrants du CSommet actuel
CArc** CSommet::SOMGetTabArrivants()
{
	return pARCarrivants;
}

///@brief getter de l’attribut pARCpartants
///@param RIEN
///@return CArc** pARCpartants : tableau des Carc partants du CSommet actuel
CArc** CSommet::SOMGetTabPartants()
{
	return pARCpartants;
}

///@brief getter de l’attribut uiSOMnbDeparts
///@param RIEN
///@return unsigned int uiSOMnbDeparts : nombre de CArcs sortants du CSommet actuel
unsigned int CSommet::SOMGetTabNbDeparts()
{
	return uiSOMnbDeparts;
}

///@brief getter de l’attribut uiSOMnbArrivees
///@param RIEN
///@return unsigned int uiSOMnbArrivees : nombre de CArcs entrants dans le CSommet actuel
unsigned int CSommet::SOMGetTNbArrivees()
{
	return uiSOMnbArrivees;
}

///@brief setter de l’attribut uiSOMindice
///@param unsigned int uiindice : nouvel indice du CSommet actuel
///@return RIEN
void CSommet::SOMSetIndice(unsigned int uiindice)
{
	uiSOMindice = uiindice;
}

///@brief setter de l’attribut pARCarrivants
///@param CArc** pARCtab: nouveau tableau des CArc arrivants du CSommet actuel
///@return RIEN
void CSommet::SOMSetTabArrivants(CArc** pARCtab)
{
	pARCarrivants = pARCtab;
}

///@brief setter de l’attribut pARCpartants
///@param CArc** pARCtab : nouveau tableau des CArc partants du CSommet actuel
///@return RIEN
void CSommet::SOMSetTabPartants(CArc** pARCtab)
{
	pARCpartants = pARCtab;
}

///@brief setter de l’attribut uiSOMnbDeparts
///@param unsigned int uinb : nouveau nombre de CArc partants du CSommet actuel
///@return RIEN
void CSommet::SOMSetTabNbDeparts(unsigned int uinb)
{
	uiSOMnbDeparts = uinb;
}

///@brief setter de l’attribut uiSOMnbArrivees
///@param unsigned int uinb : nouveau nombre de CArc arrivants au CSommet actuel
///@return RIEN
void CSommet::SOMSetTNbArrivees(unsigned int uinb)
{
	uiSOMnbArrivees = uinb;
}

///@brief ajoute un CArc entrant depuis le CSommet d’indice uiIndice dans la table des CArc partants du CSommet actuel
///@param unsigned int uiIndice : indice du CSommet depuis lequel le nouveau CArc arrive (cet indice peut ne pas exister)
///@return RIEN
void CSommet::SOMAddArcArrivant(unsigned int uiIndice)
{
	CArc* pARCarc = new CArc(uiIndice);

	uiSOMnbArrivees++;

	pARCarrivants = (CArc**)realloc(pARCarrivants, uiSOMnbArrivees * sizeof(CArc*));

	pARCarrivants[uiSOMnbArrivees-1] = pARCarc;
}

///@brief ajoute un CArc partant vers le CSommet d’indice uiIndice  dans la table des CArc arrivants du CSommet actuel
///@param unsigned int uiIndice : indice du CSommet vers lequel le nouveau CArc est dirige (cet indice peut ne pas exister)
///@return RIEN
void CSommet::SOMAddArcPartant(unsigned int uiIndice)
{
	CArc* pARCarc = new CArc(uiIndice);

	uiSOMnbDeparts ++;

	pARCpartants = (CArc**)realloc(pARCpartants, uiSOMnbDeparts * sizeof(CArc*));

	pARCpartants[uiSOMnbDeparts-1] = pARCarc;
}

///@brief modifie l’arc entrant venant du sommet d’indice uiIndice, cet arc vient par la suite du sommet d’indice uiNouvelIndice
///@param unsigned int uiIndice : indice du CSommet de provenance actuel du CArc a modifier
///@param unsigned int uiNouvelIndice : indice du nouveau CSommet qu'on assigne comme prevenance du CArc 
///@return RIEN
void CSommet::SOMModArcArrivant(unsigned int uiIndice, unsigned int uiNouvelIndice)
{
	unsigned int uicompteArc;
	for (uicompteArc = 0; uicompteArc<uiSOMnbArrivees ;uicompteArc++) {
		if (pARCarrivants[uicompteArc]->ARCGetDestination() == uiIndice) {
			pARCarrivants[uicompteArc]->ARCSetDestination(uiNouvelIndice);
		}

	}

}

///@brief modifie l’arc sortant allant vers sommet d’indice uiIndice, cet arc va par la suite vers le sommet d’indice uiNouvelIndice
///detail ATTENTION: cette methode ne modifie pas les arcs entrants ou sortants d’autres CSommets que le CSommet actuel, nous considérons que la modification de ceux-ci dépend de l’utilisation souhaitée.
///@param unsigned int uiIndice : indice du CSommet destination actuel du CArc a modifier
///@param unsigned int uiNouvelIndice : indice du nouveau CSommet qu'on assigne comme destination au CArc 
///@return RIEN
void CSommet::SOMModArcPartant(unsigned int uiIndice, unsigned int uiNouvelIndice)
{
	unsigned int uicompteArc;
	for (uicompteArc = 0; uicompteArc < uiSOMnbDeparts; uicompteArc++) {
		if (pARCpartants[uicompteArc]->ARCGetDestination() == uiIndice) {
			pARCpartants[uicompteArc]->ARCSetDestination(uiNouvelIndice);
		}

	}

}

///@brief supprime le CArc entrant depuis le CSommet d’indice uidest de la table des CArc entrants du CSommet actuel
///@param unsigned int uidest : indice du CSommet de provenance du CArc a supprimer
///@return RIEN
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

///@brief supprime le CArc sortant vers le CSommet d’indice uidest de la table des CArc sortants du CSommet actuel
///@param unsigned int uidest : indice du CSommet destination du CArc a supprimer
///@return RIEN
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

///@brief inverse les tableaux de CArcs entrants et sortants du CSommet actuel
///@param RIEN
///@return RIEN
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