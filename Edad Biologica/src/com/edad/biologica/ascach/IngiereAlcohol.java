package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class IngiereAlcohol extends Activity{
		Button frec,rara;
		TextView ia;
		int [] parametro = new int[2];
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.p17);
        frec = (Button) findViewById(R.id.bResp171);
        rara = (Button) findViewById(R.id.bResp172);
        ia = (TextView) findViewById(R.id.tvDisplay16);
        frec.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Bundle b = getIntent().getExtras();
          parametro = b.getIntArray("parametro");
          parametro[0]++;
          parametro[1]--;
          Intent intento = new Intent(IngiereAlcohol.this, Felicidad.class);
    	  Bundle c = new Bundle();
    	  c.putIntArray("parametro", parametro);
    	  intento.putExtras(c); 
    	  startActivity(intento);
        
      }
    });
        rara.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Bundle b = getIntent().getExtras();
          parametro = b.getIntArray("parametro");
          parametro[0]--;
          parametro[1]++;
          Intent intento = new Intent(IngiereAlcohol.this, Felicidad.class);
    	  Bundle c = new Bundle();
    	  c.putIntArray("parametro", parametro);
    	  intento.putExtras(c); 
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

