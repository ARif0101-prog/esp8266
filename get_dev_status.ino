
//include libraries
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> 
 
//Access point credentials
const char* ssid = "testtt";
const char* pwd = "testtest";
const char* host = "http://192.168.1.6";
String get_host = "http://192.168.1.6";
 
WiFiServer server(80);  // open port 80 for server connection
 
void setup() 
{
  pinMode(D4, OUTPUT);
  Serial.begin(115200); //initialise the serial communication
  delay(20);
 
  WiFi.begin(ssid, pwd);
 
   
    //starting the server
    server.begin();
 
}
 
void loop()
{
  //call_test();
  get_device_status("home_light","Home Light");
  get_device_status("shop_light","Shop Light");
       
}
 
 
void call_test()
{
  Serial.println("It is test");
  }
 
void get_device_status(String device_name, String device_text)
  {
    
    WiFiClient client = server.available();
 
        HTTPClient http;
        String url = get_host+"/getdb.php?device_name="+device_name;
        
        http.begin(client,url);
       
        //GET method
        int httpCode = http.GET();
        String payload = http.getString();

//Serial.println(device_text);

if (device_text =="Home Light" && payload =="1")
{
digitalWrite(D4, LOW);

}
else if (device_text =="Home Light" && payload =="0")
{

  digitalWrite(D4, HIGH);
}

  
 }