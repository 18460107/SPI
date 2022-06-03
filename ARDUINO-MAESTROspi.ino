#include <SoftwareSerial.h>
#define DEBUG(a) Serial.println(a);

char var;
char svar;
char data;
int x;
SoftwareSerial Serial_2(2,3);

void setup() {
  Serial.begin(9600);
  Serial_2.begin(9600);
}

void loop() {
  if(Serial.available()){
    var=Serial.read();
    
    
    if(var=='1'){
      Serial_2.print("a");
      }
    if(var=='2'){
      Serial_2.print("b");
      }
    if(var=='0'){
      }
    

}
if(Serial_2.available()){
    data = Serial_2.read();
    Serial.print(data);
}
}
