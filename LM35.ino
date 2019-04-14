#include "LM35.h"

LM35 temp(A0);
void setup()
{
	Serial.begin(9600);
}

void loop()
{
    Serial.print("TempC");
    Serial.println(temp.getTempC());
    Serial.print("TempF");
    Serial.println(temp.getTempF());
}
