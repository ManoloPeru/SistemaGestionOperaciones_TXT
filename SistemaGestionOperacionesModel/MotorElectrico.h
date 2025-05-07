#pragma once
#include "Actuador.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase MotorElectrico
    public ref class MotorElectrico : public Actuador {
    private:
        float velocidadRPM;

    public:
        // Constructor vacio
        MotorElectrico();

        // Constructor con todos los parámetros
        MotorElectrico(float velocidadRPM);

        // Metodos GET
        float getVelocidadRPM();

        // Metodos SET
        void setVelocidadRPM(float velocidadRPM);

        // Métodos
        void CambiarVelocidad(float rpm);
    };
}