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


#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
#define DATA_CAPTURE  0x25
#define OUT_TEMP 0x26
#define STATUS_REG 0x27
#define OUT_X_L 0x28

#define CDE_ECRIT 0xAA
#define CDE_LIT   0xBB
#define CDE_RESET 255
#define LIT_AXI   0xCC


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
	GestionLog calog;
};

#endif /* GEREGYROSCOPE_H_ */
