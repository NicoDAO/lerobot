/*
 * CgereAXI.cpp
 *
 *  Created on: 2 août 2018
 *      Author: nicolas
 */
//#include "pmod_audio.h"
#include "stdio.h"
#include "string.h"
//#include "xil_io.h"
#define FIR_LA 1
#define TEST_AXI 0
#define FIR_TRANSPARENT 0

#include "TransfertAXI.h"

enum
{
    EtatPasEncoreInitialise = 0, EtatInitEnCours, EtatInitFini
};
enum
{
    Nv_coef = 0, charge_coef, fin_charge
};
//http://www.fpgadeveloper.com/2011/07/read-dip-switches-from-a-microblaze-application.html
CagereAXI::CagereAXI()
{
    xWakePeriod = 1110;
    truc_u8_recoit = (u8*) truc_recoit;
    etat_automate = EtatPasEncoreInitialise;
    val_coef_test = 0;
    chut = 0;
}

CagereAXI::~CagereAXI()
{
}

void CagereAXI::handler()
{
    char truc[100];
    u32 val;
    u32 tt;
    static u32 val_test = 0;
    //xLastWakeTime = xTaskGetTickCount();
    switch (etat_automate)
    {
    case EtatPasEncoreInitialise:
        //status = XGpio_Initialize(&GpioInput, XPAR_AXI_GPIO_0_DEVICE_ID);
        // Set the direction for all signals to be inputs
        //XGpio_SetDataDirection(&GpioInput, 1, 0xFFFFFFFF);
        etat_automate = EtatInitEnCours;
        EtatChargeCoef = Nv_coef;
        log_info(truc, sizeof(truc), "!!EtatPasEncoreInitialise  =%x\r\n",
               etat_automate);
        //	log_info(truc);
        Xil_Out32(0x43C00000 + AXI_SLV_REG0_OFFSET, 0x80000000); //allume l'ampli
        Xil_Out32(this->adresseAXI + PMOD_AUDIO_S00_AXI_SLV_REG3_OFFSET,
                  numFIR); //Regle le numéro du FIR concerné
        Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET, 0x121); //RESET FIR
        cpt_coef = 0;
        //etat_automate =EtatInitFini;
        break;
    case EtatInitEnCours:
        if (chut == 1)
        {
            Xil_Out32(this->adresseAXI + AXI_SLV_REG2_OFFSET, 0x1); //activation du mode transparent
            Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET, 0x125); //
            log_info(truc, sizeof(truc), "FIR %d : mode chut activé\r\n",
                     this->numFIR);
            log_info(truc);
            etat_automate = EtatInitFini;
        }
        else
        {
            val = lescoefs[cpt_coef];
            switch (EtatChargeCoef)
            {
            case Nv_coef:
                Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET, 0x122); //RESET FIR à 1
                sleep(1);
                Xil_Out32(this->adresseAXI + AXI_SLV_REG2_OFFSET, 0x0); //desactivation du mode transparent
                Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET, 0x125); //
                sleep(1);
                Xil_Out32(this->adresseAXI + PMOD_AUDIO_S00_AXI_SLV_REG1_OFFSET,
                          cpt_coef); //adresse
                Xil_Out32(this->adresseAXI + AXI_SLV_REG2_OFFSET,
                          lescoefs[cpt_coef]); //valeur
                Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET, 0x123); //commande
                EtatChargeCoef = charge_coef;
                //log_info(truc, sizeof(truc),"commande 0x123,adresse coef , %x, valeur : %x\n\r",cpt_coef,lescoefs[cpt_coef]);
                //log_info(truc);
                break;
            case charge_coef:
                //valide l'enregistrement du coef dans le filtre
                Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET, 0x124); //reg0
                EtatChargeCoef = Nv_coef;
                cpt_coef++;
                //log_info(truc, sizeof(truc),"commande 0x124,\n\r");
                //	log_info(truc);
                if (cpt_coef >= this->taille_filtre)
                {
                    etat_automate = EtatInitFini;
                    log_info(truc, sizeof(truc),
                             "EtatInitFini cpt_coef = %d/%d\r\n", cpt_coef,
                             this->taille_filtre);
                    log_info(truc);
                }
                break;
            case fin_charge:
                break;
            }
            break;
        case EtatInitFini:
            //	GpioLu = XGpio_DiscreteRead(&GpioInput, 1);
#if 0
            if (GpioLu != VieuGpioLut)
            {
                etat_bouton = (GpioLu >> (this->numFIR - 1)) & 0x01; //si le bouton concerne notre FIR
                if (etat_bouton != etat_ancien_bouton)//si létat du bouton a changé
                {
                    chut = (int) etat_bouton;
                    etat_ancien_bouton = etat_bouton;
                    log_info("FIR : %d : etat bouton = %x", this->numFIR,
                           (int) etat_bouton);
                    etat_automate = EtatPasEncoreInitialise;
                }
                VieuGpioLut = GpioLu;
            }
        }
#endif
        break;
    }
}

u8* truc_u8;
truc_u8 = (u8*) truc;
//	this->GestionLed->bagoteLed(2);

//vTaskDelayUntil(&xLastWakeTime, xWakePeriod);
lapause(0);

}

void CagereAXI::RegleNumeroBouton(uint32 a)
{
    this->numFIR = a;
}

void CagereAXI::RegleAdresseAxi(uint32 a)
{
    this->adresseAXI = a;
}
