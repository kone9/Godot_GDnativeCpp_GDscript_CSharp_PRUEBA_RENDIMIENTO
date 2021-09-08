extends Spatial


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var started
var contador = 0
export var limitador = 1000000
var tiempoTranscurrido #representa un double de 64 bits
var cubo
var triangulo


# Called when the node enters the scene tree for the first time.
func _ready():
	started = OS.get_system_time_msecs()
	
	cubo = $cubo
	triangulo = $triangulo
	
	#cubo = get_tree().get_nodes_in_group("cubo")[0]
	#triangulo= get_tree().get_nodes_in_group("triangulo")[0]
	
	#esto es para probar el rendimiento
	while(contador < limitador):
		prueba()
		# print("")
		contador += 1
		
	tiempoTranscurrido = OS.get_system_time_msecs() - started;
	var segundos : int = tiempoTranscurrido / 1000
	var  segundosParaMostrar : float = segundos % 60
	var minutosCompletos : int  = segundos / 60
	

	# print("SELECCIONASTE: " + tipoDeSeleccion );

	print("---------------------------------------")
	print("---------------------------------------")
	print("RESULTADO GDSCRIPT DE " +  str(limitador) + " LLAMADAS");
	print("TIEMPO COMPLETO -->  Minutos: " + str( minutosCompletos) + " ; "  + "Segundos: " +str( segundosParaMostrar) );
	print("Result GDSCRIPT in SECONS = " +  str(segundosParaMostrar)  );
	print("Result GDSCRIPT in MILISECONS= " +  str(tiempoTranscurrido) );
	print("---------------------------------------")
	print("---------------------------------------")


	get_tree().quit()

	
#para probar si se hace visible/invisible
"""func _process(delta):
	if Input.is_action_just_pressed("w"):
		prueba()
		pass#"""	



# // //---------------------
# // //PRUEBA HACIENDO VISIBLE Y INVISIBLE CON LOS "NODOS CARGADO EN VARIABLE"
func prueba():
	cubo.visible = !cubo.visible
	triangulo.visible = !triangulo.visible 
# // //---------------------


# // //---------------------
# // //PRUEBA HACIENDO VISIBLE Y INVISIBLE "LLAMANDO NODOS"	
# func prueba():
# 	$cubo.visible = !$cubo.visible
# 	$triangulo.visible = !$triangulo.visible 
# // //---------------------


# // //---------------------
#// //PRUEBA HACIENDO VISIBLE Y INVISIBLE "LLAMANDO NODOS CON GRUPOS"
# func prueba():
# 	get_tree().get_nodes_in_group("cubo")[0].visible = !get_tree().get_nodes_in_group("cubo")[0].visible
# 	get_tree().get_nodes_in_group("triangulo")[0].visible = !get_tree().get_nodes_in_group("triangulo")[0].visible
# // //---------------------
