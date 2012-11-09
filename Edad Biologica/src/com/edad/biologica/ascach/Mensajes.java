package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Mensajes extends Activity{
		Button ok;
		TextView m;
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.mensaje);
        ok = (Button) findViewById(R.id.bMensaje);
        m = (TextView) findViewById(R.id.tvDisplay23);
        ok.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Intent intento = new Intent(Mensajes.this, Aviso.class);
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


