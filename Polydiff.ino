void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

String readd() {
  String ret = ""; // again ret is a return variable
  char in; // char is the character input
  if (Serial.available() > 0){ // loop strings together the input
    in = Serial.read();
    ret += in; // appends the input character to the return string
  }
  return ret;
}

String diff() {
  int i = 0, j;
  String ret = "";
  String working = "", coefficient, power, ending = "";
  String input = readd();
  while(i < input.length()) {
    coefficient = "";
    power = "";
    if (input.charAt(i) != '+' && input.charAt(i) != '-' && i < input.length()){
      working += input.charAt(i);
    } else {
      j = 0;
      ret = "";
      while(working.charAt(j) != 'x' && j < working.length()) {
        coefficient += working.charAt(j);
        j++;
      }
      if (working.charAt(j) == 'x'){
        if (working.charAt(j + 1) == '^') {
          j += 2;
          while (j < working.length()){
            coefficient += working.charAt(j);
          }
          int coef = coefficient.toInt();
          int powow = power.toInt();
          coef = coef * powow;
          powow -= 1;
          if (input.charAt(i) == '+' || input.charAt(i) == '-'){
            ending = input[i];
          } else {
            ending = "";
          }
          if (powow > 1){
            ret += String(coef) + "x^" + String(powow) + ending;
          } else {
            ret += String(coef) + "x" + ending;
          }
        } else {
          ret += String(coef) + ending;
        }
      }
    }
    i ++;
  }
  return ret;
}

void loop(){
  Serial.println(diff());
}
