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
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x2B
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D
#define CDE_ECRIT 0xAA
#define CDE_LIT   0xBB
#define CDE_RESET 0xff
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

class Donnees_gyroscope{
public:
        Donnees_gyroscope();
        ~Donnees_gyroscope();
	s16 x_l = 0;
	s16 y_l = 0;
	s16 z_l = 0;

	s16 x_h = 0;
	s16 y_h = 0;
	s16 z_h = 0;
        
        s16 calc_x;
        s16 calc_y;
        s16 calc_z;
	void raz(void);
        void calcul(void);
	void integre(void);
	
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
        u32 litRegistreGyro(u8);
        Donnees_gyroscope    donne_gyro; 
};

#endif /* GEREGYROSCOPE_H_ */
