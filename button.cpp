#include "twilio.hpp"

// Set wifi
static const char *ssid = "";
static const char *password = "";

// Values from Twilio (find them on the dashboard)
static const char *account_sid = "";
static const char *auth_token = "";
// Phone number should start with "+<countrycode>"
static const char *from_number = "";

// You choose!
// Phone number should start with "+<countrycode>"
static const char *to_number = "";
static const char *message = "Sent from my ESP32";
static const char *message2 = "NEED TO POOP!";

Twilio *twilio;

void setup()
{
    pinMode(2, INPUT);
    Serial.begin(115200);
    Serial.print("Connecting to WiFi network ;");
    Serial.print(ssid);
    Serial.println("'...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connecting...");
        delay(500);
    }
    Serial.println("Connected!");

    twilio = new Twilio(account_sid, auth_token);
}

void loop()
{
    int buttonState = digitalRead(2);
    if (buttonState == 1)
    {
        bool success = twilio->send_message(to_number, from_number, message2, response);
        if (success)
        {
            Serial.println("Sent message successfully!");
            delay(1000);
        }
        Serial.println(buttonState);
        delay(5);
    }