#include <WiFi.h>


const char* ssid    = "Redmi Note 9 Pro";  
const char* password = "9e65a49241be";  


WiFiServer server(80);


String header;
String Device1State = "off";
 String Device2State = "off";
 String Device3State = "off";

const int Device1 = 4; 
 const int Device2 = 19; 
 const int Device3 = 21;  

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

void setup() {
  Serial.begin(9600);
 
  pinMode(Device1, OUTPUT);
pinMode(Device2, OUTPUT);
 pinMode(Device3, OUTPUT);

 digitalWrite(Device1, LOW);
   digitalWrite(Device2, LOW);
   digitalWrite(Device3, LOW);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   

  if (client) {                             
    Serial.println("New Client.");          
    String currentLine = "";                
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { 
      currentTime = millis();         
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        header += c;
        if (c == '\n') {                   
          
          if (currentLine.length() == 0) {
          
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
     


            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("Device 1 on");
              Device1State = "on";
              digitalWrite(Device1, LOW);
            } 
            else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("Device 1 off");
              Device1State = "off";
              digitalWrite(Device1, HIGH);
            }

              else if (header.indexOf("GET /2/on") >= 0) {
               Serial.println("Device 2 on");
                Device2State = "on";
               digitalWrite(Device2, LOW);
             } else if (header.indexOf("GET /2/off") >= 0) {
               Serial.println("Device 2 off");
               Device2State = "off";
               digitalWrite(Device2, HIGH);
             }
             else if (header.indexOf("GET /3/on") >= 0) {
               Serial.println("Device 3 on");
               Device3State = "on";
               digitalWrite(Device3, LOW);
             }
             else if (header.indexOf("GET /3/off") >= 0) {
               Serial.println("Device 3 off");
               Device3State = "off";
              digitalWrite(Device3, HIGH);
             }
            
            //the HTML web page
            client.println("<!DOCTYPE html>");
            client.println("<html lang=\"en-US\">");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
                client.println("<link rel=\"stylesheet\"href=\"https://fonts.googleapis.com/css2?family=Tilt Prism\">");
                 client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css?family=Sofia\">");
                  client.println("<link rel=\"stylesheet\"href=\"https://fonts.googleapis.com/css2?family=Moirai One\">");
     client.println("<link rel=\"stylesheet\"href=\"https://fonts.googleapis.com/css2?family=Special Elite\">");
    client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css2?family=Foldit\">");
    client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css2?family=Monoton\">");
    client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css2?family=Rock 3D\">");
    client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css2?family=Cabin Sketch\">");
    client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css2?family=Cinzel Decorative\">");
    client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css2?family=Fredericka the Great\">");
    client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css2?family=Pacifico\">");
    client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css2?family=Lobster\">");

          
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println("Body { background-color:#fefae0;}");
            client.println("header { text-align:center; color:#219ebc; font-family:Special Elite; margin:auto;border-bottom:2px solid #168aad; line-height:2.2em;}");
            client.println(".button { background-color: #ef233c; border: 2px solid wheat; color: white; padding: 16px 40px; font-family:Cabin Sketch;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
             client.println(".button2 {background-color: #8ecae6; color:#d90429}");
client.println(".main {font-family: Monoton; background: linear-gradient(to right, #007bff, #118ab2, #adc178, #03c0ff);-webkit-text-fill-color: transparent;-webkit-background-clip: text;}");
             client.println(".one,.two,.three {display:flex; flex-direction:column;justify-content:center;align-items:center;}");
             client.println("p {font-size:2em; font-family:Cabin Sketch;}");
             client.println(".devices {display:flex; align-items:center; justify-content:space-around;}");
             client.println("@media(max-width:600px){.devices{display:flex;flex-direction:column;align-items:center; justify-content:center;}}</style></head>");
            
        
            client.println("<body><header><h1><span class=\"main\">Home Automation Project</span><br>Prakhar Tripathi</h1></header>");
            
          

            client.println("<div class=\"devices\"><div class=\"one\"><p>Room 1 Light is " + Device1State + "</p>");
                  
            if (Device1State=="off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p></div>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p></div>");
            } 
               
            client.println("<div class=\"two\"><p>Room 2 Light is " + Device2State + "</p>");
                 
             if (Device2State=="off") {
               client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p></div>");
             } else {
               client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p></div>");
             }

          
             client.println("<div class=\"three\"><p>Room 3 Fan is " + Device3State + "</p>");
                 
             if (Device3State=="off") {
               client.println("<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p></div>");
             } else {
               client.println("<p><a href=\"/3/off\"><button class=\"button button2\">OFF</button></a></p></div>");
             }

            
            client.println("</div></body></html>");
            
          
            client.println();
           
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') { 
          currentLine += c;      
        }
      }
    }
    header = "";
  
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
