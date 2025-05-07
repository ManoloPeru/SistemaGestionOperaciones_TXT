#pragma once
#include "SensorProximidad.h"

namespace SistemaGestionOperacionesModel {

    // Constructor vacío
    SensorProximidad::SensorProximidad() : Sensor() {
        this->unidad = "0 cm";
    }

    // Constructor con parámetros
    SensorProximidad::SensorProximidad(String^ unidad) : Sensor(precision, rangoMin, rangoMax, valorActual) {
        this->unidad = unidad;
    }

    // Metodos GET
    String^ SensorProximidad::getUnidad() {
        return this->unidad;
    }

    // Metodos SET
    void SensorProximidad::setUnidad(String^ unidad) {
        this->unidad = unidad;
    }

    // Métodos
    void SensorProximidad::DetectarObjeto() {
        Console::WriteLine("SensorProximidad {0} tiene una cercania de: {1}.", this->getIdDispositivo(), this->getUnidad());
    }
}