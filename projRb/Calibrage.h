/*
 * Calibrage.h
 *
 *  Created on: 9 mai 2020
 *      Author: nicolas
 */

#ifndef CALIBRAGE_H_
#define CALIBRAGE_H_
#include <string>
#include "LectureFichier.h"
class Calibrage: public LectureFichier {
public:
	Calibrage();
	virtual ~Calibrage();
	void SetfichierCalib(std::string);
	int lit_parametrage(void);
	virtual int appliqueCalibre(int) = 0; //on met une methode virtuelle pure cara chaque périphérique à une regle de calibrage particulière
};

#endif /* CALIBRAGE_H_ */
