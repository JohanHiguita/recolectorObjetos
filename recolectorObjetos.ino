  /*
   * Autor: Johan Esteban Higuita
   * e-mail: higuitajohan@gmail.com
   * GitHub user: JohanHiguita
   * Pygmalion.tech
   * 
   * Descripción: Reto recolector objetos minicompetencias UVA 2018
   */
   
  int interseccion = 0;
  int compare = 700;

void setup () {
  motorSpeed(M1,65);
  motorSpeed(M2,65);

}
void loop () {
  if (ultrasoundRead(J3) < 13 && ultrasoundRead(J3) > 2) {
    sacarBotella ();
  } else {
    seguidorLinea ();
  }

}
void seguidorLinea (){
  if (sensorRead(J1) < compare && sensorRead(J2) < compare) {
    goForward(M1,M2);
  } else if (sensorRead(J1) > compare && sensorRead(J2) < compare) {
    turnRight(M2 , M1);
  } else if (sensorRead(J1) < compare && sensorRead(J2) > compare) {
    turnLeft(M2 , M1);
  } else if (sensorRead(J1) > compare && sensorRead(J2) > compare) {
    interseccion += 1;
    while (sensorRead(J1) > compare && sensorRead(J2) > compare) {
      goForward(M1,M2);
    }
    delay(100);
    if (interseccion == 1) {
      izq ();
    } else if (interseccion == 5) {
      der ();
    }
  }

}
void izq (){
  while (sensorRead(J2) < compare) {
    turnLeft(M2 , M1);
    delay(50);
  }
  while (sensorRead(J2) > compare) {
    turnLeft(M2 , M1);
    delay(10);
  }

}
void der (){
  while (sensorRead(J1) < compare) {
    turnRight(M2 , M1);
    delay(50);
  }
  while (sensorRead(J1) > compare) {
    turnRight(M2 , M1);
    delay(10);
  }

}
void sacarBotella (){
  motorsOff(M1 , M2);
  cerrarPinzas ();
  if (interseccion == 1 || interseccion == 2 || interseccion == 4) {
    sacarAdelante ();
  } else if (interseccion == 7 || interseccion == 8) {
    sacarAtras ();
  }

}
void cerrarPinzas (){
  motorOn(M3,REVERSE);
  delay(500);
  motorOff(M3);

}
void abrirPinzas (){
  motorOn(M3,FORWARD);
  delay(500);
  motorOff(M3);

}
void sacarAdelante (){
  goForward(M1,M2);
  delay(700);
  motorsOff(M1 , M2);
  abrirPinzas ();
  goReverse(M1,M2);
  delay(760);

}
void sacarAtras (){
  goReverse(M1,M2);
  delay(1500);
  motorsOff(M1 , M2);
  delay(100000000);

}
