#!/bin/bash

rm *.o


 g++ *.cpp -Llibs -lpthread   $(LIBS) -lrt -o sorie 

