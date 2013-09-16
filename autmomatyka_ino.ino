#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 10);
byte gateway[] = { 192 ,168 ,1 ,1 };
byte subnet[] = { 255 ,255 ,255 ,0 };
EthernetServer server(80);
float temp;
String readString = String(30);


int motor[] = {2, 3};//rolety


#define tempe_pin A0    //temperatura
#define tempe2_pin A1
int tempepin, tempepin2;
float tempe, tempe2; 
unsigned long czas;


void setup() {
   Ethernet.begin(mac, ip, gateway, subnet);
   int i;
   for(i = 0; i < 2; i++){
   pinMode(motor[i], OUTPUT); //rolety
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   }
}  

void loop(){
  temperatura();
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (readString.length() < 30)
        {
          readString = readString + c;
        }
        if (c == '\n') {
         
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();          
          
          if(readString.startsWith("GET /p1on"))
          {
            
            p1on();
            client.print("{\"status\" : \"1\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }
          
          if(readString.startsWith("GET /p1off"))
          {
           
           p1off();
            client.print("{\"status\" : \"0\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }
          if(readString.startsWith("GET /p2on"))
          {
            
            p2on();
            client.print("{\"status\" : \"1\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }
          
          if(readString.startsWith("GET /p2off"))
          {
           
           p2off();
            client.print("{\"status\" : \"0\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }  
          if(readString.startsWith("GET /p3on"))
          {
            
            p3on();
            client.print("{\"status\" : \"1\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }
          
          if(readString.startsWith("GET /p3off"))
          {
           
           p3off();
            client.print("{\"status\" : \"0\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }  
          if(readString.startsWith("GET /p4on"))
          {
            
            p4on();
            client.print("{\"status\" : \"1\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }
          
          if(readString.startsWith("GET /p4off"))
          {
           
           p4off();
            client.print("{\"status\" : \"0\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }  
          if(readString.startsWith("GET /rg"))
          {
            
            roletygora();
            client.print("{\"status\" : \"1\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }
          
          if(readString.startsWith("GET /rd"))
          {
           
           rletydol();
            client.print("{\"status\" : \"0\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }  
         if(readString.startsWith("GET /rs"))
          {
           
           roletystop();
            client.print("{\"status\" : \"0\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }   
          if(readString.startsWith("GET /temp1"))
          {
           
         client.print (tempe);
        
         }  
         if(readString.startsWith("GET /temp2"))
          {
           
         client.print (tempe2);
        
         }              
          
          readString="";
          client.stop();
        }
      }
    }
  }
}


void roletygora(){
   digitalWrite(motor[1], LOW); 
   digitalWrite(motor[0], HIGH); 
}

void rletydol(){
   digitalWrite(motor[0], LOW); 
   digitalWrite(motor[1], HIGH); 
}

void roletystop(){
   digitalWrite(motor[0], LOW); 
   digitalWrite(motor[0], HIGH); 
}

void temperatura(){
  czas = millis();
  tempe = analogRead(tempe_pin);  
  tempe2 = analogRead(tempe2_pin);
  tempe = (5.0 * tempe * 100.0)/1024.0;  
  tempe2 = (5.0 * tempe2 * 100.0)/1024.0;
  delay (1500);
}

void p1on(){ 
  digitalWrite(4, HIGH); //przeka
}

void p1off(){
  digitalWrite(4, LOW);  
}

void p2on(){ 
  digitalWrite(5, HIGH);
}

void p2off(){
  digitalWrite(5, LOW);  
}

void p3on(){ 
  digitalWrite(6, HIGH);
}

void p3off(){
  digitalWrite(6, LOW);  
}

void p4on(){ 
  digitalWrite(7, HIGH);
}

void p4off(){
  digitalWrite(7, LOW);  //
}



  
