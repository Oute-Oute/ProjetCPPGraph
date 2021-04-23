///
/// @brief Source de la classe CException
/// @file CEsxeption.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-04/21
///

#include "CException.h"
using namespace std;

///@brief Constructeur de CException par defaut
///@param RIEN
///@return RIEN
CException::CException() {
	pEXCmessage = (char*) "Exception innatendue";
	cEXCoperation = '0';
}

///@brief Constructeur de CException de confort avec indication de l'operation et du message
///@param cEXCope : char Operateur 
///@param pEXCmess : char* Message d'exception
///@return RIEN
CException::CException(char cEXCope, char * pEXCmess)
{
	pEXCmessage = pEXCmess;
	cEXCoperation = cEXCope;
}

///@brief Destructeur de CException
///@param RIEN
///@return RIEN
CException::~CException() {

}

/// @brief retourne le message d exception de la CException
/// @param RIEN
/// @return sEXCMessage le message d exception
void CException::EXCGetMessage(char* pEXCmess) {
	strcpy_s(pEXCmess, sizeof pEXCmess, pEXCmessage);
}

/// @brief definit le message d exception dans la CException
/// @param smessage le nouveau message d exception
/// @return RIEN
void CException::EXCSetMessage(char* pEXCmess) {
	pEXCmessage = pEXCmess;
}

/// @brief retourne l operation concernee par la CException
/// @param RIEN
/// @return cEXCOperation l operateur sous forme de char
char CException::EXCGetOperation() {
	return cEXCoperation;
}

/// @brief definit l operation concernee par la CException
/// @param cOperation l operateur sous forme de char
/// @return RIEN
void CException::EXCSetOperation(char cEXCope) {
	cEXCoperation = cEXCope;
}

/// @brief affiche le message d'exception de la CException courante
/// @param RIEN
/// @return RIEN
void CException::EXCAfficherException() {
	cout << "Operation " << cEXCoperation << ", exception: " << pEXCmessage << endl;
}


