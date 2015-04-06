
/* coded by:
  Brian
  Timmy
  Jack
*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

boolean pinon;

void pin(){
  delay(100);
  pinon = !pinon;
  digitalWrite(13, pinon);
}

String readd() {
  while(Serial.available() <= 0){}
  String in = Serial.readString();
  Serial.println(in);
  return in;
}

String diff(String input) {
  int i = 0, j;
  String ret = "";
  int place = 0;
  char lastchar = 'y';
  String working = "", coefficient, power, ending = "", last = "";
  working += input.charAt(i);
  pin();
  do {
    i ++;
    coefficient = "";
    power = "";
    if (lastchar == '^' || input.charAt(i) != '+' && input.charAt(i) != '-' && i < input.length()){
      working += input.charAt(i);
      lastchar = input.charAt(i);
      pin();
    } else {
      j = 0;
      coefficient = "";
      power = "";
      if (working.charAt(j) == 'x'){
        coefficient = "1";
        pin();
      }
      while(working.charAt(j) != 'x' && j < working.length()) {
        coefficient += working.charAt(j);
        j++;
      }
      if (working.charAt(j) == 'x'){
        float coef = coefficient.toFloat();
        if (last == "-"){
          coef *= -1;
          last == "";
          pin();
        }        
        if (working.charAt(j + 1) == '^') {
          j += 2;
          while (j < working.length()){
            power += working.charAt(j);
            j++;
          }
          float powow = power.toFloat();
          coef = coef * powow;
          if (coef > 0){
            if (ret != ""){
              last = "+";
            } else {
              last = "";
            }
            pin();
          } else {
            last = "";
          }
          powow -= 1;
          if (powow != 1){
            ret += last;
            ret += String(coef);
            ret += "x^";
            ret += String(powow);
            working = "";
          } else {
            ret += last;
            ret += String(coef);
            ret += "x";
            working = "";
          }
          pin();
        } else {
          float coef = coefficient.toFloat();
          ret += last + String(coef);
          working = "";
        }
        pin();
        if (input.charAt(i) == '+' || input.charAt(i) == '-'){
          last = String(input.charAt(i));
        } else {
          last = "";
        }
      } else {
        working = "";
      }
    }
  } while(i < input.length());
  if (ret == ""){
    ret = "0";
  }
  return ret;
}

void loop(){
  Serial.println(diff(readd()));
  digitalWrite(13, LOW);
  Serial.println();
}
