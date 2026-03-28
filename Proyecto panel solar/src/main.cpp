#include <iostream>
#include <vector>
#include "PanelSolar.h"

using namespace std;

int main() {
    vector<PanelSolar> paneles;

    try {
        PanelSolar p1("P1", 0.85);
        PanelSolar p2("P2", 0.90);

        paneles.push_back(p1);
        paneles.push_back(p2);

        float energia;

        for (int i = 0; i < paneles.size(); i++) {
            cout << "Ingrese energia generada para panel " << i+1 << ": ";
            cin >> energia;

            paneles[i].registrarGeneracion(energia);
        }

        for (int i = 0; i < paneles.size(); i++) {
            cout << "\nPanel " << i+1 << endl;
            cout << "Energia total: " << paneles[i].energiaTotal() << endl;
            cout << "Promedio: " << paneles[i].eficienciaPromedio() << endl;
        }

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
