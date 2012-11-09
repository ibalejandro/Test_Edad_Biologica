package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class VisitaMedico extends Activity{
		Button frec,rara;
		TextView vm;
		int [] parametro = new int[2];
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.p14);
        rara = (Button) findViewById(R.id.bResp141);
        frec = (Button) findViewById(R.id.bResp142);
        vm = (TextView) findViewById(R.id.tvDisplay13);
        frec.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Bundle b = getIntent().getExtras();
          parametro = b.getIntArray("parametro");
          parametro[0]--;
          parametro[1]++;
          Intent intento = new Intent(VisitaMedico.this, Dieta.class);
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
          parametro[0]++;
          parametro[1]--;
          Intent intento = new Intent(VisitaMedico.this, Dieta.class);
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
