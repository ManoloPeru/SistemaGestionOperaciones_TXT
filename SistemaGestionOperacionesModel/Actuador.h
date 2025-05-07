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

        // Constructor con todos los parámetros
        Actuador(float potencia);

        // Metodos GET
        float getPotencia();
        
        // Metodos SET
        void setPotencia(float potencia);
        
        // Métodos
        void Ajustar();
        void ReportarEstado();
    };
}