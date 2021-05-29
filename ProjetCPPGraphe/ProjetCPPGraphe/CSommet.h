///
/// @brief header de la classe CSommet
/// @file CSommet.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-05-22
///

#include <string>
#include <iostream>
#include "CArc.h"

///@brief un objet CSommet represent un noeud sur le graph
class CSommet
{
private:
	///indice du sommet actuel
	unsigned int uiSOMindice;

	///tableau des arcs arrivants
	CArc** pARCarrivants;

	///tableau des arcs partants
	CArc** pARCpartants;

	///nombre d'arcs partants de ce sommet
	unsigned int uiSOMnbDeparts;

	///nommbre d'arcs arrivants a ce sommet
	unsigned int uiSOMnbArrivees;

public:

	///@brief Constructeur de CSommet par defaut
	///@param RIEN
	///@return RIEN
	CSommet();

	///@brief constructeur de CSommet de confort
	///@param unsigned int uiindice : indice du nouveau CSommet
	///@return RIEN
	CSommet(unsigned int uiindice);

	///@brief destructeur de CSommet par defaut
	///@return RIEN
	///@return RIEN
	~CSommet();

	///@brief constructeur de CSommet de recopie
	///@param const CSommet &SOMsommet : CSommet a copier
	///@return RIEN
	CSommet(const CSommet &SOMsommet);

	///@brief getter de l’attribut uiSOMindice
	///@param RIEN
	///@return unsigned int uiSOMindice : indice du CSommet actuel
	unsigned int SOMGetIndice();

	///@brief getter de l’attribut pARCarrivants
	///@param RIEN
	///@return CArc** pARCarrivants : tableau des CArcs entrants du CSommet actuel
	CArc** SOMGetTabArrivants();

	///@brief getter de l’attribut pARCpartants
	///@param RIEN
	///@return CArc** pARCpartants : tableau des Carc partants du CSommet actuel
	CArc** SOMGetTabPartants();

	///@brief getter de l’attribut uiSOMnbDeparts
	///@param RIEN
	///@return unsigned int uiSOMnbDeparts : nombre de CArcs sortants du CSommet actuel
	unsigned int SOMGetTabNbDeparts();

	///@brief getter de l’attribut uiSOMnbArrivees
	///@param RIEN
	///@return unsigned int uiSOMnbArrivees : nombre de CArcs entrants dans le CSommet actuel
	unsigned int SOMGetTNbArrivees();

	///@brief setter de l’attribut uiSOMindice
	///@param unsigned int uiindice : nouvel indice du CSommet actuel
	///@return RIEN
	void SOMSetIndice(unsigned int uiindice);

	///@brief setter de l’attribut pARCarrivants
	///@param CArc** pARCtab: nouveau tableau des CArc arrivants du CSommet actuel
	///@return RIEN
	void SOMSetTabArrivants(CArc** pARCtab);

	///@brief setter de l’attribut pARCpartants
	///@param CArc** pARCtab : nouveau tableau des CArc partants du CSommet actuel
	///@return RIEN
	void SOMSetTabPartants(CArc** pARCtab);

	///@brief setter de l’attribut uiSOMnbDeparts
	///@param unsigned int uinb : nouveau nombre de CArc partants du CSommet actuel
	///@return RIEN
	void SOMSetTabNbDeparts(unsigned int uinb);

	///@brief setter de l’attribut uiSOMnbArrivees
	///@param unsigned int uinb : nouveau nombre de CArc arrivants au CSommet actuel
	///@return RIEN
	void SOMSetTNbArrivees(unsigned int uinb);

	///@brief ajoute un CArc entrant depuis le CSommet d’indice uiIndice dans la table des CArc partants du CSommet actuel
	///@param unsigned int uiIndice : indice du CSommet depuis lequel le nouveau CArc arrive (cet indice peut ne pas exister)
	///@return RIEN
	void SOMAddArcArrivant(unsigned int uiIndice);

	///@brief ajoute un CArc partant vers le CSommet d’indice uiIndice  dans la table des CArc arrivants du CSommet actuel
	///@param unsigned int uiIndice : indice du CSommet vers lequel le nouveau CArc est dirige (cet indice peut ne pas exister)
	///@return RIEN
	void SOMAddArcPartant(unsigned int uiIndice);

	///@brief modifie l’arc entrant venant du sommet d’indice uiIndice, cet arc vient par la suite du sommet d’indice uiNouvelIndice
	///details ATTENTION: cette methode ne modifie pas les arcs sortants d’autres CSommets que le CSommet actuel, nous considérons que la modification de ceux-ci dépend de l’utilisation souhaitée.
	///@param unsigned int uiIndice : indice du CSommet de provenance actuel du CArc a modifier
	///@param unsigned int uiNouvelIndice : indice du nouveau CSommet qu'on assigne comme prevenance du CArc 
	///@return RIEN
	void SOMModArcArrivant(unsigned int uiIndice, unsigned int uiNouvelIndice);

	///@brief modifie l’arc sortant allant vers sommet d’indice uiIndice, cet arc va par la suite vers le sommet d’indice uiNouvelIndice
	///details ATTENTION: cette methode ne modifie pas les arcs entrants d’autres CSommets que le CSommet actuel, nous considérons que la modification de ceux-ci dépend de l’utilisation souhaitée.
	///@param unsigned int uiIndice : indice du CSommet destination actuel du CArc a modifier
	///@param unsigned int uiNouvelIndice : indice du nouveau CSommet qu'on assigne comme destination au CArc 
	///@return RIEN
	void SOMModArcPartant(unsigned int uiIndice, unsigned int uiNouvelIndice);

	///@brief supprime le CArc entrant depuis le CSommet d’indice uidest de la table des CArc entrants du CSommet actuel
	///@param unsigned int uidest : indice du CSommet de provenance du CArc a supprimer
	///@return RIEN
	void SOMDelArcArrivant(unsigned int uidest);

	///@brief supprime le CArc sortant vers le CSommet d’indice uidest de la table des CArc sortants du CSommet actuel
	///@param unsigned int uidest : indice du CSommet destination du CArc a supprimer
	///@return RIEN
	void SOMDelArcPartant(unsigned int uidest);

	///@brief inverse les tableaux de CArcs entrants et sortants du CSommet actuel
	///@param RIEN
	///@return RIEN
	void SOMInverseTableaux();

};
