#include "Actuador.h"

namespace SistemaGestionOperacionesModel {
    // Constructor vac�o
    Actuador::Actuador() : Dispositivo()
    {
        this->potencia = 0.0f;
    }

    // Constructor con par�metros
    Actuador::Actuador(float potencia) : Dispositivo(idDispositivo, estado)
    {
        this->potencia = potencia;
    }

    // M�todos GET
    float Actuador::getPotencia()
    {
        return this->potencia;
    }

    // M�todos SET
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

