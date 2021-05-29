///
/// @brief source de la classe CArc
/// @file CArc.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-05/28
///

#include "CArc.h"

///@brief Constructeur de Carc par defaut
///@param RIEN
///@return RIEN
CArc::CArc()
{
	uiARCdestination = 0;
}

///@brief Constructeur de CArc avec renseigneent de destination
///@param uiARCdest : unsigned int indice du sommet de destination
///@return RIEN
CArc::CArc(unsigned int uiARCdest)
{
	uiARCdestination = uiARCdest;
}

///@brief Constructuer de CArc de recopie
///@param ARCarc : CArc a copier
///@return RIEN
CArc::CArc(const CArc &ARCarc)
{
	uiARCdestination = ARCarc.uiARCdestination;
}

///@brief Destructeur de CArc
///@param RIEN
///@return RIEN
CArc::~CArc()
{
}

///@brief Getter de destination d'un CArc
///@param RIEN
///@return uiARCdestination : unsigned int indice du sommet de destination actuel de du CArc
unsigned int CArc::ARCGetDestination()
{
	return uiARCdestination;
}

///@brief Setter de destination d'un CArc
///@param uiDestination : unsigned int Destionation souhaitee
///@return RIEN
void CArc::ARCSetDestination(unsigned int uiDestination)
{
	uiARCdestination = uiDestination;
}
