#include "Playlist.h"
#include <iostream>

Playlist::Playlist(const std::string& nombre)
    : nombre(nombre) {
}

bool Playlist::agregarCancion(Cancion* cancion) {
    if (cancion == nullptr) {
        return false;
    }

    for (Cancion* existente : canciones) {
        if (existente == cancion) {
            return false;
        }
    }

    canciones.push_back(cancion);
    return true;
}

bool Playlist::agregarPodcast(Podcast* podcast) {
    if (podcast == nullptr) {
        return false;
    }

    for (Podcast* existente : podcasts) {
        if (existente == podcast) {
            return false;
        }
    }

    podcasts.push_back(podcast);
    return true;
}

int Playlist::cantidadPistas() const {
    return static_cast<int>(canciones.size() + podcasts.size());
}

Duracion Playlist::duracionTotal() const {
    int total = 0;

    for (const Cancion* cancion : canciones) {
        total += cancion->getDuracion().totalSegundos();
    }

    for (const Podcast* podcast : podcasts) {
        total += podcast->getDuracion().totalSegundos();
    }

    return Duracion(total / 60, total % 60);
}

void Playlist::mostrar() const {
    std::cout << "\nPlaylist: " << nombre << '\n';

    for (const Cancion* cancion : canciones) {
        cancion->mostrar();
    }

    for (const Podcast* podcast : podcasts) {
        podcast->mostrar();
    }

    std::cout << "Cantidad de pistas: " << cantidadPistas() << '\n';
    std::cout << "Duracion total: ";
    duracionTotal().imprimir();
    std::cout << '\n';
}