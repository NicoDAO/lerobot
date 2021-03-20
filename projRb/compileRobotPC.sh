#!/bin/bash

#creation des fichiers de sorties en fonction de la date
export fichier_sortie_compile=log_compile_$(date -I).log
export fichier_sortie_ccpcheck=log_cppcheck_$(date -I).log
echo log de la compile: $fichier_sortie_compile , log de cppcheck $fichier_sortie_ccpcheck
echo ************************************************************************************
echo *                                                                                  *
echo *                                                                                  *
echo *                                                                                  *
echo *                                                                                  *
echo *                                                                                  *
echo *         par  TOUTATIS                                                            *
echo *                                                                                  *
echo *                                                                                  *
echo *                                                                                  *
echo *                                                                                  *
echo *                                                                                  *
echo *                                                                                  *
echo *                                                                                  *
echo ************************************************************************************
sleep 1
g++ sources/*.cpp -v -Llibs -lpthread    -lrt -o execute_robot 1>2 $fichier_sortie_compile 
sh  analyse_code.sh | tee $fichier_sortie_ccpcheck

