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
bool ChoixCouleur(int couleur){
    bool couleur_ok;
    couleur_ok = true;

    switch (couleur)
    {
    case 1:
        cout << senseSetRGBpixel(0,0,255,0,0)<< endl;
        cout << "pixel (0,0) de couleur rouge"<< endl;
        break;
    case 2: 
        cout << senseSetRGBpixel(0,0,0,255,0)<< endl;
        cout << "pixel (0,0) de couleur vert"<< endl;
        break;
    case 3:
        cout << senseSetRGBpixel(0,0,0,0,255)<< endl;
        cout << "pixel (0,0) de couleur bleu"<< endl;
        break;
    
    default:
        cout<< "Valeur non prise en compte !"<< endl;
        couleur_ok = false;
    }
    return couleur_ok;
}
// Fin sous-programmes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Début variables
    int input_couleur;
    bool couleur_ok;
    // Fin variables
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if (senseInit()) {
        cout << "Sense Hat initialization Ok." << endl;
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Début instructions
        cout << "Choix couleur:" ;
        cin >> input_couleur;
        
        couleur_ok = ChoixCouleur(input_couleur);
        while (couleur_ok = false){
            cout << ChoixCouleur (input_couleur);
        }
        
        
        // Fin instructions
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "Press joystick button to quit." << endl;
        senseWaitForJoystickEnter();

        senseShutdown();
        cout << "Sense Hat shut down." << endl;
    }

    return EXIT_SUCCESS;
}
