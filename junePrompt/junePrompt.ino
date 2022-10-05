String cmd;
char car; 
String ID = "June", PASS = "Sung";
int login = 0; 

void bootupMsg(){
 Serial.println(" ################################/n ##          june Booting      ##/n ################################/n/n");
 
}
void helpMseg(){
   Serial.println("♪~ ♬ ♪♬~♪ ♪~ ♬ ♪♬~♪ ♪~ ♬ ♪♬~♪ ♪/n/n");

}

void promptMsg(){
  Serial.print("♬ ♪♬~♪>> ");
}


void setup() {
  Serial.begin(9600);
  bootupMsg();
  login = 0;                // 로그인 상태 0:OFF, 1:ID, 2:PASS, 3:login 
  Serial.print("ID :  ");
}

void loop() {

  if (Serial.available()) {
    car = Serial.read();
    cmd += String(car);
    Serial.print(car);
  }
   
  if (cmd.indexOf('\n') > -1) {
    if (login == 0) // 로그인하지 않았을때
    {
      if (ID == cmd){
        login = 1;
        Serial.print("PASS :  ");
      } else{
        Serial.print("ID :  ");
      }
      
    }else if (login == 1)
    {
      if (PASS == cmd){
        login = 2;
        promptMsg();
      } else{
        Serial.print("PASS :  ");
      }
    }else if (login == 2)
    {
      promptMsg();
    }
        
    cmd = "";    
  }

 
}
  
  
