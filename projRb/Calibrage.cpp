/*
 * Calibrage.cpp
 *
 *  Created on: 9 mai 2020
 *      Author: nicolas
 */

#include "Calibrage.h"
#include "log.h"

Calibrage::Calibrage() {
	// TODO Auto-generated constructor stub
}

Calibrage::~Calibrage() {
	// TODO Auto-generated destructor stub
}

Calibrage::Calibrage(GestionLog *lelog ) {
	this->lelog = lelog;

}

void Calibrage::SetfichierCalib(std::string tt){

	ouvrFichierSimu(tt);//on va lire le fichier de parametrage et on rempli le vecteur parametrage
	lit_parametrage();

}
int Calibrage::lit_parametrage(void){
	 for (unsigned i=0; i<parametrage.size(); i++)
		 this->lelog->log_calibre("on lit %d", parametrage.at(i));
	 return 1;
}


