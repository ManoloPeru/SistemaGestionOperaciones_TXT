#pragma once
#include "MotorElectrico.h"

namespace SistemaGestionOperacionesModel {

    // Constructor vac�o
    MotorElectrico::MotorElectrico() : Actuador() {
        this->velocidadRPM = 0.0f;
    }

    // Constructor con par�metros
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

    // M�todos
    void MotorElectrico::CambiarVelocidad(float rpm) {
        this->setVelocidadRPM(rpm);
        Console::WriteLine("MotorElectrico {0} ha cambiado de velocidadRPM {1}.", this->getIdDispositivo(), this->getVelocidadRPM());
    }
}