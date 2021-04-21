
#include <string>
#include <iostream>

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
