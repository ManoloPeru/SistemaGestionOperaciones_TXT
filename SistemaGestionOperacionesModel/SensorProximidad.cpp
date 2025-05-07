#pragma once
#include "SensorProximidad.h"

namespace SistemaGestionOperacionesModel {

    // Constructor vac�o
    SensorProximidad::SensorProximidad() : Sensor() {
        this->unidad = "0 cm";
    }

    // Constructor con par�metros
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

    // M�todos
    void SensorProximidad::DetectarObjeto() {
        Console::WriteLine("SensorProximidad {0} tiene una cercania de: {1}.", this->getIdDispositivo(), this->getUnidad());
    }
}