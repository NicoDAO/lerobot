#!/bin/bash

rm *.o


 #g++ *.cpp -Llibs -lpthread   $(LIBS) -lrt -o sorie 
 g++ *.cpp -Llibs -lpthread    -lrt -o sorie 

#scp -r -p projRb/ nicolas@10.0.0.12:/home/nicolas/
