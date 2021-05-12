
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class CLecture
{
private:
	char* pLECnomFichier;

	ifstream fmyFile;

	unsigned int uinbArcs;
	
	unsigned int uinbSommets;

	int *itabSommets;

	int *itabArcsDepart;

	int *itabArcsArrivee;


public:
	CLecture();

	CLecture(char* cnF);

	CLecture(const CLecture &LECLecture);

	~CLecture();

	int LECGetNbSommets();

	int LECGetNbArcs();

	int *LECGetSommets();

	int *LECGetArcsDepart();
	
	int *LECGetArcsArrivee();

	void LECSetNbSommets();

	void LECSetNbArcs();

	void LECSetSommets();

	void LECSetArcs();

	void LECLireFichier();

};
