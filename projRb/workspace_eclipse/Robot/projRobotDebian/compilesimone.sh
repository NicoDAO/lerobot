#!/bin/bash

rm *.o


 #g++ *.cpp -Llibs -lpthread   $(LIBS) -lrt -o sorie 
 g++ sources/*.cpp -Llibs -lpthread    -lrt -o sorie 

#scp -r -p projRb/ nicolas@10.0.0.12:/home/nicolas/
scp -r -p sources/ nicolas@10.0.0.8:/home/nicolas/


