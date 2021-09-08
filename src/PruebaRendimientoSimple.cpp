#include "PruebaRendimientoSimple.h"
#include <OS.hpp>
#include <SceneTree.hpp>

using namespace godot;

PruebaRendimientoSimple::PruebaRendimientoSimple() 
{
    
}

PruebaRendimientoSimple::~PruebaRendimientoSimple() 
{
    
}

void PruebaRendimientoSimple::_init() 
{
    
}


void PruebaRendimientoSimple::_ready() 
{
    OS *_OS = OS::get_singleton();
    started = (double)_OS->get_system_time_msecs();

    /////////BUSCAR NODOS NO BORRAR///////////////
    cubo = get_node<MeshInstance>("cubo");
    triangulo = get_node<MeshInstance>("triangulo");
    ////////////////////////////////////////////////
    Godot::print("inicio el proceso");


    while(contador < limitador)
    {
		Prueba();
        // Godot::print("");
        contador += 1;
    }

    tiempoTranscurrido = (double)_OS->get_system_time_msecs() - started;
    double segundos = tiempoTranscurrido / 1000;
    int segundosParaMostrar = (int)segundos % 60;
    int minutosCompletos = (int)segundos / 60;
    
    Godot::print("---------------------------------------");
    Godot::print("---------------------------------------");
    Godot::print("RESULTADO C++ DE " +  String::num_int64(limitador ) + " LLAMADAS");
    Godot::print("TIEMPO COMPLETO -->  Minutos: " + String::num_int64(minutosCompletos ) + " : "  + "Segundos: " + String::num_int64(segundosParaMostrar ));
    Godot::print("Result C++ in SECONS = " + String::num_real(segundos ) );
    Godot::print("Result C++ in MILISECONS = " + String::num_real(tiempoTranscurrido ) );
    Godot::print("---------------------------------------");
    Godot::print("---------------------------------------");


    get_tree()->quit();
}

// //---------------------
// //PRUEBA HACIENDO VISIBLE Y INVISIBLE CON LOS "NODOS CARGADO EN VARIABLE"
void PruebaRendimientoSimple::Prueba() 
{
    cubo->set_visible( !cubo->is_visible() );
    triangulo->set_visible( !triangulo->is_visible() );
}
// //---------------------

// //---------------------
// //PRUEBA HACIENDO VISIBLE Y INVISIBLE "LLAMANDO NODOS"
// void PruebaRendimientoSimple::Prueba() 
// {
//     get_node<MeshInstance>("cubo")->set_visible(  !get_node<MeshInstance>("cubo")->is_visible()  );
//     get_node<MeshInstance>("triangulo")->set_visible(  !get_node<MeshInstance>("triangulo")->is_visible() );
// }
// //---------------------

// //---------------------
// //PRUEBA HACIENDO VISIBLE Y INVISIBLE "LLAMANDO NODOS CON GRUPOS"
// void PruebaRendimientoSimple::Prueba() 
// {
//     cast_to<MeshInstance>( get_tree()->get_nodes_in_group("cubo")[0] )->set_visible( !cast_to<MeshInstance>( get_tree()->get_nodes_in_group("cubo")[0] )->is_visible() );
//     cast_to<MeshInstance>( get_tree()->get_nodes_in_group("triangulo")[0] )->set_visible( !cast_to<MeshInstance>( get_tree()->get_nodes_in_group("triangulo")[0] )->is_visible() );
// }
// //---------------------




void PruebaRendimientoSimple::_register_methods() 
{
    register_method("_ready",&PruebaRendimientoSimple::_ready);
    register_method("Prueba",&PruebaRendimientoSimple::Prueba);
    register_property<PruebaRendimientoSimple,int >("limitador",&PruebaRendimientoSimple::limitador,1000000 );
}





