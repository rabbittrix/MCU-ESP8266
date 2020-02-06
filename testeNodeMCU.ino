#include <ESP8266WiFi.h>

const byte LED = 16;
boolean statusLED = LOW;

char ssid[] = "Vodafone-FAD548"; //nome da sua rede
char senha[] = "NH5k6ncEhX"; // senha da sua rede

WiFiServer server(80);  //Estancia do server e port

void setup() {

  pinMode(LED,OUTPUT);
  
  Serial.begin(115200);
  delay(10);

  connectWiFi(ssid,senha);   

  server.begin();
  Serial.println("Server starting...");

}

void loop() {
  WiFiClient client = server.available();
  if(!client){
    return;
  }

  while(!client.available()){
    delay(1);
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  if(req.indexOf("LEDon") != -1){
    digitalWrite(LED,HIGH);
    statusLED = HIGH;
  }else if(req.indexOf("LEDoff") !=-1){
    digitalWrite(LED,LOW);
    statusLED = LOW;
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<meta http-equiv='refresh' content='2'>");
  client.println("<h1>Controle de dispositivo remotamente com ESP8266</h1>");
  client.println("<h2>Ola ESP8266</h2>");

  if(!statusLED)
  client.println("<p>LED <a href=\"LEDon\"><button>DESLIGAR</button></a></p>");
  else  
  client.println("<p>LED <a href=\"LEDoff\"><button>LIGAR</button></a></p>");
  
  client.println("</html>");
  
}

void connectWiFi(char SSID[], char SENHA[]){
  Serial.print("Conectando a rede...");
  Serial.println(SSID);

  WiFi.begin(SSID, SENHA);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("Waiting...");
  }

  Serial.println(" ");
  Serial.println("WiFi Connected");
  Serial.println("Address IP: ");
  Serial.println(WiFi.localIP());
  
}
