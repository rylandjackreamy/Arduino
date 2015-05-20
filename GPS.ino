
#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial serialgps(2,3);

unsigned long chars;
unsigned short sentences, failed_checksum;

void setup(){
  serialgps.begin(4800);
}

String posit(){
  float latitude, longitude;
  gps.f_get_position(&latitude, &longitude);
  return (String(latitude) + ", " + String(longitude))
}

String time(){
  int year;
  byte month, day, hour, minute, second, hundredths;
  gps.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
  return (String(hour) + ":" + String(minute) + ":" + String(second) + "." + String(hundredths))
}

String GPS(char task){ 
  while (serialgps.available()){}
  int c = serialgps.read(); 
  if (gps.encode(c)){
    if (task == 't'){ // t for time
      ret = time()
    } else if (task == 'p'){ // p for position
      ret = posit()
    } else if (task == 'a'){ // a for altitude
      ret = gps.f_altitude()
    } else if (task == 'c'){ // c for course
      ret = gps.f_course()
    } else if (task == 's'){ // s for speed
      ret = gps.f_speed_mph()
    } else if (task == 'n'){ // n for number of satelites
      ret = gps.satellites()
    }
    gps.stats(&chars, &sentences, &failed_checksum);
  }
}

void loop(){
}
