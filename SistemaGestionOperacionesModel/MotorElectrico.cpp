#pragma once
#include "MotorElectrico.h"

namespace SistemaGestionOperacionesModel {

    // Constructor vacío
    MotorElectrico::MotorElectrico() : Actuador() {
        this->velocidadRPM = 0.0f;
    }

    // Constructor con parámetros
    MotorElectrico::MotorElectrico(float velocidadRPM) : Actuador(potencia) {
        this->velocidadRPM = velocidadRPM;
    }

    // Metodos GET
    float MotorElectrico::getVelocidadRPM() {
        return this->velocidadRPM;
    }

    // Metodos SET
    void MotorElectrico::setVelocidadRPM(float velocidadRPM) {
        this->velocidadRPM = velocidadRPM;
    }

    // Métodos
    void MotorElectrico::CambiarVelocidad(float rpm) {
        this->setVelocidadRPM(rpm);
        Console::WriteLine("MotorElectrico {0} ha cambiado de velocidadRPM {1}.", this->getIdDispositivo(), this->getVelocidadRPM());
    }
}