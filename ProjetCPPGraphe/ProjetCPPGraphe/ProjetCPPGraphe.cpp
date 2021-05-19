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
	
	cout << "tests sommets\n";
	CSommet** sommets =new CSommet*[Test.LECGetNbSommets()];
	for (int i = 0; i < Test.LECGetNbSommets(); i++) {
		sommets[i] = new CSommet(Test.LECGetSommets()[i]);
	}
	for (int i = 0; i < Test.LECGetNbArcs(); i++) {
		sommets[Test.LECGetArcsDepart()[i]-1]->SOMAddArcPartant(Test.LECGetArcsArrivee()[i]);
		sommets[Test.LECGetArcsArrivee()[i]-1]->SOMAddArcArrivant(Test.LECGetArcsDepart()[i]);
	}


	cout << "initialisation faite\n";


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

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
