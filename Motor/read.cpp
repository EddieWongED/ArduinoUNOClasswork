#include <Arduino.h>
#include <SPI.h>
#include "../lib/arduino-mcp2515/mcp2515.h"

struct can_frame canMsg;
MCP2515 mcp2515(10);

void setup()
{
  Serial.begin(115200);

  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();

}

void loop()
{
if (mcp2515.readMessage(&canMsg1) == MCP2515::ERROR_OK)
  {
    Serial.print("id = ");
    Serial.print(canMsg1.can_id, HEX); // print ID
    Serial.println();
    Serial.print("dlc = ");
    Serial.print(canMsg1.can_dlc, HEX); // print DLC
    Serial.println();
    int pos = canMsg1.data[0] << 8 | canMsg1.data[1];
    int vel = canMsg1.data[2] << 8 | canMsg1.data[3];
    int torqueCurrent = canMsg1.data[4] << 8 | canMsg1.data[5];
    int temperture = canMsg1.data[6];

    Serial.print("Position: ");
    Serial.print(pos, DEC);
    Serial.println();
    Serial.print("Velocity: ");
    Serial.print(vel, DEC);
    Serial.println();
    Serial.print("Torque Current: ");
    Serial.print(torqueCurrent, DEC);
    Serial.println();
    Serial.print("Temperture: ");
    Serial.print(temperture, DEC);
    Serial.println();
  }
}