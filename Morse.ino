int t = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

int ret[] = {};
void letters(char l){
  if (l=='a'){
    int ret[] = {
      1, 3
    };
  } else if (l=='b'){
    int ret[] = {
      3, 1, 1, 1
    };
  } else if (l=='c'){
    int ret[] = {
      3, 1, 3, 1
    };
  } else if (l=='d'){
    int ret[] = {
      3, 1, 1
    };
  } else if (l=='e'){
    int ret[] = {
      1
    };
  } else if (l=='f'){
    int ret[] = {
      1, 1, 3, 1
    };
  } else if (l=='g'){
    int ret[] = {
      3, 3, 1
    };
  } else if (l=='h'){
    int ret[] = {
      1, 1, 1, 1
    };
  } else if (l=='i'){
    int ret[] = {
      1, 1
    };
  } else if (l=='j'){
    int ret[] = {
      1, 3, 3, 3
    };
  } else if (l=='k'){
    int ret[] = {
      3, 1, 3
    };
  } else if (l=='l'){
    int ret[] = {
      1, 3, 1, 1
    };
  } else if (l=='m'){
    int ret[] = {
      3, 3
    };
  } else if (l=='n'){
    int ret[] = {
      3, 1
    };
  } else if (l=='o'){
    int ret[] = {
      3, 3, 3
    };
  } else if (l=='p'){
    int ret[] = {
      1, 3, 3, 1
    };
  } else if (l=='q'){
    int ret[] = {
      3, 3, 1, 3
    };
  } else if (l=='r'){
    int ret[] = {
      1, 3, 1
    };
  } else if (l=='s'){
    int ret[] = {
      1, 1, 1
    };
  } else if (l=='t'){
    int ret[] = {
      3
    };
  } else if (l=='u'){
    int ret[] = {
      1, 1, 3
    };
  } else if (l=='v'){
    int ret[] = {
      1, 1, 1, 3
    };
  } else if (l=='w'){
    int ret[] = {
      1, 3, 3
    };
  } else if (l=='x'){
    int ret[] = {
      3, 1, 1, 3
    };
  } else if (l=='y'){
    int ret[] = {
      3, 1, 3, 3
    };
  } else if (l=='z'){
    int ret[] = {
      3, 3, 1, 1
    };
  } else {
    int ret[] = {};
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //get new string in
  char letrs[] = {'l', 'e', 't', 't', 'e', 'r', 's'};
  int x = 0;
  while(x < sizeof(letrs)){
    letters(letrs[x]);
    if(letrs[x] == ' '){
      delay(t * 4);
    }
    int i = 0;
    while(i < sizeof(ret)){
      pinMode(13, HIGH);
      delay(t * ret[i]);
      pinMode(13, LOW);
      delay(t);
      i ++;
    }
    delay(t * 3);
    x ++;
  }
}
