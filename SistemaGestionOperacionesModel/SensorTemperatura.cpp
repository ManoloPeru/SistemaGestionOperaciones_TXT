#pragma once
#include "SensorTemperatura.h"

namespace SistemaGestionOperacionesModel {

    // Constructor vac�o
    SensorTemperatura::SensorTemperatura() : Sensor() {
        this->unidad = "0 �C";
    }

    // Constructor con par�metros
    SensorTemperatura::SensorTemperatura(String^ unidad) : Sensor(precision, rangoMin, rangoMax, valorActual) {
        this->unidad = unidad;
    }

    // Metodos GET
    String^ SensorTemperatura::getUnidad() {
        return this->unidad;
    }

    // Metodos SET
    void SensorTemperatura::setUnidad(String^ unidad) {
        this->unidad = unidad;
    }

    // M�todos
    void SensorTemperatura::ReportarTemperatura() {
        Console::WriteLine("SensorTemperatura {0} tiene una temperatura de: {1}.", this->getIdDispositivo(), this->getUnidad());
    }
}
