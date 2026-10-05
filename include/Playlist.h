#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>

#include "Cancion.h"
#include "Duracion.h"
#include "Podcast.h"

// La Playlist usa pistas existentes: agregación.
class Playlist {
private:
    std::string nombre;
    std::vector<Cancion*> canciones;
    std::vector<Podcast*> podcasts;

public:
    Playlist(const std::string& nombre);

    bool agregarCancion(Cancion* cancion);
    bool agregarPodcast(Podcast* podcast);

    int cantidadPistas() const;
    Duracion duracionTotal() const;
    void mostrar() const;
};

#endif