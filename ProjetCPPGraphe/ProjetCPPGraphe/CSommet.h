///
/// @brief header de la classe CArc
/// @file CArc.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-05-12
///

#include <string>
#include <iostream>

#include "CArc.h"

///@brief un objet CSommet represent un noeud sur le graph
class CSommet
{
private:
	//nombre de sommets existants
	unsigned int uiSOMnbSommets;

	//indice du sommet actuel
	unsigned int uiSOMindice;

	//tableau des arcs arrivants
	CArc** pARCarrivants;

	//tableau des arcs partants
	CArc** pARCpartants;

	//nombre d'arcs partants de ce sommet
	unsigned int uiSOMnbDeparts;

	//nommbre d'arcs arrivants a ce sommet
	unsigned int uiSOMnbArrivees;

public:

	///@brief 
	///@param RIEN
	///@return RIEN
	CSommet();

	///@brief
	///@param
	///@return RIEN
	CSommet(unsigned int uiindice);

	///@brief
	///@return RIEN
	///@return RIEN
	~CSommet();

	///@brief
	///@param
	///@return
	CSommet(const CSommet &SOMsommet);

	///@brief
	///@param
	///@return
	unsigned int SOMGetIndice();

	///@brief
	///@param
	///@return
	CArc** SOMGetTabArrivants();

	///@brief
	///@param
	///@return
	CArc** SOMGetTabPartants();

	///@brief
	///@param
	///@return
	unsigned int SOMGetTabNbDeparts();

	///@brief
	///@param
	///@return
	unsigned int SOMGetTNbArrivees();

	///@brief
	///@param
	///@return
	void SOMSetIndice(unsigned int uiindice);

	///@brief
	///@param
	///@return
	void SOMSetTabArrivants(CArc** pARCtab);

	///@brief
	///@param
	///@return
	void SOMSetTabPartants(CArc** pARCtab);

	///@brief
	///@param
	///@return
	void SOMSetTabNbDeparts(unsigned int uinb);

	///@brief
	///@param
	///@return
	void SOMSetTNbArrivees(unsigned int uinb);

	///@brief
	///@param
	///@return
	void SOMAddArcArrivant(CSommet SOMdepart);

	///@brief
	///@param
	///@return
	void SOMAddArcPartant(CSommet SOMarrive);

	///@brief
	///@param
	///@return
	void SOMModArcArrivant(CSommet SOMdest, CSommet SOMnouvelleDest);

	///@brief
	///@param
	///@return
	void SOMModArcPartant(CSommet SOMdest, CSommet SOMnouvelleDest);

	///@brief
	///@param
	///@return
	void SOMDelArcArrivant(unsigned int uidest);

	///@brief
	///@param
	///@return
	void SOMDelArcPartant(unsigned int uidest);

	///@brief
	///@param
	///@return
	void SOMRechercherArcArrivant(unsigned int uidest);

	///@brief
	///@param
	///@return
	void SOMRechercherArcPartant(unsigned int uidest);

};
