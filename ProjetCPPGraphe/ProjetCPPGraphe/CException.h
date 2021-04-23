///
/// @brief Header de la classe CException
/// @file CEsxeption.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-04/21
///

#include <string>
#include <iostream>

///@brief On throw des objets de type CException pour gerer les exceptions pendant l'execution du code
class CException
{
private:
	char cEXCoperation;

	char* pEXCmessage;

public:

	///@brief Constructeur de CException par defaut
	///@param RIEN
	///@return RIEN
	CException();

	///@brief Constructeur de CException de confort avec indication de l'operation et du message
	///@param cEXCope : char Operateur 
	///@param pEXCmess : char* Message d'exception
	///@return RIEN
	CException(char cEXCope, char* pEXCmess);

	///@brief Destructeur de CException
	///@param RIEN
	///@return RIEN
	~CException();

	/// @brief retourne le message d exception de la CException
	/// @param RIEN
	/// @return sEXCMessage le message d exception
	void EXCGetMessage(char* pEXCmess);

	/// @brief definit le message d exception dans la CException
	/// @param smessage le nouveau message d exception
	/// @return RIEN
	void EXCSetMessage(char* pEXCmess);

	/// @brief retourne l operation concernee par la CException
	/// @param RIEN
	/// @return cEXCOperation l operateur sous forme de char
	char EXCGetOperation();

	/// @brief definit l operation concernee par la CException
	/// @param cOperation l operateur sous forme de char
	/// @return RIEN
	void EXCSetOperation(char cEXCope);

	/// @brief affiche le message d'exception de la CException courante
	/// @param RIEN
	/// @return RIEN
	void EXCAfficherException();

};
