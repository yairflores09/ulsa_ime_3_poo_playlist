#ifndef CANCION_H
#define CANCION_H

#include <string>
#include "Pista.h"

// Una Cancion es una Pista: herencia.
class Cancion : public Pista {
private:
    std::string artista;
    std::string genero;

public:
    Cancion(const std::string& titulo, int min, int seg,
            const std::string& artista, const std::string& genero);
            ~Cancion();

    std::string getArtista() const;
    std::string getGenero() const;
    void mostrar() const;
};

#endif