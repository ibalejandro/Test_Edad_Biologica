package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Expectativa extends Activity{
		Button ok;
		TextView e;
		int [] parametro = new int[2];
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.expectativa);
        ok = (Button) findViewById(R.id.bExpectativa);
        e = (TextView) findViewById(R.id.tvDisplay21);
        Bundle b = getIntent().getExtras();
        parametro = b.getIntArray("parametro");
        e.setText("Su Expectativa de Vida es " + parametro[1] + " años");
        ok.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Intent intento = new Intent(Expectativa.this, Continuar.class);
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


