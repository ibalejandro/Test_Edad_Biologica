package com.edad.biologica.ascach;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.text.InputType;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class Test_Edad_Biologica extends Activity {
  
  String sexo = "";

  Button seguir;
  EditText ingreso;
  TextView display0;
  int respuestas[] = new int [2]; 
  
   
    @Override
    public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.edadcr);
        ingreso = (EditText)findViewById(R.id.etComando);
        seguir = (Button) findViewById(R.id.bEdad);
        display0 = (TextView)findViewById(R.id.tvInvalido);
        ingreso.setInputType(InputType.TYPE_CLASS_TEXT);  
        seguir.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				// TODO Auto-generated method stub
				String check = ingreso.getText().toString();
				display0.setText(check);
				if(esNumero(check) && check!=null && !check.equals("")){
					int x = Integer.parseInt(check);
					if(esEdadValida(x)){
						display0.setText("Edad Válida");
						display0.setTextColor(Color.GREEN);
						respuestas[0] = x;
						respuestas[1] = 80;
						Intent intento = new Intent(Test_Edad_Biologica.this, Sexo.class);
						Bundle b = new Bundle();
						b.putIntArray("parametro", respuestas); //ESTE ES EL PARAMETRO
						intento.putExtras(b); //Pasa el parámetro.
						startActivity(intento);
						
					}
					else{
						display0.setText("Edad Inválida.       Ingrese una edad Válida y presione CONTINUAR.");
						display0.setTextColor(Color.RED);
					}
				}
				else{
					display0.setText("Edad Inválida.           Ingrese una edad Válida y presione CONTINUAR.");
					display0.setTextColor(Color.RED);
					
				}
			}
			
		});
    }
    
    

    public boolean esNumero(String x){
        for(int i=0;i<x.length();i++){
            if(!(x.charAt(i) <= '9' && x.charAt(i)>='0')){
                return false;
            }
        }
        return true;
  }
    public boolean esEdadValida(int x){
        if(x <=80 && x>=1){
            return true;
        }
        else{
            return false;
       }
}  
           
       
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_test__edad__biologica, menu);
        
        return true;
        
    }
    
    @Override
	  protected void onPause() {
	    // TODO Auto-generated method stub
	    super.onPause();
	    finish();
	  }
}