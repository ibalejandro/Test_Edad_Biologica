package com.edad.biologica.ascach;

import android.app.Activity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Pesimista extends Activity{
		Button si,no;
		TextView p;
		int [] parametro = new int[2];
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.p4);
        no = (Button) findViewById(R.id.bResp41);
        si = (Button) findViewById(R.id.bResp42);
        p = (TextView) findViewById(R.id.tvDisplay3);
        si.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Bundle b = getIntent().getExtras();
          parametro = b.getIntArray("parametro");
          parametro[0]++;
          parametro[1]--;
          Intent intento = new Intent(Pesimista.this, VariasCosas.class);
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
          parametro[0]--;
          parametro[1]++;
          Intent intento = new Intent(Pesimista.this, VariasCosas.class);
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
