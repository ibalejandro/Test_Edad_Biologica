package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Result extends Activity{
		int counter;
		Button ok;
		TextView r;
		
		public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.resultado);
        counter = 0;
        ok = (Button) findViewById(R.id.bResultado);
        r = (TextView) findViewById(R.id.tvDisplay20);
        ok.setOnClickListener(new View.OnClickListener() {
      
      public void onClick(View v) {
        // TODO Auto-generated method stub
        counter++;
        	try{
    		Class ourClass = Class.forName("com.edad.biologica.ascach.Expectativa");
    		Intent ourIntent = new Intent(Result.this, ourClass);
    		startActivity(ourIntent);
    		}catch(ClassNotFoundException e){
    			e.printStackTrace();
    		}
        
      }
    });     
        
    
    }

}

