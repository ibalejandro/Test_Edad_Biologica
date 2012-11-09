package com.edad.biologica.ascach;

import android.app.Activity;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;

public class CalculadorEdad extends Activity {
  MediaPlayer cancion;
  @Override
  
  protected void onCreate(Bundle InstanciaG) {
    // TODO Auto-generated method stub
    super.onCreate(InstanciaG);
    setContentView(R.layout.splash);
    cancion = MediaPlayer.create(CalculadorEdad.this, R.raw.splash_sound);
    cancion.start();
    Thread timer = new Thread(){
      public void run(){
        try{
          sleep(9000);
        }catch(InterruptedException e){
          e.printStackTrace();
        }finally{
          Intent abrirTest_Edad_Biologica = new Intent("com.edad.biologica.ascach.TEST_EDAD_BIOLOGICA");
          startActivity(abrirTest_Edad_Biologica);                                
        }
      }
      
    };
    timer.start();
  }

  @Override
  protected void onPause() {
    // TODO Auto-generated method stub
    super.onPause();
    cancion.release();  //esto es para parar la canción.
    finish();
  }

}