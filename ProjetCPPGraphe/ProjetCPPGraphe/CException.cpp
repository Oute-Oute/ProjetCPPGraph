///
/// @brief Source de la classe CException
/// @file CEsxeption.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-05/09
///

#include "CException.h"
using namespace std;

///@brief Constructeur de CException par defaut
///@param RIEN
///@return RIEN
CException::CException() {
	pEXCmessage = (char*) "Exception inatendue";
	pEXCoperation = (char*)"inconnue";
}

///@brief Constructeur de CException de confort avec indication de l'operation et du message
///@param cEXCope : char* Operation 
///@param pEXCmess : char* Message d'exception
///@return RIEN
CException::CException(char* pEXCope, char * pEXCmess)
{
	pEXCmessage = pEXCmess;
	pEXCoperation = pEXCope;
}

///@brief Destructeur de CException
///@param RIEN
///@return RIEN
CException::~CException() {

}

/// @brief copie le message d'exception dans le char* en parametre
/// @param char* pEXCmess
/// @return RIEN
void CException::EXCGetMessage(char* pEXCmess) {
	strcpy_s(pEXCmess, sizeof pEXCmess, pEXCmessage);
}

/// @brief definit le message d exception dans la CException
/// @param char* pEXCmess le nouveau message d exception
/// @return RIEN
void CException::EXCSetMessage(char* pEXCmess) {
	pEXCmessage = pEXCmess;
}

/// @brief copie l'operation d'exception dans le char* en parametre
/// @param char* pEXCope
/// @return RIEN
void CException::EXCGetOperation(char* pEXCope) {
	strcpy_s(pEXCope, sizeof pEXCope, pEXCoperation);
}

/// @brief definit l operation concernee par la CException
/// @param char* pEXCope : la nouvelle operation du CException actuel
/// @return RIEN
void CException::EXCSetOperation(char* pEXCope) {
	pEXCoperation = pEXCope;
}

/// @brief affiche le message d'exception de la CException courante
/// @param RIEN
/// @return RIEN
void CException::EXCAfficherException() {
	cout << "Operation " << pEXCoperation << ", exception: " << pEXCmessage << endl;
}


