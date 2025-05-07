#pragma once 
#include "Actuador.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase ValvulaNeumatica
    public ref class ValvulaNeumatica : public Actuador {
    private:
        float presion;

    public:
        // Constructor vacio
        ValvulaNeumatica();

        // Constructor con todos los parámetros
        ValvulaNeumatica(float presion);

        // Metodos GET
        float getPresion();

        // Metodos SET
        void setPresion(float presion);

        // Métodos
        void RegularPresion(float presion);
    };
}