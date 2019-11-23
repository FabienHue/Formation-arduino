float temp = 4.5;
String texte = " Ceci est du texte";


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Bonjour, je suis Fabien");
  Serial.print(temp);
  Serial.println(texte);
  delay(1000);
}
