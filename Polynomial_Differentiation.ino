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
  // put your main code here, to run repeatedly:
  int i = 0;
  String ret = "";
  String input = readd();
  while(i < input.length()) {
    int j = 0;
    String working = "";
    String coefficient = "";
    String power = "";
    while((input.charAt(i) != '+' || input.charAt(i) != '-') && i < input.length()) {
      working += input.charAt(i);
      i++;
      Serial.println(input.charAt(i));
    }  
    ret = "";
    while(working.charAt(j) != 'x' || working.charAt(j) != '+' || working.charAt(j) != '-' || j == working.length()) {
      coefficient += working.charAt(j);
      j++;
    }
    Serial.println(working);
    if (working.charAt(j) == '+' || working.charAt(j) == '-') {
      ret += input.charAt(i);
    } else if (working.charAt(j + 1) != '^') {
      ret += coefficient + input.charAt(i);
    } else {
      while(j < working.length()) {
        power += working.charAt(j);
        j++;
      }
      j += 2;
      int coef = coefficient.toInt();
      int powow = power.toInt();
      coef *= powow;
      powow -= 1;
      ret += String(coef) + "x^" + String(powow) + input.charAt(i);
    }
  }
  return ret;
}

void loop(){
  Serial.println(diff());
}
