// ProjetCPPGraphe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CLecture.h"
#include "CGraphe.h"
using namespace std;


int main()
{
    cout << "Hello World!\n";

	char* nf = (char*)"test.txt";
	CLecture Test(nf);
	Test.LECLireFichier();
	
	CSommet** sommets = new CSommet*[Test.LECGetNbSommets()];
	for (int i = 0; i < Test.LECGetNbSommets(); i++) {
		sommets[i] = new CSommet(Test.LECGetSommets()[i]);
	}
	for (int i = 0; i < Test.LECGetNbArcs(); i++) {
		sommets[Test.LECGetArcsDepart()[i] - 1]->SOMAddArcPartant(Test.LECGetArcsArrivee()[i]);
		sommets[Test.LECGetArcsArrivee()[i] - 1]->SOMAddArcArrivant(Test.LECGetArcsDepart()[i]);
	}


	CGraphe graphe (sommets, 3);

	graphe.GRAAfficherGraphe();

	graphe.GRAInverserGraphe();
	std::cout << "/!\\INVERSION DU GRAPHE/!\\" << std::endl;

	graphe.GRAAfficherGraphe();

	graphe.GRAInverserGraphe();

	std::cout << "ajout manuel d'un sommet dans le graphe\n" << std::endl;
	CSommet *sommet4 = new CSommet(3);

	sommet4->SOMAddArcPartant(1);
	sommet4->SOMAddArcArrivant(2);
	try {
		graphe.GRAAddSommet(sommet4);
	}

	catch (CException *EXCException){
		EXCException->EXCAfficherException();
	}

	graphe.GRAAfficherGraphe();

}