#ifndef PISTA_H
#define PISTA_H

#include <string>
#include "Duracion.h"

// Una Pista tiene una Duracion: composición.
class Pista {
private:
    std::string titulo;
    Duracion duracion;

public:
    Pista(const std::string& titulo, int min, int seg);
    ~Pista();

    std::string getTitulo() const;
    Duracion getDuracion() const;

    void setTitulo(const std::string& nuevoTitulo);
    void mostrarInfo() const;
};

#endif
