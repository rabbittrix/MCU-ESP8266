const byte LED = 2;
const byte LED_1 = 16;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  pinMode(LED_1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED, LOW); //liga Led
  digitalWrite(LED_1, LOW);
  delay(1000);            //espera 1 segundo
  digitalWrite(LED, HIGH);//apaga Led
  digitalWrite(LED_1, HIGH);
  delay(1000);            //espera 1 segundo


}
