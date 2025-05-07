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

        // Constructor con todos los par�metros
        ValvulaNeumatica(float presion);

        // Metodos GET
        float getPresion();

        // Metodos SET
        void setPresion(float presion);

        // M�todos
        void RegularPresion(float presion);
    };
}