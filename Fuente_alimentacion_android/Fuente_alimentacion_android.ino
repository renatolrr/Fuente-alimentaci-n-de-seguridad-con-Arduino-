//Fuente alimentacion android

boolean estado;
 
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  randomSeed(analogRead(0));
  estado = false;
}
 
void loop()
{
    delay(1000);
    Serial.write(random(40));
    while(Serial.available() > 0)
    {
      Serial.read();
      estado = !estado;
      digitalWrite(13, estado);
    }
}
