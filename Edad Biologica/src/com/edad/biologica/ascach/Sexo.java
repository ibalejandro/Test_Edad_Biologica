package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Sexo extends Activity{
		Button masc,fem;
		TextView sexo; 
		int [] parametro = new int[2];
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.p2);
        masc = (Button) findViewById(R.id.bResp21);
        fem = (Button) findViewById(R.id.bResp22);
        sexo = (TextView) findViewById(R.id.tvDisplay1);
        masc.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
        Bundle b = getIntent().getExtras();
        parametro = b.getIntArray("parametro");
        parametro[0]++;
        parametro[1]--;
    	Intent intento = new Intent(Sexo.this, ReaccionViolenta.class);
		Bundle c = new Bundle();
		c.putIntArray("parametro", parametro);
		intento.putExtras(c); 
		startActivity(intento);

      }
    });
        fem.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	Bundle b = getIntent().getExtras();
        parametro = b.getIntArray("parametro");
        parametro[0]--;
        parametro[1]++;
      	Intent intento = new Intent(Sexo.this, ReaccionViolenta.class);
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
