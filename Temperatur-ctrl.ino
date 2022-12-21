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

//********************Temp Control Relay (Also we can use A0,...A5 pin on Uno board)
int PinRelay = 5;
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
int Temp_IN;
//********************Area Tempreture START
int TempSettings = 19;
//********************Area Tempreture END
int TimeDisplay;
boolean Key;

void setup()
{
  Temp.begin();
  Display1.set(7);
  Display1.init();
  Display1.display(Digitos);
  Display1.point(POINT_OFF);
  // pinMode(PinSW, INPUT_PULLUP);
  pinMode(PinRelay, OUTPUT);
  pinMode(PinVccTemp, OUTPUT);
  pinMode(PinGndTemp, OUTPUT);
  digitalWrite(PinRelay, HIGH);
  digitalWrite(PinVccTemp, HIGH);
  Temp.requestTemperatures();
  delay(1000);
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
  if (Temp_IN > TempSettings)
    digitalWrite(PinRelay, LOW);
  if (Temp_IN < TempSettings)
    digitalWrite(PinRelay, HIGH);
}
