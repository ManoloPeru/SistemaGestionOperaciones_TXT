#pragma once
#include "ValvulaNeumatica.h"

namespace SistemaGestionOperacionesModel {

    // Constructor vac�o
    ValvulaNeumatica::ValvulaNeumatica() : Actuador() {
        this->presion = 0.0f;
    }

    // Constructor con par�metros
    ValvulaNeumatica::ValvulaNeumatica(float presion) : Actuador(potencia) {
        this->presion = presion;
    }

    // Metodos GET
    float ValvulaNeumatica::getPresion() {
        return this->presion;
    }

    // Metodos SET
    void ValvulaNeumatica::setPresion(float presion) {
        this->presion = presion;
    }

    // M�todos
    void ValvulaNeumatica::RegularPresion(float presion) {
        this->setPresion(presion);
        Console::WriteLine("ValvulaNeumatica {0} ha cambiado de presion {1}.", this->getIdDispositivo(), this->getPresion());
    }
}