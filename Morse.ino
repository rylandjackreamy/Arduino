
/* written by:
  timmy
  brian
  jack
*/

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

String letters(char l){ //takes in a character, outputs a string containing dots & dashes
  String ret; // ret is a local variable which will be returned as the function output
  if (l=='a'){ 
    ret = "13"; // 1 for dot 3 for dash
  } else if (l=='b'){
  ret = "3111";
  } else if (l=='c'){
    ret = "3131";
  } else if (l=='d'){
    ret = "311";
  } else if (l=='e'){
    ret = "1";
  } else if (l=='f'){
    ret = "1131";
  } else if (l=='g'){
    ret = "331";
  } else if (l=='h'){
    ret = "1111";
  } else if (l=='i'){
    ret = "11";
  } else if (l=='j'){
    ret = "1333";
  } else if (l=='k'){
    ret = "313";
  } else if (l=='l'){
    ret = "1331";
  } else if (l=='m'){
    ret = "33";
  } else if (l=='n'){
    ret = "31";
  } else if (l=='o'){
    ret = "333";
  } else if (l=='p'){
    ret = "1331";
  } else if (l=='q'){
    ret = "3313";
  } else if (l=='r'){
    ret = "131";
  } else if (l=='s'){
    ret = "111";
  } else if (l=='t'){
    ret = "3";
  } else if (l=='u'){
    ret = "113";
  } else if (l=='v'){
    ret = "1113";
  } else if (l=='w'){
    ret = "133";
  } else if (l=='x'){
    ret = "3113";
  } else if (l=='y'){
    ret = "3133";
  } else if (l=='z'){
    ret = "3311";
  } else if (l == '1'){
    ret = "13333";
  } else if (l == '2'){
    ret = "11333";
  } else if (l == '3'){
    ret = "11133";
  } else if (l == '4'){
    ret = "11113";
  } else if (l == '5'){
    ret = "11111";
  } else if (l == '6'){
    ret = "31111";
  } else if (l == '7'){
    ret = "33111";
  } else if (l == '8'){
    ret = "33311";
  } else if (l == '9'){
    ret = "33331";
  } else if (l == '0'){
    ret = "33333";
  } else {
    ret = ""; // if its not a letter or number ignore it
  }
  return ret;
}

int t = 300, del, d; // t is the length of a dot.  del is the time to delay.  d is used in some computation

String readd() {
  String ret = ""; // again ret is a return variable
  char in; // char is the character input
  if (Serial.available() > 0){ // loop strings together the input
    in = Serial.read();
    ret += in; // appends the input character to the return string
  }
  return ret;
}

void loop() {
  String letrs = readd(); // takes the input string given by the function readd
  delay(t); 
  letrs.toLowerCase(); // puts the whole string in lower case
  int x = 0;
  String wait = "";
  while(x < letrs.length()){
    wait = letters(letrs.charAt(x)); // passes a character from the string into letters to get out dots and dashes
    if(letrs[x] == ' '){
      delay(t * 7); // if a space, wait longer
    }
    int i = 0;    
    while(i < wait.length()){
      digitalWrite(13, HIGH);
      del = int(wait.charAt(i)) - 48; // converting from string to int added 48 for some reason...
      int j = 0;
      d = 0;
      while(j < del){ // some multiplication because that was having trouble
        d += t;
        j += 1;
      }
      delay(d);
      digitalWrite(13, LOW);
      delay(t);
      i ++;
    }
    delay(t * 3); // time between letter is the same as a dash
    x ++;
  }
}
