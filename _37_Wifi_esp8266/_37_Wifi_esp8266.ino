#include <SoftwareSerial.h>

SoftwareSerial ESP8266(10, 9);
String SSID = "teacherHanul";
String PASSWORD = "teacherhanul";

unsigned long lastTimeMillis = 0;

void printResponse() {
  while (ESP8266.available()) {
    Serial.println(ESP8266.readStringUntil('\n')); 
  }
}

void connectWifi(){
  
  while(1){
    Serial.println("Wifi connecting ...");
    String cmd = "AT+CWMODE=1";
    ESP8266.println(cmd);
    cmd ="AT+CWJAP=\""+SSID+"\",\""+PASSWORD+"\"";
    ESP8266.println(cmd);
    delay(5000);
    if(ESP8266.find("OK")){
      Serial.println("Wifi connected");        
      String cmd1 = "AT+CIFSR";   // IP 주소 알아내기
      ESP8266.println(cmd1);  
      Serial.print("IP :");  
      delay(1000); 
      break;
    }
  }
  
}

void setup() {
  Serial.begin(9600);
  ESP8266.begin(9600);
  delay(2000);

  pinMode(13, OUTPUT);  //전등
  pinMode(12, OUTPUT);  //가스
  
  connectWifi();
}

void loop() {
  if (millis() - lastTimeMillis > 30000) {
    lastTimeMillis = millis();
    String ledVal = (String)digitalRead(13);
    String gasVal = (String)digitalRead(12); 

    ESP8266.println("AT+CIPMUX=1");
    delay(1000);
    printResponse();

    ESP8266.println("AT+CIPSTART=4,\"TCP\",\"192.168.0.59\",8989");
    delay(1000);
    printResponse();

    String cmd = "GET /app/arduSetLed?ledVal=" + ledVal
                + "&gasVal=" + gasVal
                + " HTTP/1.0";
    //Serial.println(cmd);
    ESP8266.println("AT+CIPSEND=4," + String(cmd.length() + 4));
    delay(1000);

    ESP8266.println(cmd);
    delay(1000);
    ESP8266.println(""); 
  }

  if (ESP8266.available()) {
    Serial.write(ESP8266.read());
  }
}
