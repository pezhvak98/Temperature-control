<h4 align="center">A simple and interesting project to work with<a href="https://www.arduino.cc/" target="_blank"> Arduino Uno</a>.</h4>
<p align="center">
  <a href="https://www.arduino.cc/en/software">
    <img src="https://www.svgrepo.com/show/353423/arduino.svg"
         alt="Gitter">
  </a>
  <h5 align="center">Designed and implemented by : Pezhvak ;)</h5>
</p>

## Items needed

> **Note**
> this is an educational project and the design goal is not a professional tool.

| items                                                                                        | #Q  |
| -------------------------------------------------------------------------------------------- | --- |
| Arduino Uno Board                                                                            | 1   |
| 5V relay module                                                                              | 1   |
| Jumper board wire                                                                            | 1   |
| The cable connecting its board to the computer (such as the connecting cable of the printer) | 1   |
| TM1637 seven-segment 4-digit display module                                                  | 1   |
| 4.7 kilo ohm resistance with 0.25 watt power and 5% tolerance                                | 1   |
| temperature sensor (DS18B20)                                                                 | 1   |
| Cooler (Fan => 12V)                                                                          | 1   |
| heater (low-ampere filament lamp)                                                            | 1   |
| 12V-2A Adapter (Independent power source for cooling and heating control)                    | 1   |

## How To work

With the help of a temperature sensor, a cooler (fan) and a heater (low-ampere filament lamp), we keep the temperature of the chamber constant, for example, the temperature of the chamber should be 25 degrees Celsius.

If the temperature drops, the heater starts working to increase the temperature

If the temperature rises, the cooling circuit turns on and the chamber temperature decreases.

In this way, the temperature remains constant

## Download

- [Arduino IDE 1.8.19](https://www.arduino.cc/en/software)

> **Note**
> Don't forget to download the libraries included in this repository to run the code correctly.
> The path to install libraries in Arduino software :
> **Sketch > Include Library > Add .ZIP Library…**

## Programming on Arduino board

- Connect the Arduino board to the computer via USB cable.

**The first method**

- After running the Arduino software, click on the **New** option through the **File** menu.
- Paste the codes placed in file **Temperatur-ctrl** in the new window
- Now select the **Save** option from the **File** menu and save the program in your desired location.
- After saving the program, go to the **Board** menu through the Tools menu and select the **Arduino Uno** item from the drop-down list.
- Go to the **Port** menu again through the same Tools menu and select the USB port number through which the Arduino board is connected to the computer from the drop-down list.
- In the end, to transfer the program to the Arduino board, it is enough to click on the **upload** icon to program the program on the Arduino board in the Arduino software.

**The second method**

- After running the Arduino software, click on the **open** option through the File menu.
- and open file **Temperatur-ctrl**
- After openning the program, go to the **Board** menu through the Tools menu and select the **Arduino Uno** item from the drop-down list.
- Go to the **Port** menu again through the same Tools menu and select the USB port number through which the Arduino board is connected to the computer from the drop-down list.
- In the end, to transfer the program to the Arduino board, it is enough to click on the **upload** icon to program the program on the Arduino board in the Arduino software.

## How to use

After entering the necessary codes, connect the board to the computer through a serial port and from the serial part of the monitor, we can set our desired temperature by entering the number of that temperature. You can also connect the board to your phone with a OTG Make these settings using the [Serial USB Terminal](https://play.google.com/store/apps/details?id=de.kai_morich.serial_usb_terminal&hl=fa&gl=US&pli=1) program tool, which is the same as the serial monitor of the Arduino editor

## [![image](https://www.linkpicture.com/q/Screenshot-from-2022-12-30-23-30-28.png)](https://www.linkpicture.com/view.php?img=LPic63af440db3c922033888547)

> GitHub [@pezhvak98](https://github.com/pezhvak98) &nbsp;&middot;&nbsp;
> Twitter [@pezhvak_98](https://twitter.com/pezhvak_98)
