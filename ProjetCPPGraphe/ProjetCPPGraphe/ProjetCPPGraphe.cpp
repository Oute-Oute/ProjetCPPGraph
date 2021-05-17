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
	CSommet *sommet1 = new CSommet(15);
	CSommet *sommet2 = new CSommet(22);
	CSommet *sommet3 = new CSommet(3);

	cout << "initialisation faite\n";

	sommet1->SOMAddArcPartant(*sommet2);
	sommet1->SOMAddArcArrivant(*sommet3);
	cout << "sommet 1 complet\n";

	sommet2->SOMAddArcPartant(*sommet3);
	sommet2->SOMAddArcArrivant(*sommet1);
	cout << "sommet 2 complet\n";

	sommet3->SOMAddArcPartant(*sommet1);
	sommet3->SOMAddArcArrivant(*sommet2);
	cout << "sommet 3 complet\n";

	CSommet* sommets[3] = { sommet1, sommet2, sommet3 };

	CGraphe graphe = CGraphe(sommets, 3);
	graphe.GRAAfficherGraphe();
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
