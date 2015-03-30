String in = "letters";
char[] letrs;
int[] wait;
int t = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

int ret[4];
int  letters(char l){
  if (l=="a"){
    ret[] = {
      1, 3
    };
  } else if (l=="b"){
    ret[] = {
      3, 1, 1, 1
    };
  } else if (l=="c"){
    ret[] = {
      3, 1, 3, 1
    };
  } else if (l=="d"){
    ret[] = {
      3, 1, 1
    };
  } else if (l=="e"){
    ret[] = {
      1
    };
  } else if (l=="f"){
    ret[] = {
      1, 1, 3, 1
    };
  } else if (l=="g"){
    ret[] = {
      3, 3, 1
    };
  } else if (l=="h"){
    ret[] = {
      1, 1, 1, 1
    };
  } else if (l=="i"){
    ret[] = {
      1, 1
    };
  } else if (l=="j"){
    ret[] = {
      1, 3, 3, 3
    };
  } else if (l=="k"){
    ret[] = {
      3, 1, 3
    };
  } else if (l=="l"){
    ret[] = {
      1, 3, 1, 1
    };
  } else if (l=="m"){
    ret[] = {
      3, 3
    };
  } else if (l=="n"){
    ret[] = {
      3, 1
    };
  } else if (l=="o"){
    ret[] = {
      3, 3, 3
    };
  } else if (l=="p"){
    ret[] = {
      1, 3, 3, 1
    };
  } else if (l=="q"){
    ret[] = {
      3, 3, 1, 3
    };
  } else if (l=="r"){
    ret[] = {
      1, 3, 1
    };
  } else if (l=="s"){
    ret[] = {
      1, 1, 1
    };
  } else if (l=="t"){
    ret[] = {
      3
    };
  } else if (l=="u"){
    ret[] = {
      1, 1, 3
    };
  } else if (l=="v"){
    ret[] = {
      1, 1, 1, 3
    };
  } else if (l=="w"){
    ret[] = {
      1, 3, 3
    };
  } else if (l=="x"){
    ret[] = {
      3, 1, 1, 3
    };
  } else if (l=="y"){
    ret[] = {
      3, 1, 3, 3
    };
  } else if (l=="z"){
    ret[] = {
      3, 3, 1, 1
    };
  } else {
    ret[] = {
    };
  }
  return ret
}

void loop() {
  // put your main code here, to run repeatedly:
  //get new string in
  letrs = in;
  x = 0;
  while(x < letrs.length()){
    wait = letters(letrs[x])
    if(letrs[x] == " "){
      delay(t * 7);
    }
    i = 0;
    while(i < wait.length()){
      pinMode(13, HIGH);
      delay(t * wait[i]);
      pinMode(13, LOW);
      delay(t);
    }
    delay(t * 3);
}
