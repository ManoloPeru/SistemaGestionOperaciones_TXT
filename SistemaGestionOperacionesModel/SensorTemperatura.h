#pragma once
#include "Sensor.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase SensorTemperatura
    public ref class SensorTemperatura : public Sensor {
    private:
        String^ unidad;

    public:
        // Constructor vacio
        SensorTemperatura();

        // Constructor con todos los par�metros
        SensorTemperatura(String^ unidad);

        // Metodos GET
        String^ getUnidad();

        // Metodos SET
        void setUnidad(String^ unidad);

        // M�todos
        void ReportarTemperatura();
    };
}