#pragma once 
#include "Dispositivo.h"
#include "Experimento.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String
    using namespace System::Collections::Generic; // Para usar List en C++/CLI

    // Declaracion de la clase EstacionControl
    public ref class EstacionControl {
    private:
        int idEstacion;
        String^ estado;
        List<Dispositivo^>^ listaDispositivo;
        Experimento^ experimento;

    public:
        // Constructor vacio
        EstacionControl();

        // Constructor con todos los parámetros
        EstacionControl(int idEstacion, String^ estado, List<Dispositivo^>^ listaDispositivo, Experimento^ experimento);

        // Metodos GET
        int getIdEstacion();
        String^ getEstado();
        List<Dispositivo^>^ getListaDispositivo();
        Experimento^ getExperimento();

        // Metodos SET
        void setIdEstacion(int idEstacion);
        void setEstado(String^ estado);
        void setListaDispositivo(List<Dispositivo^>^ listaDispositivo);
        void setExperimento(Experimento^ experimento);

        //Metodos generales
        void IniciarExerimento();
        void DetenerExerimento();
        void AgregarDispositivo();
        void AsignarTarea();
        void MonitorearDispositivo();
    };
}
