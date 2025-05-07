#include "Experimento.h"

namespace SistemaGestionOperacionesModel {
    // Constructor vacío
    Experimento::Experimento()
    {
        this->idExperimento = 0;
        this->fechaInicio = "";
        this->duracion = 0;
        this->estado = "Inactivo";
    }

    // Constructor con parámetros
    Experimento::Experimento(int idExperimento, String^ fechaInicio, int duracion, String^ estado)
    {
        this->idExperimento = idExperimento;
        this->fechaInicio = fechaInicio;
        this->duracion = duracion;
        this->estado = estado;
    }

    // Métodos GET
    int Experimento::getIdExperimento()
    {
        return this->idExperimento;
    }

    String^ Experimento::getFechaInicio()
    {
        return this->fechaInicio;
    }

    int Experimento::getDuracion()
    {
        return this->duracion;
    }

    String^ Experimento::getEstado()
    {
        return this->estado;
    }

    // Métodos SET
    void Experimento::setIdExperimento(int idExperimento)
    {
        this->idExperimento = idExperimento;
    }

    void Experimento::setFechaInicio(String^ fechaInicio)
    {
        this->fechaInicio = fechaInicio;
    }

    void Experimento::setDuracion(int duracion)
    {
        this->duracion = duracion;
    }

    void Experimento::setEstado(String^ estado)
    {
        this->estado = estado;
    }

    void Experimento::Iniciar()
    {
        Console::WriteLine("Elexperimento se ha iniciado.");
    }

    void Experimento::Finalizar()
    {
        Console::WriteLine("El experimento ha finalizado.");
    }

    void Experimento::GenerarInforme() {
        Console::WriteLine("Procesndo informe...");
    }
}

