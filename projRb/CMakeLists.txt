cmake_minimum_required (VERSION 2.6)

project (projRb)

#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "*.cpp")
#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "projRb.cpp")
#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR})
#
#
#

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/projRb.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/Calibrage.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/GereMoteur_test.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/MonPWM.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/ConfigureFIRFPGA.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/GestionTraction.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/ConfigureVolumes.cpp  
	 ${CMAKE_CURRENT_SOURCE_DIR}/LectureFichier.cpp    
	 ${CMAKE_CURRENT_SOURCE_DIR}/GereCapteurDistance.cpp  
	 ${CMAKE_CURRENT_SOURCE_DIR}/LitMemoireLinux.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/SensMoteur.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/GereGyroscope.cpp     
	 ${CMAKE_CURRENT_SOURCE_DIR}/log.cpp         
	 ${CMAKE_CURRENT_SOURCE_DIR}/sockets.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/GereLed.cpp          
	 ${CMAKE_CURRENT_SOURCE_DIR}/Messagerie.cpp         
	 ${CMAKE_CURRENT_SOURCE_DIR}/Tache.cpp
	 ${CMAKE_CURRENT_SOURCE_DIR}/GereMoteur.cpp          
	 ${CMAKE_CURRENT_SOURCE_DIR}/mode_fonctionnement.cpp 
	 ${CMAKE_CURRENT_SOURCE_DIR}/TransfereAXI.cpp
 )

#add_executable(projRb projRb.cpp)
#list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/lit_capteur.cpp)
#list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/CMakeCXXCompilerId.cpp)
add_executable(projRb ${SOURCE})
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(projRb PRIVATE Threads::Threads)
#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "*.cpp")
