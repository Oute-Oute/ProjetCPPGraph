#include <string>
#include <iostream>

#include "CException.h"


CException::CException()
{
}

CException::CException(char cEXCope, char* pEXCmess)
{
}

CException::~CException()
{
}

void CException::EXCGetMessage(char* pEXCmess)
{
}

void CException::EXCSetMessage(char* pEXCmess)
{
}

char CException::EXCGetOperation()
{
	return 0;
}

void CException::EXCSetOperation(char cEXCope)
{
}

void CException::EXCAfficherException()
{
}
