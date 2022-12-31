/*
  Temperature control (keeping the temperature constant)

  With the help of a temperature sensor, a cooler (fan) and
  a heater (low-ampere filament lamp), we keep the temperature
  of the chamber constant, for example, the temperature of the
  chamber should be 25 degrees Celsius.
  If the temperature drops, the heater starts working to increase the temperature
  If the temperature rises, the cooling circuit turns on and the chamber temperature decreases.
  In this way, the temperature remains constant

  Designed and implemented by : Pezhvak


*/

//********************Temp Control Relay
int PinRelay1 = 5;
int PinRelay2 = 6;
//********************Display
int PinClkLcd = 2;
int PinDioLcd = 3;
#include <TM1637.h>
#define CLK PinClkLcd
#define DIO PinDioLcd
TM1637 Display1(CLK, DIO);
//********************Temp
int PinVccTemp = 8;
int PinDataTemp = 9;
int PinGndTemp = 10;
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS PinDataTemp
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature Temp(&oneWire);
int8_t Digitos[] = {8, 8, 8, 8};
int8_t GDigitos[] = {8, 8, 8, 8};
int Temp_IN;
//********************Area Tempreture
int TempSettings = 25;
//********************Switch
// int PinSW = 12;
int TimeSW;
int TimeDisplay;
boolean Key;

void setup()
{
  Temp.begin();
  Serial.begin(9600);
  Display1.set(7);
  Display1.init();
  Display1.display(Digitos);
  Display1.point(POINT_OFF);
  // pinMode(PinSW, INPUT_PULLUP);
  pinMode(PinRelay1, OUTPUT);
  pinMode(PinRelay2, OUTPUT);
  pinMode(PinVccTemp, OUTPUT);
  pinMode(PinGndTemp, OUTPUT);
  digitalWrite(PinRelay1, HIGH);
  digitalWrite(PinRelay2, LOW);
  digitalWrite(PinVccTemp, HIGH);
  Temp.requestTemperatures();
  Serial.println("Ready!");
  delay(500);
}
void loop()
{
  Temp.requestTemperatures();
  Temp_IN = Temp.getTempCByIndex(0);
  int8_t Digit2 = Temp_IN % 10;
  int8_t Digit1 = (Temp_IN % 100) / 10;
  Digitos[3] = 12;
  Digitos[2] = Digit2;
  Digitos[1] = Digit1;
  Digitos[0] = 19;
  Display1.display(Digitos);
  //***************************get serial
  String GetTemp;
  if (Serial.available())
  {
    GetTemp = Serial.readString();
    TempSettings = GetTemp.toInt();
    Serial.print("/****   GetTemp   ****\  ");
    Serial.println(GetTemp);
    int8_t FDigit = GetTemp.substring(0, 1).toInt();
    int8_t SDigit = GetTemp.substring(1, 2).toInt();
    GDigitos[3] = 12;
    GDigitos[2] = SDigit;
    GDigitos[1] = FDigit;
    GDigitos[0] = 16;
    Display1.display(GDigitos);
    Serial.print(" The entered temperature  ");
    Serial.print(GetTemp);
    Serial.println("  was saved");
    delay(2000);
    Display1.display(Digitos);
  }
  delay(50);
  if (Temp_IN < (TempSettings - 0.2))
  {
    // delay(500);
    digitalWrite(PinRelay1, HIGH);
    Serial.println("Heater on");
    digitalWrite(PinRelay2, LOW);
  }
  if (Temp_IN > (TempSettings + 0.9))
  {
    do
    {
      digitalWrite(PinRelay1, LOW);
      delay(800);
      digitalWrite(PinRelay2, HIGH);
      Serial.println("fan on");

    } while (Temp_IN == (TempSettings));
    digitalWrite(PinRelay2, HIGH);
    digitalWrite(PinRelay1, HIGH);
    Serial.println("BOTH OFF");
  }
  delay(1500);
  Serial.println("    "); // add space
  Serial.print("chamber Temprature = ");
  Serial.println(Temp_IN);
  Serial.print("SET POINT Temprature =  ");
  Serial.println(TempSettings);
}
