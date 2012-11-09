package com.edad.biologica.ascach;

public class Resultados {
	  
	int edadReal; // a esto se le asigna la edad que entre
	int[] vida = new int [2];
	  
	
	  public Resultados(int x) {
			// TODO Auto-generated constructor stub
			this.edadReal = x;
			vida[0] = edadReal;
			vida[1] = 80;
		}

	public int[] decirEdadYExpectativa(){
		vida[0]=10;
		vida[1]=20;
		return vida;		
	}
	
	
	
	
	  
}
