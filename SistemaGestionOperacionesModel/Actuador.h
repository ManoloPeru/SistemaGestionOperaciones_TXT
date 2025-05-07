#pragma once
#include "Dispositivo.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase Actuador
    public ref class Actuador : public Dispositivo {
    protected:
        float potencia;

    public:
        // Constructor vacio
        Actuador();

        // Constructor con todos los par�metros
        Actuador(float potencia);

        // Metodos GET
        float getPotencia();
        
        // Metodos SET
        void setPotencia(float potencia);
        
        // M�todos
        void Ajustar();
        void ReportarEstado();
    };
}