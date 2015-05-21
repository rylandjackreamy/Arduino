#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial serialgps(2,3);

int year, Satellites;
float latitude, longitude, Altitude;
byte month, day, hour, minute, second, hundredths;
unsigned long chars, Speed, Course;
unsigned short sentences, failed_checksum;

void setup(){
  Serial.begin(115200);
  serialgps.begin(4800);
}

void GPSAll(){
  while(!serialgps.available()){}
  while(serialgps.available()){
    int c = serialgps.read(); 
    if(gps.encode(c)){
      gps.f_get_position(&latitude, &longitude);
      gps.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
      Altitude = gps.f_altitude(); 
      Course = gps.f_course(); 
      Speed = gps.f_speed_kmph();
      Satellites = gps.satellites();
      gps.stats(&chars, &sentences, &failed_checksum);
    }
  }
}

void loop(){
  while(Satellites < 1){
    GPSAll();
  }
  GPSAll();
  Serial.println(latitude);
  delay(1000);
}
