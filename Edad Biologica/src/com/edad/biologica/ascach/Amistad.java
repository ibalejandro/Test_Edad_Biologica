package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Amistad extends Activity{
		Button si,no;
		TextView a;
		int [] parametro = new int[2];
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.p20);
        no = (Button) findViewById(R.id.bResp201);
        si = (Button) findViewById(R.id.bResp202);
        a = (TextView) findViewById(R.id.tvDisplay19);
        si.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Bundle b = getIntent().getExtras();
          parametro = b.getIntArray("parametro");
          parametro[0]--;
          parametro[1]++;
          Intent intento = new Intent(Amistad.this, Resultado.class);
    	  Bundle c = new Bundle();
    	  c.putIntArray("parametro", parametro);
    	  intento.putExtras(c); 
    	  startActivity(intento);
        
      }
    });
        no.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Bundle b = getIntent().getExtras();
          parametro = b.getIntArray("parametro");
          parametro[0]++;
          parametro[1]--;
          Intent intento = new Intent(Amistad.this, Resultado.class);
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
