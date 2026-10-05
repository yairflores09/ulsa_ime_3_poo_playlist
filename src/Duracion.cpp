#include "Duracion.h"
#include <iostream>

Duracion::Duracion(int min, int seg)
    : minutos(min), segundos(seg) {
        std::cout << "Construyendo Duracion\n";
    if (min < 0 || seg < 0) {
        minutos = 0;
        segundos = 0;
    } else {
        minutos = min + seg / 60;
        segundos = seg % 60;
    }
}

int Duracion::getMinutos() const {
    return minutos;
}

int Duracion::getSegundos() const {
    return segundos;
}

int Duracion::totalSegundos() const {
    return minutos * 60 + segundos;
}

void Duracion::imprimir() const {
    std::cout << minutos << ":";
    if (segundos < 10) {
        std::cout << "0";
    }
    std::cout << segundos;
}
Duracion::~Duracion() {
    std::cout << "Destruyendo Duracion\n";
}