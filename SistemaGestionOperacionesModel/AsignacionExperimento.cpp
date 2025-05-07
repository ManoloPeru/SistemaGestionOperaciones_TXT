#include "AsignacionExperimento.h"

namespace SistemaGestionOperacionesModel {
    // Constructor vacío
    AsignacionExperimento::AsignacionExperimento() 
    {
        this->idAsignacion = 0;
        this->fechaAsignacion = "";
        this->rol = "";
        this->dispositivo = gcnew Dispositivo();
        this->experimento = gcnew Experimento();
    }

    // Constructor con parámetros
    AsignacionExperimento::AsignacionExperimento(int idAsignacion, String^ fechaAsignacion, String^ rol, Dispositivo^ dispositivo, Experimento^ experimento)
    {
        this->idAsignacion = idAsignacion;
        this->fechaAsignacion = fechaAsignacion;
        this->rol = rol;
        this->dispositivo = dispositivo;
        this->experimento = experimento;
    }

    // Métodos GET
    int AsignacionExperimento::getIdAsignacion()
    {
        return this->idAsignacion;
    }

    String^ AsignacionExperimento::getFechaAsignacion()
    {
        return this->fechaAsignacion;
    }

    String^ AsignacionExperimento::getRol()
    {
        return this->rol;
    }

    Dispositivo^ AsignacionExperimento::getDispositivo()
    {
        return this->dispositivo;
    }

    Experimento^ AsignacionExperimento::getExperimento()
    {
        return this->experimento;
    }

    // Métodos SET
    void AsignacionExperimento::setIdAsignacion(int idAsignacion)
    {
        this->idAsignacion = idAsignacion;
    }

    void AsignacionExperimento::setFechaAsignacion(String^ fechaAsignacion)
    {
        this->fechaAsignacion = fechaAsignacion;
    }

    void AsignacionExperimento::setRol(String^ rol)
    {
        this->rol = rol;
    }

    void AsignacionExperimento::setDispositivo(Dispositivo^ dispositivo)
    {
        this->dispositivo = dispositivo;
    }

    void AsignacionExperimento::setExperimento(Experimento^ experimento)
    {
        this->experimento = experimento;
    }

}

