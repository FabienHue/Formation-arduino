int led = 11;

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  analogWrite(led,150);
}
