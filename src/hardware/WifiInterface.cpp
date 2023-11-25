#include "WifiInterface.h"
#include "_Credentials.h"

/*
 * ESP is a pain to ensure statup
 * happens on a clean slate.
 */
void WiFiReset()
{
    WiFi.persistent(false);
    WiFi.disconnect();
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);
}

void printWiFiStatus(wl_status_t p_WiFiStatus)
{
    Serial.print("WiFi Status: ");
    switch (p_WiFiStatus)
    {

    case WL_IDLE_STATUS:
        Serial.println("WL_IDLE_STATUS -- temporary status assigned when WiFi.begin() is called");
        break;

    case WL_NO_SSID_AVAIL:
        Serial.println("WL_NO_SSID_AVAIL -- when no SSID are available");
        break;

    case WL_SCAN_COMPLETED:
        Serial.println("WL_SCAN_COMPLETED -- scan networks is completed");
        break;

    case WL_CONNECTED:
        Serial.println("WL_CONNECTED -- connected to a WiFi network");
        break;

    case WL_CONNECT_FAILED:
        Serial.println("WL_CONNECT_FAILED -- the connection fails for all the attempts");
        break;

    case WL_CONNECTION_LOST:
        Serial.println("WL_CONNECTION_LOST -- the connection is lost");
        break;

    case WL_DISCONNECTED:
        Serial.println("WL_DISCONNECTED -- disconnected from a network");
        break;
    default:
        Serial.println("unknown");
    }
}

WifiInterface::WifiInterface()
{
}

void WifiInterface::configure()
{
    wl_status_t status;
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (status != WL_CONNECTED)
    {
        delay(1000);
        printWiFiStatus(status);
        Serial.println("Connecting to WiFi...");
        status = WiFi.status();
    }

    Serial.println("Connected to WiFi");
}

WiFiClient &WifiInterface::getWifiClient()
{
    return client_;
}