#pragma once
#include "Sensor.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase SensorProximidad
    public ref class SensorProximidad : public Sensor {
    private:
        String^ unidad;

    public:
        // Constructor vacio
        SensorProximidad();

        // Constructor con todos los par�metros
        SensorProximidad(String^ unidad);

        // Metodos GET
        String^ getUnidad();

        // Metodos SET
        void setUnidad(String^ unidad);

        // M�todos
        void DetectarObjeto();
    };
}