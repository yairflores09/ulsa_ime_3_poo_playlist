#include <iostream>
#include "Playlist.h"

int main() {
        std::cout << "\n--- Experimento 1 ---\n";
    {
        Cancion prueba("Prueba", 1, 0, "Artista", "Pop");
    }
    std::cout << "--- Fin del experimento 1 ---\n\n";
    std::cout << std::boolalpha;
    std::cout << "Practica 1: Playlist de musica\n";

    // Biblioteca: las pistas existen fuera de las playlists.
    Cancion c1("The Spins", 3, 15, "Mac Miller", "Hip hop");
    Cancion c2("Love Lost", 2, 42, "Mac Miller", "Hip hop");
    Cancion c3("Timber", 3, 24, "Pitbull", "Pop");
    Podcast p1("Robotica para principiantes", 20, 30,
               "Yair", 1);

    Playlist favoritos("Favoritos");
    Playlist estudiar("Para estudiar");

    favoritos.agregarCancion(&c1);
    favoritos.agregarCancion(&c2);
    favoritos.agregarCancion(&c3);

    estudiar.agregarCancion(&c1);
    estudiar.agregarPodcast(&p1);

    favoritos.mostrar();
    estudiar.mostrar();

    // Experimento 2: destruir la playlist no destruye la cancion.
    std::cout << "\n--- Experimento 2 ---\n";
    {
        Playlist temporal("Temporal");
        temporal.agregarCancion(&c3);
        temporal.mostrar();
    }

    std::cout << "La playlist temporal ya no existe. "
              << "La cancion sigue existiendo:\n";
    c3.mostrar();

    // Experimento 3: ambas playlists apuntan a la misma cancion.
    std::cout << "\n--- Experimento 3 ---\n";
    c1.setTitulo("The Spins (titulo actualizado)");
    favoritos.mostrar();
    estudiar.mostrar();

    // Pruebas: cada comprobacion muestra OK o FALLO.
    std::cout << "\n--- Casos de prueba ---\n";
    int fallas = 0;

    auto comprobar = [&fallas](int numero, bool correcto) {
        std::cout << "Prueba " << numero << ": "
                  << (correcto ? "OK" : "FALLO") << '\n';
        if (!correcto) {
            ++fallas;
        }
    };

    // 1. Duracion normal: 3:45.
    Duracion normal(3, 45);
    comprobar(1, normal.getMinutos() == 3
                 && normal.getSegundos() == 45
                 && normal.totalSegundos() == 225);

    // 2. Normalizar 75 segundos: 1:15.
    Duracion normalizada(0, 75);
    comprobar(2, normalizada.getMinutos() == 1
                 && normalizada.getSegundos() == 15
                 && normalizada.totalSegundos() == 75);

    // 3. Valores negativos: 0:00.
    Duracion negativa(-2, 10);
    comprobar(3, negativa.getMinutos() == 0
                 && negativa.getSegundos() == 0
                 && negativa.totalSegundos() == 0);

    // 4. Titulo vacio: Sin titulo.
    Cancion sinTitulo("", 1, 0, "Artista", "Pop");
    bool tituloInicial = sinTitulo.getTitulo() == "Sin título";
    sinTitulo.setTitulo("Otro titulo");
    sinTitulo.setTitulo("");
    comprobar(4, tituloInicial
                 && sinTitulo.getTitulo() == "Sin título");

    // 5. Playlist vacia: 0 pistas y 0:00.
    Playlist vacia("Vacia");
    Duracion totalVacia = vacia.duracionTotal();
    comprobar(5, vacia.cantidadPistas() == 0
                 && totalVacia.getMinutos() == 0
                 && totalVacia.getSegundos() == 0);

    // 6. Agregar la misma cancion dos veces.
    Playlist duplicados("Duplicados");
    bool primera = duplicados.agregarCancion(&c2);
    bool segunda = duplicados.agregarCancion(&c2);
    comprobar(6, primera && !segunda
                 && duplicados.cantidadPistas() == 1);

    // 7. Rechazar un puntero nulo.
    bool aceptaNulo = duplicados.agregarCancion(nullptr);
    comprobar(7, !aceptaNulo
                 && duplicados.cantidadPistas() == 1);

    // 8. Dos canciones y un podcast:
    // 3:15 + 2:42 + 20:30 = 26:27 (1587 segundos).
    Playlist mixta("Mixta");
    mixta.agregarCancion(&c1);
    mixta.agregarCancion(&c2);
    mixta.agregarPodcast(&p1);

    Duracion totalMixto = mixta.duracionTotal();
    comprobar(8, mixta.cantidadPistas() == 3
                 && totalMixto.getMinutos() == 26
                 && totalMixto.getSegundos() == 27
                 && totalMixto.totalSegundos() == 1587);

    std::cout << "Total mixto obtenido: ";
    totalMixto.imprimir();
    std::cout << "\nPruebas fallidas: " << fallas << '\n';

    return fallas == 0 ? 0 : 1;
}