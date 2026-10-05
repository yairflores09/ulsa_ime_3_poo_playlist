#include "Cancion.h"
#include <iostream>

Cancion::Cancion(const std::string& titulo, int min, int seg,
                 const std::string& artista, const std::string& genero)
    : Pista(titulo, min, seg), artista(artista), genero(genero) {
         std::cout << "Construyendo Cancion\n";
}

std::string Cancion::getArtista() const {
    return artista;
}

std::string Cancion::getGenero() const {
    return genero;
}

void Cancion::mostrar() const {
    mostrarInfo();
    std::cout << "Artista: " << artista
              << " | Genero: " << genero << '\n';
}
Cancion::~Cancion() {
    std::cout << "Destruyendo Cancion\n";
}