#include "PanelSolar.h"
#include <numeric>
#include <stdexcept>

PanelSolar::PanelSolar(const std::string& id, float eficiencia)
    : id(id), eficiencia(eficiencia), energiaGenerada(0.0f) {

    if (eficiencia <= 0) {
        throw std::invalid_argument("Eficiencia invalida");
    }
}

void PanelSolar::registrarGeneracion(float wattHora) {
    if (wattHora < 0) {
        throw std::invalid_argument("Energia negativa no permitida");
    }

    historialGeneracion.push_back(wattHora);
    energiaGenerada += wattHora;
}

float PanelSolar::energiaTotal() const {
    return energiaGenerada;
}

float PanelSolar::eficienciaPromedio() const {
    if (historialGeneracion.empty()) return 0.0f;

    float suma = std::accumulate(historialGeneracion.begin(),
                                 historialGeneracion.end(), 0.0f);

    return suma / historialGeneracion.size();
}