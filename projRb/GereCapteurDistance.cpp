/*
 * GereMoteur.cpp
 *
 *  Created on: 6 janv. 2020
 *      Author: nicolas
 */

#include "GereCapteurDistance.h"
#include "config_du_system.h"
GereCapteurDistance::GereCapteurDistance()
{
    //snprintf(this->nom_moteur, sizeof(this->nom_moteur), "moteur????");
    memset(tabMesure, 0, sizeof(tabMesure));
}

GereCapteurDistance::~GereCapteurDistance()
{
}

void GereCapteurDistance::handler()
{
    //Xil_Out32(this->adresseAXI + AXI_SLV_REG2_OFFSET,lescoefs[cpt_coef]); //valeur
    //https://www.xilinx.com/support/documentation/ip_documentation/axi_dma/v7_1/pg021_axi_dma.pdf
    static u32 add = 0;
    static int num = 0;
    printf("\r\nGereCapteurDistance::handler() entree\r\n");
    if (leMessage1->vecteurMessages.empty())
    {
        u32 lit = 0, lit_moy = 0;
        u32 add1 = this->adresseAXI + add;
        lit = Xil_In32(add1);
        ajoute_mesure(lit);
        lit_moy = calculeMesureMoyenne();
//	add++;
        printf("capteur distance : %d (moy %d)\r\n",lit,lit_moy);
        AMessage messCapteur;
        messCapteur.distanceCapteur = lit_moy;
        snprintf(messCapteur.message,sizeof(messCapteur.message),"distance %d/%d",lit,lit_moy);
        //printf(">envoieMessage distance brut = %d  , moyenne = %d   taille %d \r\n", lit,lit_moy,leMessage1->Messager);
      //  int dispo = leMessage1->vecteurMessages.capacity();
        int ret = leMessage1->envoieMessage(&messCapteur);
#ifdef LOG_CAPTEUR
        printf(
            "[%04d]Capteur : envoie message : distance : %d (taille classe = %d/%d)\r\n",
            cpt_tache, lit_moy, sizeof(messCapteur), dispo);
#endif
#ifdef LOG_BARGRAF		//dessin du bargraf
        u8 dist_g = lit_moy/1000;
        char bargraf [256];
        memset(bargraf,0,sizeof(bargraf));
        if(dist_g>=sizeof(bargraf))dist_g =sizeof(bargraf)-1;
        for(u8 u = 0; u < dist_g; u++)
        {
            bargraf[u] = '*';
        }
        printf("  %s\r\n",bargraf);
        for(u8 u = 0; u < dist_g; u++)
        {
            bargraf[u] = '*';
        }
#endif
    }
    else
    {
        printf("[%04d]Capteur : la queue est pleine \r\n");
    }
    printf("Capteur handler sleep %d sortie\r\n\r\n",this->xWakePeriod);
    sleep(this->xWakePeriod);
}

void GereCapteurDistance::ajoute_mesure(int mesure)
{
    if (indexMesure < coef_moyenne/*sizeof(tabMesure)*/)
    {
        tabMesure[indexMesure] = mesure;
    }
    if (indexMesure++ >= coef_moyenne/*sizeof(tabMesure)*/)
    {
        indexMesure = 0;
    }
}

int GereCapteurDistance::calculeMesureMoyenne()
{
    int val_moy = 0;
    for (int i = 0; i < coef_moyenne/*sizeof(tabMesure)*/; i++)
    {
        val_moy += tabMesure[i]; // on fait la somme
    }
    val_moy = val_moy / coef_moyenne /* sizeof(tabMesure)*/;
    return val_moy;
}

