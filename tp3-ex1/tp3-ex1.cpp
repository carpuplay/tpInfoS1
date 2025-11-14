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


// Fin sous-programmes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Début variables
    char choix;
    bool repeter = true;
    int n = 0;

    // Fin variables
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if (senseInit()) {
        cout << "Sense Hat initialization Ok." << endl;
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Début instructions
        senseSetRGBpixel(n,0,255,0,0);

        do{
            cout << "ON allume un autre pixel?" << endl;
            cin >> choix;
            if (choix == 'N'){
                repeter = false;
            } else if (choix != 'O')
            {
                cout << "Erreur";
            }else{
                senseSetPixel(n+1,0,255,0,0);
                n++;
            }

        } while ( repeter == true);
        // Fin instructions
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "Press joystick button to quit." << endl;
        senseWaitForJoystickEnter();

        senseShutdown();
        cout << "Sense Hat shut down." << endl;
    }

    return EXIT_SUCCESS;
}
