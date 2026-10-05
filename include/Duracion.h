#ifndef DURACION_H
#define DURACION_H

class Duracion {
private:
    int minutos;
    int segundos;

public:
    Duracion(int min, int seg);
    ~Duracion();

    int getMinutos() const;
    int getSegundos() const;
    int totalSegundos() const;
    void imprimir() const;
};

#endif 
