// Godot engine C++ Gdnative Estructura de un archivo
#ifndef PRUEBARENDIMIENTOSIMPLE_H//nose si sea necesario, pero esto lo saque de los ejemplos lo dejo por las dudas, asi funciona
#define PRUEBARENDIMIENTOSIMPLE_H//nose si sea necesario, pero esto lo saque de los ejemplos lo dejo por las dudas, asi funciona

#pragma once//importante siempre incluir esta linea

//importamos las librerias que necesitamos
#include <Godot.hpp>
#include <Spatial.hpp>
#include <MeshInstance.hpp>

//siempre usamos el nameSpace para que sea identificada la clase por todo el proyecto
namespace godot {
	class PruebaRendimientoSimple : public Spatial {
        // Respetar que el macro tenga el acceso privado
        private:
            GODOT_CLASS(PruebaRendimientoSimple, Spatial)  

        public:
            //metodo contructor, ojo no se llama directo, usar init()
            PruebaRendimientoSimple();
            //metodo destructor, ni idea como funciona en godot, pero lo declaramos por las dudas aunque no lo usemos
            ~PruebaRendimientoSimple();
            //metodo inicial siempre hay que declararlo
            void _init();

            void _ready();

           //Para hacer la magia de usar Godot Engine con C++ y Gdnative hay que registrar metodos y propiedades con este metodo... //IMPORTANTE tenemos que registrar los metodos sino godot no los detecta, a veces al registrar las propiedades para que se vean en el editor no se cargan, si pasa eso, reinicia el editor
            static void _register_methods();

        private:
            //para crear un delay pero no funciona cuando el juego se ejecuta
            double started;
            int contador = 0;
            int limitador = 1000000;//variable exportada al editor registrada como propiedad
            double tiempoTranscurrido; //#representa un double de 64 bits
            MeshInstance *cubo;
            MeshInstance *triangulo;

        private:
            void Prueba();
        
	};
}

#endif