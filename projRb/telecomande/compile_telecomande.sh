#!/bin/bash

#rm *.o


 #g++ *.cpp -Llibs -lpthread   $(LIBS) -lrt -o sorie 
 g++ *.cpp -Llibs -lpthread    -lrt -o teleco

#scp -r -p telecommande/ nicolas@10.0.0.12:/home/nicolas/

