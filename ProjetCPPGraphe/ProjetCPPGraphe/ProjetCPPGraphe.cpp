// ProjetCPPGraphe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CLecture.h"
#include "CGraphe.h"
using namespace std;


int main()
{
	/*
    cout << "Hello World!\n";

	char* nf = (char*)"test.txt";
	CLecture Test(nf);
	Test.LECLireFichier();
	*/
	cout << "tests sommets\n";
	CSommet *sommet1 = new CSommet(1);
	CSommet *sommet2 = new CSommet(2);
	CSommet *sommet3 = new CSommet(3);

	cout << "initialisation faite\n";

	sommet1->SOMAddArcPartant(2);
	sommet1->SOMAddArcArrivant(3);
	cout << "sommet 1 complet\n";

	sommet2->SOMAddArcPartant(3);
	sommet2->SOMAddArcArrivant(1);
	cout << "sommet 2 complet\n";

	sommet3->SOMAddArcPartant(1);
	sommet3->SOMAddArcArrivant(2);
	cout << "sommet 3 complet\n";

	CSommet* sommets[3] = { sommet1, sommet2, sommet3 };

	CGraphe graphe (sommets, 3);

	///////////////////////////////////////
	unsigned int uicompteSommets;
	unsigned int uicompteArcs;
	unsigned int uinbSommets = 3;

	for (uicompteSommets = 0; uicompteSommets < uinbSommets; uicompteSommets++) {
		std::cout << "Sommet " << sommets[uicompteSommets]->SOMGetIndice() << " : ";
		CArc ** partants = sommets[uicompteSommets]->SOMGetTabPartants();
		for (uicompteArcs = 0; uicompteArcs < sommets[uicompteSommets]->SOMGetTabNbDeparts(); uicompteArcs++) {
			std::cout << sommets[uicompteSommets]->SOMGetIndice() << "->" << partants[uicompteArcs]->ARCGetDestination() << " ; ";
		}

		std::cout << std::endl;

	}

	//graphe.GRAAfficherGraphe();
}