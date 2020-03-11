
/*
 Example by mdrehan4all (Md Rehan)
*/

#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "yourappname.firebaseio.com"
#define FIREBASE_AUTH "eWfqtdz83B___Firebase_Realtime_Database_Secret_Key___peXHcBGKcskz"
#define WIFI_SSID "Your Wifi Name"
#define WIFI_PASSWORD "Your Wifi Password"

//Define FirebaseESP8266 data object
//FirebaseData firebaseData0;
FirebaseData firebaseData1;
FirebaseData firebaseData2;
FirebaseData firebaseData3;
FirebaseData firebaseData4;
//FirebaseData firebaseData5;
//FirebaseData firebaseData6;
//FirebaseData firebaseData7;
//FirebaseData firebaseData8;
//FirebaseData firebaseData9;
//FirebaseData firebaseData10;

//PINS
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;

//FirebaseJson json;

void setup()
{

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  //Firebase.setReadTimeout(firebaseData0, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  
  Firebase.setReadTimeout(firebaseData1, 1000 * 60);
  Firebase.setReadTimeout(firebaseData2, 1000 * 60);
  Firebase.setReadTimeout(firebaseData3, 1000 * 60);
  Firebase.setReadTimeout(firebaseData4, 1000 * 60);
  /*
  Firebase.setReadTimeout(firebaseData0, 1000 * 60);
  Firebase.setReadTimeout(firebaseData5, 1000 * 60);
  Firebase.setReadTimeout(firebaseData6, 1000 * 60);
  Firebase.setReadTimeout(firebaseData7, 1000 * 60);
  Firebase.setReadTimeout(firebaseData8, 1000 * 60);
  Firebase.setReadTimeout(firebaseData9, 1000 * 60);
  Firebase.setReadTimeout(firebaseData10, 1000 * 60);
  */
  Firebase.setwriteSizeLimit(firebaseData1, "tiny");
  Firebase.setwriteSizeLimit(firebaseData2, "tiny");
  Firebase.setwriteSizeLimit(firebaseData3, "tiny");
  Firebase.setwriteSizeLimit(firebaseData4, "tiny");
  /*
  Firebase.setwriteSizeLimit(firebaseData0, "tiny");
  Firebase.setwriteSizeLimit(firebaseData5, "tiny");
  Firebase.setwriteSizeLimit(firebaseData6, "tiny");
  Firebase.setwriteSizeLimit(firebaseData7, "tiny");
  Firebase.setwriteSizeLimit(firebaseData8, "tiny");
  Firebase.setwriteSizeLimit(firebaseData9, "tiny");
  Firebase.setwriteSizeLimit(firebaseData10, "tiny");
  */
  
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  //pinMode(D4, OUTPUT);
  //pinMode(D5, OUTPUT);
  //pinMode(D6, OUTPUT);
  //pinMode(D7, OUTPUT);
  //pinMode(D8, OUTPUT);
  //pinMode(D9, OUTPUT);
  //pinMode(D10, OUTPUT);

  //Default
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
}

void loop()
{
  Firebase.get(firebaseData1, "switch1/status");
  Firebase.get(firebaseData2, "switch2/status");
  Firebase.get(firebaseData3, "switch3/status");
  Firebase.get(firebaseData4, "switch4/status");
  //Firebase.get(firebaseData4, "switch4/status");
  //Firebase.get(firebaseData5, "switch5/status");
  //Firebase.get(firebaseData6, "switch6/status");
  //Firebase.get(firebaseData7, "switch7/status");
  //Firebase.get(firebaseData8, "switch8/status");
  //Firebase.get(firebaseData9, "switch9/status");
  //Firebase.get(firebaseData10, "switch10/status");

  int p0 = firebaseData1.intData();
  int p1 = firebaseData2.intData();
  int p2 = firebaseData3.intData();
  int p3 = firebaseData4.intData();
  //int p4 = firebaseData4.intData();
  //int p5 = firebaseData5.intData();
  //int p6 = firebaseData6.intData();
  //int p7 = firebaseData7.intData();
  //int p8 = firebaseData8.intData();
  //int p9 = firebaseData9.intData();
  //int p10 = firebaseData10.intData();

  digitalWrite(D0, p0);
  digitalWrite(D1, p1);
  digitalWrite(D2, p2);
  digitalWrite(D3, p3);
  //digitalWrite(D4, p4);
  //digitalWrite(D5, p5);
  //digitalWrite(D6, p6);
 
  //digitalWrite(D0, p1);
  //digitalWrite(LED_BUILTIN, p2);
  
  //delay(10);
}
