#include "arrete.h"
#include <iostream>

using namespace std;

Arrete::Arrete(int sommet1, int sommet2) : sommet1(sommet1), sommet2(sommet2), poids(1){

}



int Arrete::getSommet1(){
	cout<<"yo!"<<endl;
	return sommet1;
}	

int Arrete::getSommet2(){
	return sommet2;
}

int Arrete::getPoids(){
	return poids;
}
	
bool Arrete::checkArrete(Arrete &arrete){
	if(arrete.getSommet1() == sommet1 || arrete.getSommet1() == sommet2 || arrete.getSommet2() == sommet1 || arrete.getSommet2() == sommet2){
		return true;
	}
	return false;	
}	
