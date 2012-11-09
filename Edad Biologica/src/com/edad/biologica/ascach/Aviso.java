package com.edad.biologica.ascach;

import android.app.Activity;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Aviso extends Activity{
		Button ok;
		TextView av;
		
		
		public void onCreate(Bundle InstanciaG) {
        super.onCreate(InstanciaG);
        setContentView(R.layout.aviso);
        ok = (Button) findViewById(R.id.bAviso);
        av = (TextView) findViewById(R.id.tvDisplay24);
        ok.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
    	  //finish();
    	  System.exit(0);
        
      }
    });     
        
    
    }

}



