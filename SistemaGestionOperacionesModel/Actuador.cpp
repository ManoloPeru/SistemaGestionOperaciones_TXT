#include "Actuador.h"

namespace SistemaGestionOperacionesModel {
    // Constructor vacío
    Actuador::Actuador() : Dispositivo()
    {
        this->potencia = 0.0f;
    }

    // Constructor con parámetros
    Actuador::Actuador(float potencia) : Dispositivo(idDispositivo, estado)
    {
        this->potencia = potencia;
    }

    // Métodos GET
    float Actuador::getPotencia()
    {
        return this->potencia;
    }

    // Métodos SET
    void Actuador::setPotencia(float potencia)
    {
        this->potencia = potencia;
    }

    //Metodos generales
    void Actuador::Ajustar()
    {
        Console::WriteLine("Robot {0} - valor actual ({1}).", this->getIdDispositivo(), this->getPotencia());
    }

    void Actuador::ReportarEstado() {
        Console::WriteLine("Robot {0}: Estado={1}, Potencia=({2})",
            this->getIdDispositivo(), this->getEstado() ? "Activo" : "Inactivo", potencia);
    }
}

