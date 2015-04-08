void setup() {
  // put your setup code here, to run once:

}

boolean frac = false;

String chunk(String chunkIn){
  String ret, chunkF, chunkS;
  int i = 0;
  boolean first = true, fOp = true;
  char chF, op;
  while (i < chunkIn.length()){
    chF = chunkIn.charAt(i);
    if (chF == '^' || chF == '/' || chF == '*' || chF == '+' || chF == '-' || chF == '!' && fOp){
      op = chF;
      fOp = false;
    } else if (chunkFirst){
      chunkF += chunkIn.charAt(i);
    } else {
      chunkS += chunkIn.charAt(i);
    }
  }
  if (op == '/'){
    int pl = 0;
    while (pl < chunkF){
      
    }
}


void loop() {
  // put your main code here, to run repeatedly:

}
