#include <DHT.h>
#include <DHT_U.h>
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>

#define SENSOR 2
int TEMPERATURA;
int HUMEDAD;
char dato;

SoftwareSerial Serial_1(8,9);

#define SSpin 10
File archivo;

DHT dht(SENSOR, DHT11);

void setup() {
 Serial.begin(9600);
 Serial_1.begin(9600);
 dht.begin();
 delay(500);
     Serial_1.println("Inicializando tarjeta ...");
     delay(500);
}

void loop() {
  
  
  if(Serial_1.available()>0){
    dato=Serial_1.read();
    if(dato=='a'){
     

      if(!SD.begin(SSpin)){
       Serial_1.println("Fallo en inicializacion !");
       return;
      }
    Serial_1.println("Inicializacion correcta");
    archivo = SD.open("datos.txt", FILE_WRITE);
    
    if (archivo) {

       if (dato=='a'){
      while(1){
       
        TEMPERATURA = dht.readTemperature();
        HUMEDAD = dht.readHumidity();
         archivo.print(TEMPERATURA);
         archivo.print(",");
         archivo.println(HUMEDAD);

         Serial_1.print(TEMPERATURA);
         Serial_1.print(",");
         Serial_1.println(HUMEDAD);

         delay(1000);
         dato=Serial_1.read();
if (dato=='b'){
  archivo.close();
  Serial_1.println("Escritura correcta");
  break;
  break;
  
          }
       
      }
       }
      
      
      } else {
      Serial_1.println("Error en apertura de datos.txt");
     }

    }


  }

}
