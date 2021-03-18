//
//              MADE BY JJ_00ne for all the fellow apes
//
//==============================================================================
//Due to LCD dimension, you can fit in a maximum gain of 9999.99$, so maybe it will
//become useless when the squeeze will squoze. We will buy a bigger LCD with our tendies.
//These are the variables you have to change:

//the website where your PHP is located. You don't need the full url, just www.site.com
const char website[] PROGMEM = "www.site.com";

//number of shares
int sharez = 69;

//Cost of the shares (price at which you bought multiplied by the number of shares)
//If you have multiple positions opened at different price, you have to sum all the
//cost of all the positions.
float expensez = 69.69;

//Other expenses for the shares (commissions, overnight interests,...)
float expensez = 420.69;

//decomment the line suitable for your board:
//Arduino MEGA:
LiquidCrystal lcd(12,11,6,5,4,3);
//Arduino UNO
//LiquidCrystal lcd(12,11,6,5,4,3);

//You should also check comments on line 101 and 61
//==============================================================================


#include <EtherCard.h>
#include <LiquidCrystal.h>
String websito;
float price;
#define HTTP_HEADER_OFFSET 0
static byte mymac[] = {0x12,0x34,0x56,0x78,0x90,0xAB}; //Change the MAC if this one cause conflict in your network
byte Ethernet::buffer[700];
static uint32_t timer = 0;

static void response_callback (byte status, word off, word len) {
  websito=String((const char*) Ethernet::buffer + off);
  websito=websito.substring(240,246);
  price = websito.toFloat();
  Serial.print("Price: ");
  Serial.println(price);
  Serial.print("Tendies: ");
  Serial.println((sharez*price) - expensez - costz); 

  lcd.setCursor(9,0);
  lcd.print(price);
  lcd.print("$");
  lcd.setCursor(8,1);
  lcd.print((sharez*price) - expensez - costz);
  lcd.print("$");
} 

void setup () {
  Serial.begin(9600);
  lcd.begin(16,2); //If you have a different LCD, change the dimension here
  lcd.print("Price: ");
  lcd.setCursor(0,1);
  lcd.print("Tendies: ");

  if (!ether.begin(sizeof Ethernet::buffer, mymac))
  {
    Serial.println("Failed to access Ethernet controller");
    while(1);
  }
  else
    Serial.println("Ethernet controller initialized");
  Serial.println();

  if (!ether.dhcpSetup())
  {
    Serial.println("Failed to get configuration from DHCP");
    while(1);
  }
  else
    Serial.println("DHCP configuration done");

  if (!ether.dnsLookup(website))
  {
    Serial.println("DNS failed");
    while(1);
  }
  else 
    Serial.println("DNS resolution done"); 

  ether.printIp("SRV IP:\t", ether.hisip);
  Serial.println();
}

void loop() {
  ether.packetLoop(ether.packetReceive());

  if (millis() > timer) {
    timer = millis() + 10000;
    
    ether.browseUrl(PSTR("/parse.php"), "/parse.php", website, response_callback);  //If you upload the PHP on your server with a different name, change it here
  }
}
