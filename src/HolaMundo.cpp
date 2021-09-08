#include "HolaMundo.h"
// #include "Windows.h"//para usar librerias de windows
#include <chrono>//para usar librerias multiplataforma
#include <thread>//para usar librerias multiplataforma
#include<ctime>
#include<iostream>



using namespace godot;


HolaMundo::HolaMundo() 
{
    
}

HolaMundo::~HolaMundo() 
{
    
}

void HolaMundo::_init() 
{
    //asldjaskdaskdjasdjamsdasmdlñaskdñlsadkñlaskdlñaskañlskdlñaskdlñaskdñlasdñaslkdlñ
}


void HolaMundo::delay(int secs) 
{
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void HolaMundo::_ready()
{
   
    // Sleep(1000); // SOLO WINDOWS# 1000 milisegundos = 1 segundo: supuestamente detiene el flujo del código por un tiempo aqui
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));// MULTIPLATAFORMA# 1000 milisegundos = 1 segundo: supuestamente detiene el flujo del código por un tiempo aqui
    // std::this_thread::sleep_for(std::chrono::seconds(1));// MULTIPLATAFORMA# 1000 milisegundos = 1 segundo: supuestamente detiene el flujo del código por un tiempo aqui
    for (int i = 0; i < 4; i++)
    {
        Godot::print("Hola Mundo C++ GDnative");
        // delay(1);
        // Sleep(1000);
        std::this_thread::sleep_for(std::chrono::seconds(1));//detengo por un segundo
        /* code */
    }
    // Godot::print("Hola Mundo C++ GDnative");
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    // Godot::print("Hola Mundo C++ GDnative");
}

void HolaMundo::_register_methods() 
{
    register_method("_ready",&HolaMundo::_ready);//registro a ready
}





