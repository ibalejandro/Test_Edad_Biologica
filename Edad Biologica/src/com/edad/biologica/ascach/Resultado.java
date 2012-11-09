package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Resultado extends Activity{
		Button ok;
		TextView r;
		int [] parametro = new int[2];
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.resultado);
        ok = (Button) findViewById(R.id.bResultado);
        r = (TextView) findViewById(R.id.tvDisplay20);
        Bundle b = getIntent().getExtras();
        parametro = b.getIntArray("parametro");
        r.setText("Su Edad Biologica es " + Math.abs(parametro[0])  + " años");
        ok.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  Intent intento = new Intent(Resultado.this, Expectativa.class);
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
