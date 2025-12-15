/* File: 03_rotate.cpp
 * Author: Philippe Latu
 * Source: https://github.com/platu/libsensehat-cpp
 *

 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cmath>

#include <sensehat.h>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // system_clock, seconds, milliseconds

using namespace std;

const int NB_VALS = 8;
const int MAX_NORME_ACCEL = 10;

int saisirValeurs(int tabVal[NB_VALS])
{
    int choixVal;
    cout << "Remplir Tableau a valeurs" << endl;
    for (int i = 0; i < NB_VALS; i++)
    {
        do
        {
            cout << "Saisir val " << i << ";" << endl;
            cin >> choixVal;
        } while (choixVal < 0 || choixVal > 8);
        tabVal[i] = choixVal;
    }
    return tabVal[8];
}

void afficherHistogramme(int tabVal[NB_VALS])
{
    for (int i = 0; i < NB_VALS; i++)
    {
        for (int j = 0; j < tabVal[i]; j++)
        {
            senseSetRGBpixel(i, j, 255, 0, 128);
        }
    }
}

double calculNormeAccel(double x, double y, double z)
{
    double normeAccel;

    normeAccel = sqrt((x * x) + (y * y) + (z * z));

    return normeAccel;
}

double minNormeAccel(double normeAccel, double minNorme)
{
    if (normeAccel < minNorme)
    {
        minNorme = normeAccel;
    }
    return minNorme;
}

int main()
{
    /*int tabVal[NB_VALS];*/
    double x, y, z;
    double normeAccel, normeMin = MAX_NORME_ACCEL;

    if (senseInit())
    {
        cout << "-------------------------------" << endl
             << "Sense Hat initialization Ok." << endl;

        /*         saisirValeurs(tabVal);
                afficherHistogramme(tabVal); */

        for (int i = 0; i < 100; i++)
        {
            sleep_for(milliseconds(100));
            if (senseGetAccelG(x, y, z))
            {
                cout << showpos << fixed << setprecision(6)
                     << "x = " << x
                     << " y = " << y
                     << " z = " << z;
                normeAccel = calculNormeAccel(x, y, z);
                normeMin = minNormeAccel(normeAccel, normeMin);
                cout << "\t-> norme accélération : " << normeAccel << endl;
            }
            else
            {
                cout << "Pas de mesure disponible." << endl;
            }
            cout << "La norme minimale d'accélération mesurée est : " << normeMin << endl;
        }

        cout << "Press joystick button to quit." << endl;
        senseWaitForJoystickEnter();

        senseShutdown();
        cout << "Sense Hat shut down." << endl;
    }

    return EXIT_SUCCESS;
}