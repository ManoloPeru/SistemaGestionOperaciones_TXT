#include "EstacionControl.h"

namespace SistemaGestionOperacionesModel {
    // Constructor vacío
    EstacionControl::EstacionControl()
    {
        this->idEstacion = 0;
        this->estado = "";
        this->listaDispositivo = gcnew List<Dispositivo^>();
        this->experimento = gcnew Experimento();
    }

    // Constructor con parámetros
    EstacionControl::EstacionControl(int idEstacion, String^ estado, List<Dispositivo^>^ listaDispositivo, Experimento^ experimento)
    {
        this->idEstacion = idEstacion;
        this->estado = estado;
        this->listaDispositivo = listaDispositivo;
        this->experimento = experimento;
    }

    // Métodos GET
    int EstacionControl::getIdEstacion()
    {
        return this->idEstacion;
    }

    String^ EstacionControl::getEstado()
    {
        return this->estado;
    }

    List<Dispositivo^>^ EstacionControl::getListaDispositivo()
    {
        return this->listaDispositivo;
    }

    Experimento^ EstacionControl::getExperimento()
    {
        return this->experimento;
    }

    // Métodos SET
    void EstacionControl::setIdEstacion(int idEstacion)
    {
        this->idEstacion = idEstacion;
    }

    void EstacionControl::setEstado(String^ estado)
    {
        this->estado = estado;
    }

    void EstacionControl::setListaDispositivo(List<Dispositivo^>^ listaDispositivo)
    {
        this->listaDispositivo = listaDispositivo;
    }

    void EstacionControl::setExperimento(Experimento^ experimento)
    {
        this->experimento = experimento;
    }

    //Metodos generales
    void EstacionControl::IniciarExerimento()
    {
        throw gcnew System::NotImplementedException();
    }

    void EstacionControl::DetenerExerimento()
    {
        throw gcnew System::NotImplementedException();
    }

    void EstacionControl::AgregarDispositivo()
    {
        throw gcnew System::NotImplementedException();
    }

    void EstacionControl::AsignarTarea()
    {
        throw gcnew System::NotImplementedException();
    }

    void EstacionControl::MonitorearDispositivo()
    {
        throw gcnew System::NotImplementedException();
    }

}


