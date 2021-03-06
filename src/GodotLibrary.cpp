//EJEMPLO de archivo para registrar las clases.
//este archivo no posee .h, es solo el .cpp
//ACA REGISTRAREMOS TODAS LAS CLASES QUE CREAMOS
// #include "HolaMundo.H"
// #include "MovimientoTest.h"
#include "HolaMundo.h"
#include "PruebaRendimientoSimple.h"
// #include "Personaje.h"

using namespace godot;//usamos el espacio de nombres godot sino tenemos varios problemas, no podra explicar mucho esto, pero asi funciona

///////////////////////////////////////////////////
// Las funciones godot_gdnative_init y godot_gdnative_terminate son llamadas
// respectivamente cuando Godot carga nuestro plugin y cuando lo descarga.
// Todo lo que que hacemos aquí es analizar a través de estas funciones
// en nuestro módulo de enlaces para inicializarlo, pero podrías tener que configurar
// más cosas dependiendo de tus necesidades. Por ahora lo dejamos asi sin tocarlo.

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	godot::Godot::gdnative_terminate(o);
}

//////////////////////////////////////////////////

//-> ESTE ES EL MAS IMPORTANTE METODO PARA REGISTRAR CLASES <- //
extern "C" void GDN_EXPORT godot_nativescript_init(void* handle)
{
	godot::Godot::nativescript_init(handle);//Precaución no borrar esto.
	
	//Registramos todas las clases que creamos aqui abajo
	register_class<HolaMundo>();
	register_class<PruebaRendimientoSimple>();
	// register_class<godot::Personaje>();
	// register_class<MovimientoTest>();
	//register_class<YOUCLASE>();//registra tu clase!
	
}