

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

String readd() {
  while(Serial.available() <= 0){}
  String in = Serial.readString();
  Serial.println(in);
  return in;
}


String diff() {
  int i = -1, j;
  String ret = "";
  int place = 0;
  String working = "", coefficient, power, ending = "", last = "";
  String input = readd();
  do {
    i ++;
    coefficient = "";
    power = "";
    if (input.charAt(i) != '+' && input.charAt(i) != '-' && i < input.length()){
      working += input.charAt(i);
    } else {
      j = 0;
      coefficient = "";
      power = "";
      if (working.charAt(j) == 'x'){
        coefficient = "1";
      }
      while(working.charAt(j) != 'x' && j < working.length()) {
        coefficient += working.charAt(j);
        j++;
      }
      if (working.charAt(j) == 'x'){
        if (working.charAt(j + 1) == '^') {
          j += 2;
          while (j < working.length()){
            power += working.charAt(j);
            j++;
          }
          int coef = coefficient.toInt();
          int powow = power.toInt();
          coef = coef * powow;
          powow -= 1;
          if (powow > 1){
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
        } else {
          int coef = coefficient.toInt();
          ret += last + String(coef);
          working = "";
        }
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
  return ret;
}




void loop(){
  Serial.println(diff());
}
