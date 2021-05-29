///
/// @brief header de la classe CArc
/// @file CArc.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-05-12
///

#include <string>
#include <iostream>

///@brief un objet CArc represente une arrete orientee sur le graph
///@details un CArc contient l'attribut uiARCdestination, int representant l'indice du noeud de destination
class CArc
{
private:
	///destination du CArc actuel
	unsigned int uiARCdestination;

public:
	///@brief Constructeur de Carc par defaut
	///@param RIEN
	///@return RIEN
	CArc();

	///@brief Constructeur de CArc avec renseigneent de destination
	///@param uiARCdest : unsigned int indice du sommet de destination
	///@return RIEN
	CArc(unsigned int uiARCdest);

	///@brief Constructuer de CArc de recopie
	///@param ARCarc : CArc a copier
	///@return RIEN
	CArc(const CArc &ARCarc);

	///@brief Destructeur de CArc
	///@param RIEN
	///@return RIEN
	~CArc();

	///@brief Getter de destination d'un CArc
	///@param RIEN
	///@return uiARCdestination : unsigned int indice du sommet de destination actuel de du CArc
	unsigned int ARCGetDestination();

	///@brief Setter de destination d'un CArc
	///@param uiDestination : unsigned int Destionation souhaitee
	///@return RIEN
	void ARCSetDestination(unsigned int uiDestination);

};
