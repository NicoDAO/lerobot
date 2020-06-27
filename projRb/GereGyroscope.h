/*
 * GereGyroscope.h
 *
 *  Created on: 21 juin 2020
 *      Author: nicolas
 */

#ifndef GEREGYROSCOPE_H_
#define GEREGYROSCOPE_H_
#include "TransfertAXI.h"
#include "config_du_system.h"
#include "Tache.h"
#include "Calibrage.h"
#include "Messagerie.h"
#include "LitMemoireLinux.h"

enum{
	gyro_reset = 0,
	gyro_config,
	gyro_tourne
};

class element_config{
public:
	std::string nom_element;
	u16 adresse;
	u16 valeur;
};

class config_totale : public LectureFichier{
public:
	//config_totale();
	//~config_totale();
	std::string nom;
	std::vector<element_config> element;

};


class GereGyroscope : public CagereAXI , public Calibrage {
public:
	GereGyroscope();
	virtual ~GereGyroscope();
	int appliqueCalibre(int val);
	void handler(void);
private :
	u16 etat_gyro = gyro_reset;
	s32 handler_gyro_reset(s32);
	s32 handler_gyro_config(s32);
	s32 handler_gyro_tourne(s32);
	config_totale config_gyro;
	int lit_config_gyro (void);
};

#endif /* GEREGYROSCOPE_H_ */
