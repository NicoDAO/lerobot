#!/bin/bash


echo recopie les fichiers dans le repertoire d excecution
cp capteur_distance.calib workspace_eclipse/Robot/projRobotDebian
cp capteur_gyroscope1.calib  workspace_eclipse/Robot/projRobotDebian
cp config_gyroscope	workspace_eclipse/Robot/projRobotDebian
cp moteur1.calib           workspace_eclipse/Robot/projRobotDebian
cp moteur2.calib          workspace_eclipse/Robot/projRobotDebian
cp simu_capteur_distance.txt  workspace_eclipse/Robot/projRobotDebian
//cp -r * workspace_eclipse/Robot/projRobotDebian
echo fait

