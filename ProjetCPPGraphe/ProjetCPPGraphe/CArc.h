
#include <string>
#include <iostream>

#include "const CArc.h"

class CArc
{
private:
	unsigned int uiARCdestination;


public:
	CArc();

	CArc(unsigned int uiARCdest);

	CArc(const CArc &ARCarc);

	~ CArc();

	unsigned int ARCGetDestination();

	void ARCSetDestination(unsigned int uiDestination);

};
