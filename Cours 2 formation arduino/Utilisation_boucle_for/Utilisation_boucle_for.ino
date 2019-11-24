int led = 11;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  for (int i = 0; i <= 255; i++) { //On part de i = 0 ; on continu temps que i <=255; on ajoute 1 ; i++ -> i = i+1
    analogWrite(led, i);
    Serial.println(i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(led, i);
    Serial.println(i);
    delay(10);
  }
}
