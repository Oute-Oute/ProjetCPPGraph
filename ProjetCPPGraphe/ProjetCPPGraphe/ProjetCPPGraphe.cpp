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
	
	CSommet *sommet1 = new CSommet(1);
	CSommet *sommet2 = new CSommet(2);
	CSommet *sommet3 = new CSommet(3);

	sommet1->SOMAddArcPartant(2);
	sommet1->SOMAddArcArrivant(3);

	sommet2->SOMAddArcPartant(3);
	sommet2->SOMAddArcArrivant(1);

	sommet3->SOMAddArcPartant(1);
	sommet3->SOMAddArcArrivant(2);

	CSommet* sommets[3] = { sommet1, sommet2, sommet3 };

	CGraphe graphe (sommets, 3);

	graphe.GRAAfficherGraphe();

	graphe.GRAInverserGraphe();
	std::cout << "/!\\INVERSION DU GRAPHE/!\\" << std::endl;

	graphe.GRAAfficherGraphe();

}