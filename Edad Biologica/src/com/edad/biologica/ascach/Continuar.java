package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Continuar extends Activity{
		Button volver,salir;
		TextView con;
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.continuar);
        volver = (Button) findViewById(R.id.bContinuar2);
        salir = (Button) findViewById(R.id.bContinuar1);
        con = (TextView) findViewById(R.id.tvDisplay22);
        volver.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Intent intento = new Intent(Continuar.this, Test_Edad_Biologica.class);
    	  startActivity(intento);
        
      }
    });
        salir.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Intent intento = new Intent(Continuar.this, Mensajes.class);
    	  startActivity(intento);
      }
    });
        
        
    
    }
		@Override
		  protected void onPause() {
		    // TODO Auto-generated method stub
		    super.onPause();
		    finish();
		  }
}

