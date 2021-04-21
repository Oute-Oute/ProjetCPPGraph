
#include <string>
#include <iostream>

class CException
{
private:
	char cEXCoperation;

	char* pEXCmessage;


public:
	CException();

	CException(char cEXCope, char* pEXCmess);

	~CException();

	void EXCGetMessage(char* pEXCmess);

	void EXCSetMessage(char* pEXCmess);

	char EXCGetOperation();

	void EXCSetOperation(char cEXCope);

	void EXCAfficherException();

};
