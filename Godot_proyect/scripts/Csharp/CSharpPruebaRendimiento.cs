using Godot;
using System;

public class CSharpPruebaRendimiento : Spatial
{
    private MeshInstance cubo;
    private MeshInstance triangulo;
    private ulong started;
    private int contador = 0;
    
    [Export]
    private int limitador = 1000000;
    private ulong tiempoTranscurrido;
    
    /// Called when the node enters the scene tree for the first time.
    public override void _Ready()
    {
        started = OS.GetSystemTimeMsecs();
        cubo = GetNode<MeshInstance>("cubo");
        triangulo = GetNode<MeshInstance>("triangulo");
        
        //cubo = (GetTree().GetNodesInGroup("cubo")[0]as MeshInstance);
        //triangulo = (GetTree().GetNodesInGroup("triangulo")[0]as MeshInstance);
        
        //#esto es para probar el rendimiento
        while (contador < limitador)
        { 
            prueba();
        }
        tiempoTranscurrido = OS.GetSystemTimeMsecs() - started;
        tiempoTranscurrido = (ulong)OS.GetSystemTimeMsecs() - started;
        float segundos = tiempoTranscurrido / 1000;
        float segundosParaMostrar = (int)segundos % 60;
        int minutosCompletos = (int)segundos / 60;
        

        GD.Print("---------------------------------------");
        GD.Print("---------------------------------------");
        GD.Print("RESULTADO C# DE " +  limitador.ToString() + " LLAMADAS");
        GD.Print("TIEMPO COMPLETO -->  Minutos: " + minutosCompletos.ToString() + " : "  + "Segundos: " + segundosParaMostrar.ToString() );
        GD.Print("Result C# in SECONS = " + segundos.ToString() );
        GD.Print("Result C# in MILISECONS = " + tiempoTranscurrido.ToString() );
        GD.Print("---------------------------------------");
        GD.Print("---------------------------------------");


        // GD.Print("Result C#: ", tiempoTranscurrido);
        GetTree().Quit();//*/
       
    }

    //Probar desde teclado si se hace visible/invisible
    /*public override void _Process(float delta){
        if(Input.IsActionJustPressed("w")){
            prueba();
        }
    }//*/


    // //---------------------
    // //PRUEBA HACIENDO VISIBLE Y INVISIBLE CON LOS "NODOS CARGADO EN VARIABLE"
    private void prueba()
    {
        cubo.Visible = !cubo.Visible;
        triangulo.Visible = !triangulo.Visible;
        contador++;
    }
    // //---------------------

    // //PRUEBA HACIENDO VISIBLE Y INVISIBLE "LLAMANDO NODOS"
    // private void prueba()
    // {
    //     GetNode<MeshInstance>("cubo").Visible = !GetNode<MeshInstance>("cubo").Visible;
    //     GetNode<MeshInstance>("triangulo").Visible =  !GetNode<MeshInstance>("triangulo").Visible;
    //     contador++;
    // }
    // //---------------------

    // //---------------------
    // //PRUEBA HACIENDO VISIBLE Y INVISIBLE "LLAMANDO NODOS CON GRUPOS"
    //en esta funcion uso los grupos para hacerlos visible/invisible
    // private void prueba()
    // {
    //     (GetTree().GetNodesInGroup("cubo")[0]as MeshInstance).Visible = !(GetTree().GetNodesInGroup("cubo")[0]as MeshInstance).Visible;
    //     (GetTree().GetNodesInGroup("triangulo")[0]as MeshInstance).Visible =  !(GetTree().GetNodesInGroup("triangulo")[0]as MeshInstance).Visible;
    //     contador++;
    // }
    // //---------------------

}
