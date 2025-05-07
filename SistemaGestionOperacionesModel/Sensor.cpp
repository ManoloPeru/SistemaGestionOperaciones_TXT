#include "Sensor.h"

namespace SistemaGestionOperacionesModel {
    // Constructor vacío
    Sensor::Sensor() : Dispositivo()
    {
        this->precision = 0.0f;
        this->rangoMin = 0.0f;
        this->rangoMax = 0.0f;
        this->valorActual = 0.0f;
    }

    // Constructor con parámetros
    Sensor::Sensor(float precision, float rangoMin, float rangoMax, float valorActual) : Dispositivo(idDispositivo, estado)
    {
        this->precision = precision;
        this->rangoMin = rangoMin;
        this->rangoMax = rangoMax;
        this->valorActual = valorActual;
    }

    // Métodos GET
    float Sensor::getPrecision()
    {
        return this->precision;
    }

    float Sensor::getRangoMin()
    {
        return this->rangoMin;
    }

    float Sensor::getRangoMax()
    {
        return this->rangoMax;
    }

    float Sensor::getValorActual()
    {
        return this->valorActual;
    }

    // Métodos SET
    void Sensor::setPrecision(float precision)
    {
        this->precision = precision;
    }

    void Sensor::setRangoMin(float rangoMin)
    {
        this->rangoMin = rangoMin;
    }

    void Sensor::setRangoMax(float rangoMax)
    {
        this->rangoMax = rangoMax;
    }

    void Sensor::setValorActual(float valorActual)
    {
        this->valorActual = valorActual;
    }

    void Sensor::MedirValor()
    {
        Console::WriteLine("Robot {0} - valor actual ({1}).", this->getIdDispositivo(), this->getValorActual());
    }

    void Sensor::Calibrar()
    {
        Console::WriteLine("El Robot {0}: ha calibrado en {1}", this->getIdDispositivo(), this->getPrecision());
    }

    void Sensor::ReportarEstado() {
        Console::WriteLine("Robot {0}: Estado={1}, Posición=({2}, {3}, {4})",
            this->getIdDispositivo(), this->getEstado() ? "Activo" : "Inactivo", precision, rangoMin, rangoMax);
    }
}

