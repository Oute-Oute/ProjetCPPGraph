
///
/// @brief header de la classe CGraphe
/// @file CGraphe.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-05-28
///

#include <string>
#include <iostream>

#include "CException.h"
#include "CSommet.h"

///@brief la classe CGraphe represente un graphique contenant des sommets et des arcs qui les relient
class CGraphe
{
private:
	///tableau des CSommet contenus dans le CGraphe actuel
	CSommet** pSOMtabSommets;
	///nombhre de CSommet du CGraphe actuel
	unsigned int uinbSommets;

public:

	///@brief Constructeur de CGraph par defaut
	///@param RIEN
	///@return RIEN
	CGraphe();

	///@brief  constructeur de CGraphe confort 
	///@param pSOMsommets : CSommet** tableau de pointeurs vers les sommets du CGraph
	///@param uinbSommets : unsigned int correspondant au nombre de sommets du CGraph
	///@return RIEN
	CGraphe(CSommet** pSOMsommets, unsigned int uinbSommets);

	///@brief constructeur de CGraphe de recopie
	///@param  CGraphe &GRAgraphe : CGraphe a recopier
	///@return RIEN
	CGraphe(const CGraphe &GRAgraphe);

	///@brief destructeur de CGraphe
	///@param RIEN
	///@return RIEN
	~CGraphe();

	///@brief  getter de l’attribut pSOMtabSommets
	///@param RIEN
	///@return CSommet** pSOMtabSommets : tableau des sommets du CGraphe
	CSommet** GRAGetTabSommets();

	///@brief getter de l’attribut uinbSommets
	///@param RIEN
	///@return unsigned int uinbSommets : nombre de sommets du CGraphe
	unsigned int GRAGetnbSommets();

	///@brief setter de l’attribut pSOMtabSommets
	///@param CSommet** ptabSommets : nouveau tableau de sommets 
	///@return RIEN
	void GRASetTabSommets(CSommet** ptabSommets);

	///@brief setter setter de l’attribut uinbSommets
	///@param unsigned int uinbSommets : nouveau nombre de sommets
	///@return RIEN
	void GRASetnbSommets(unsigned int uinbSommets);

	///@brief ajoute le sommet au graphe
	///@param CSommet* pSOMsommet : pointeur vers le CSommet a ajouter
	///@return RIEN
	void GRAAddSommet(CSommet* pSOMsommet);

	///@brief modifie le sommet d’indice uiindice du graphe actuel, on lui donne l’indice uinewIndice
	///@details ATTENTION : cette méthode ne modifie pas les tableaux d’arcs partants et arrivants des autres sommets, nous considérons que la modification de ceux-ci dépend de l’utilisation souhaitée
	///@param unsigned int uindice : indice du CSommet a modifier
	///@param unsigned int uinewIndice : nouvel indice assigne au CSommet
	///@return RIEN
	void GRAModSommet(unsigned int uindice, unsigned int uinewIndice);

	///@brief retire le CSommet d’indice uisomm du CGraphe actuel
	///@param unsigned int uisomm : indice du CSommet a retirer
	///@return RIEN
	void GRADelSommet(unsigned int uisomm);

	///@brief affiche le graphique dans la sortie par défaut 
	///@details affichage du nombre de sommets, leurs indices et les arcs sortants de chaque sommets
	///@param RIEN
	///@return RIEN
	void GRAAfficherGraphe();

	///@brief inverse tous les arcs du graphe actuel
	///@param RIEN
	///@return RIEN
	void GRAInverserGraphe();
};
