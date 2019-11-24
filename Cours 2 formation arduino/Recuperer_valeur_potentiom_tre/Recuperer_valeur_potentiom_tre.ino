int led = 11;
int pot = A0;
int valeur;
int PWM;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  valeur = analogRead(pot);
  PWM = map(valeur, 0, 1024, 0, 255);

  analogWrite(led,PWM);
  Serial.println(valeur);
}
