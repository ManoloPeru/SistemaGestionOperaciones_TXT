#pragma once

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase Dispositivo
    public ref class Dispositivo {
    protected:
        int idDispositivo;
        String^ estado;
    
    public:
        // Constructor vacio
        Dispositivo();

        // Constructor con todos los par�metros
        Dispositivo(int idDispositivo, String^ estado);

        // Metodos GET
        int getIdDispositivo();
        String^ getEstado();

        // Metodos SET
        void setIdDispositivo(int id);
        void setEstado(String^ estado);


        // M�todos
        void Activar();
        void Desactivar();
    };
}