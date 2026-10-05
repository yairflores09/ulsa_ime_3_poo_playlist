#include "Podcast.h"
#include <iostream>

Podcast::Podcast(const std::string& titulo, int min, int seg,
                 const std::string& anfitrion, int numeroEpisodio)
    : Pista(titulo, min, seg),
      anfitrion(anfitrion),
      numeroEpisodio(numeroEpisodio) {
}

std::string Podcast::getAnfitrion() const {
    return anfitrion;
}

int Podcast::getNumeroEpisodio() const {
    return numeroEpisodio;
}

void Podcast::mostrar() const {
    mostrarInfo();
    std::cout << "Anfitrion: " << anfitrion
              << " | Episodio: " << numeroEpisodio << '\n';
}