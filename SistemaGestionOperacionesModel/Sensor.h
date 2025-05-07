#pragma once
#include "Dispositivo.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase Sensor
    public ref class Sensor : public Dispositivo {
    protected:
        float precision;
        float rangoMin;
        float rangoMax;
        float valorActual;

    public:
        // Constructor vacio
        Sensor();

        // Constructor con todos los parámetros
        Sensor(float precision, float rangoMin, float rangoMax, float valorActual);

        // Metodos GET
        float getPrecision();
        float getRangoMin();
        float getRangoMax();
        float getValorActual();

        // Metodos SET
        void setPrecision(float precision);
        void setRangoMin(float rangoMin);
        void setRangoMax(float rangoMax);
        void setValorActual(float valorActual);

        // Métodos
        void MedirValor();
        void Calibrar();
        void ReportarEstado();
    };
}