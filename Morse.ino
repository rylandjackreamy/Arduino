void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

String letters(char l){ //takes in a character, outputs a string containing dots & dashes
  String ret;
  if (l=='a'){
    ret = "13";
  } else if (l=='b'){
  ret = "3111";
  } else if (l=='c'){
    ret = "3131";
  } else if (l=='d'){
    ret = "311";
  } else if (l=='e'){
    ret = "e";
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
  } else {
    ret = "";
  }
  return ret;
}

int t = 100, del, d; // t is the length of a dot

void loop() {
  // need to get new String letrs via input, havent figured that out yet 
  String letrs = "SoS";
  letrs.toLowerCase();
  int x = 0;
  String wait = "";
  while(x < letrs.length()){
    wait = letters(letrs.charAt(x)); // gets dots & dashes for letter
    if(letrs[x] == ' '){
      delay(t * 4); // if a space, wait longer
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
    delay(t * 3); // time between letter
    x ++;
  }
}
