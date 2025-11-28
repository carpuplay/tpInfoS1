/* File: tp2-ex1.cpp
 * Author: Philippe Latu
 * Source: https://github.com/platu/libsensehat-cpp
 *
 * Patron du code source des séances de travaux pratiques
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <sensehat.h>

using namespace std;
using namespace std::this_thread;  // sleep_for, sleep_until
using namespace std::chrono;       // system_clock, seconds, milliseconds

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Début constantes

// Fin constantes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Début sous-programmes



void AllumerColonne(int colonne, int red, int green, int blue){
    int i;

    for (i=0; i<8; i++ ){
        senseSetRGBpixel(colonne,i, red, green, blue);
    }
}

void AllumerLigne(int ligne, int red, int green, int blue){
    int i;

    for (i=0; i<8; i++ ){
        senseSetRGBpixel(i,ligne, red, green, blue);
    }
}

// Fin sous-programmes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Début variables
    int red1 = 0;
    int green1 = 0;
    int blue1 = 127;

    int stepr = (255-red1)/7;
    int stepg = (255-green1)/7;
    int stepb = (255-blue1)/7;

    int j, i;


    // Fin variables
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if (senseInit()) {
        cout << "Sense Hat initialization Ok." << endl;
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Début instructions
        
            //int y, x;
        //for (i=0; i<8; i++){

            // AllumerColonne(i, red1, green1, blue1);
            // AllumerLigne(i, red1, green1, blue1);
            // sleep_for(milliseconds(500));
        for (j=0; j<8; j++){
            for (i=j; i<8; i++){
                senseSetRGBpixel(i, j, red1, green1, blue1);
                senseSetRGBpixel(j, i, red1, green1, blue1);
            }  
            
            red1 += stepr;

            green1 += stepg;
            blue1 += stepb;
            sleep_for(milliseconds(300));

        }       


        //}
              
        
     
            
            
        // Fin instructions
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "Press joystick button to quit." << endl;
        senseWaitForJoystickEnter();

        senseShutdown();
        cout << "Sense Hat shut down." << endl;
    }
    

    return EXIT_SUCCESS;
}
