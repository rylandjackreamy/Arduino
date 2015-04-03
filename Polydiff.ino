
/*
String readd() {
  String rett = ""; // again ret is a return variable
  char in; // char is the character input
  while(!Serial.available()){}
  while (Serial.available() > 0){ // loop strings together the input
    Serial.println(Serial.available());
    in = Serial.read();
    Serial.println(in);
    rett += in; // appends the input character to the return string
  }
  Serial.println(rett);
  return rett;
}
*/

String diff() {
  int i = 0, j;
  String ret = "";
  int place = 0;
  String working = "", coefficient, power, ending = "", last = "";
  String input = "3x^34+4x-5"; //readd();
  Serial.println(input);
  while(i < input.length()) {
    coefficient = "";
    power = "";
    if (input.charAt(i) != '+' && input.charAt(i) != '-' && i < input.length()){
      working += input.charAt(i);
    } else {
      Serial.println(working);
      j = 0;
      ret = "";
      coefficient = "";
      power = "";
      while(working.charAt(j) != 'x' && j < working.length()) {
        coefficient += working.charAt(j);
        j++;
      }
      Serial.println(coefficient);
      if (working.charAt(j) == 'x'){
        Serial.println(working.charAt(j));
        if (working.charAt(j + 1) == '^') {
          Serial.println(working.charAt(j + 1));
          j += 2;
          while (j < working.length()){
            power += working.charAt(j);
            j++;
          }
          Serial.println(power);
          int coef = coefficient.toInt();
          int powow = power.toInt();
          coef = coef * powow;
          powow -= 1;
          if (powow > 1){
            ret += last;
            ret += String(coef);
            ret += "x^";
            ret += String(powow);
          } else {
            ret += last;
            ret += String(coef);
            ret += "x";
          }
          if (input.charAt(i) == '+' || input.charAt(i) == '-'){
            last = String(input.charAt(i));
          } else {
            last = "";
          }
        } else {
          int coef = coefficient.toInt();
          ret += String(coef) + ending;
        }
      }
    }
    i ++;
  }
  return ret;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(diff());
}

void loop(){}
