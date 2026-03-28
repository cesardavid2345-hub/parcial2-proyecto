#ifndef PANEL_SOLAR_H
#define PANEL_SOLAR_H

#include <string>
#include <vector>

/**
 * @brief Clase que representa un panel solar.
 */
class PanelSolar {
private:
    std::string id;
    float eficiencia;
    float energiaGenerada;
    std::vector<float> historialGeneracion;

public:
    /**
     * @brief Constructor
     * @param id Identificador del panel
     * @param eficiencia Eficiencia inicial
     */
    PanelSolar(const std::string& id, float eficiencia);

    /**
     * @brief Registra energía generada
     * @param wattHora Energía en Wh
     */
    void registrarGeneracion(float wattHora);

    /**
     * @brief Obtiene energía total
     * @return Energía acumulada
     */
    float energiaTotal() const;

    /**
     * @brief Calcula promedio de generación
     * @return Promedio
     */
    float eficienciaPromedio() const;
};

#endif