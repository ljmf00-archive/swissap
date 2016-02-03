/*lsferreira programming */


#ifndef MCALC_HPP_INCLUDED
#define MCALC_HPP_INCLUDED

//Include libraries
#include "../lib/libs.hpp"
//Used namespaces
using namespace std;

	void mcalc()
	{
		cout << "PT(1)/EN(2)?: ";
		int choiselang;
		cin >> choiselang;
		if (choiselang == 1)
		{
			cout << "Numero de disciplinas?: ";
			int numsubjects;
			cin >> numsubjects;
			int avarg = 0;
			for (int i = 1; i <= numsubjects; i++)
			{
				cout << "Nome da disciplina?: ";
				string choisename;
				cin >> choisename;

				cout << "Numero de Testes?: ";
				int choisent;
				cin >> choisent;
				int mt = 0;
				for (int i = 1; i <= choisent; i++)
				{
					cout << "% Testes?: ";
					int choisepct;
					cin >> choisepct;
					int pct = choisepct / 100;
					cout << "Testes?: ";
					int choiset;
					cin >> choiset;
					int t = choiset * pct;

					mt += t / choisent;
				}

				cout << "Numero de Trabalhos?: ";
				int choisentr;
				cin >> choisentr;
				int mtr = 0;
				for (int i = 1; i <= choisentr; i++)
				{
					cout << "% Trabalhos?: ";
					int choisepctr;
					cin >> choisepctr;
					int pctr = choisepctr / 100;
					cout << "Trabalhos?: ";
					int choisetr;
					cin >> choisetr;
					int tr = choisetr * pctr;

					mtr += tr / choisentr;
				}


				cout << "% Atitudes e valores: ";
				int choisepcav;
				cin >> choisepcav;
				int pcav = choisepcav / 100;
				cout << "Atitudes e valores: ";
				int choiseav;
				cin >> choiseav;
				int av = choiseav * pcav;

				avarg += (mt + mtr + av) / numsubjects;
			}
			cout << "A tua media e: " << avarg << endl;
		}
		else if (choiselang == 2)
		{

		}


	}

#endif // MCALC_HPP_INCLUDED