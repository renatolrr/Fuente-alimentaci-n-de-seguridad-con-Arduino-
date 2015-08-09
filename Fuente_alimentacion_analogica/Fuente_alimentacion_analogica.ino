
//Fuente de seguridad analogica
//Renato Ramirez

#include <EEPROM.h>

int button1 = 10; // Boton de envio
int button2 = 12; // Boton de reset
int relayPin = 13;// Para activar transistor
int pot = 5; // Potenciometro de pass


void setup()
{
  pinMode(button1, INPUT); // envio como input
  pinMode(button2, INPUT); // reset como input
  pinMode(relayPin, OUTPUT);  // set pin as an output
  pinMode(pot, INPUT); // pass como input
  Serial.begin(9600); //serial 
}

void loop()
{
  // reset
  int breset;
  breset = digitalRead(button2);
  if(breset == LOW){
    int ini=0;
    EEPROM.write(1,ini);
  }
  // lectura pass
  int pass;
  pass = analogRead(pot);
  // valor del pass
  int valor;
  valor = EEPROM.read(1);
  //cambio de valor
  if (Serial.available() > 0) {   
      valor=Serial.read();
      EEPROM.write(1,valor); 
      }
  // comprobar pass
  if(button1 == LOW){
    if((pass==valor)||(valor==0)){
      digitalWrite(relayPin,HIGH);
     }
  }
} 
  




