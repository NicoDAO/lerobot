/*
 * CgereAXI.h
 *
 *  Created on: 2 août 2018
 *      Author: nicolas
 */

#ifndef SRC_TRANSFERTAXI_H_
#define SRC_TRANSFERTAXI_H_

#include "stdio.h"
#include "Tache.h"
#include "type.h"
#include "config_du_system.h"
#include "xparameters.h"
#include "log.h"
#include "config_du_system.h"
//#include "xbasic_types.h"

//#include "xstatus.h"

#include "LitMemoireLinux.h"

class CagereAXI : public Tache, public LitMemoireLinux {
public:
	CagereAXI();
	virtual ~CagereAXI();
	void handler(void);

	void RegleNumeroBouton(uint32);
	int taille_filtre;
	unsigned int * lescoefs;
	void RegleAdresseAxi(uint32);

private:

	bool etat_ancien_bouton;
	bool etat_bouton;
	char truc_recoit[100];
	u8* truc_u8_recoit;
	uint32 numFIR;
	//Xuint32 DataRead;
	u32 DataRead;
	u8 chut;
	uint32 val_coef_test;
	GestionLog calog;
protected:
	int etat_automate;
	int EtatChargeCoef;
	int cpt_coef;
#if UTILISE_GPIO_AXI == 1
	XGpio GpioInput;
#else
	//XGpioPs GpioInput;

#endif
	u32 GpioLu;
	u32 VieuGpioLut;
	u32 status;
	u32 adresseAXI;


};


#endif /* SRC_TRANSFERTAXI_H_ */
