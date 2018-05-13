#ifndef _ARRETE_H_
#define _ARRETE_H_

class Arrete {

	public:
	Arrete(int sommet1, int sommet2);
	int getSommet1();
	int getSommet2();
	int getPoids();
	bool checkArrete(Arrete &arrete);

	
	private:
	int sommet1;
	int sommet2;
	int poids;

};

#endif