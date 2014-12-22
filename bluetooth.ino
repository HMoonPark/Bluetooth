// We have program HM-11 and arduino 328P
// Kimagu 2014.12.23


#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

String inputString="";
boolean stringComplete= false;


void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.setTimeout(5000);
  
  //test if the moudele is read.
  Serial.println("HM-11 : AT+Command mode");  //change command
  delay(1000);
  if (Serial.find("Read"))
  {
    Serial.println("Module is ready");
  }
  else
  {
    Serial.println("Module have no response");
    Serial.println("Exchange to Serial Port"); 
    while(1);
  }
  delay(1000);
  
  //connect to the bluetooth(HM-11)
  boolean conneted=false;
  
  /*
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
    if( Serial.available() > 0)
    {
      input=Serial.read();
      if(input=='AT')
        {
          while(Serial.available()>0)
          {
            Serial.read();
          }
          
        }
     }
  }
  */
}
void loop() {
  // put your main code here, to run repeatedly:
  
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());

}
