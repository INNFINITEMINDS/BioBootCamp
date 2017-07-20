# How to hook up your AD8232 Heart Monitor
This folder contains all of the software that you need to run the AD8232 Heart Monitor and to visualize your electrocardiogram.

## Required Programs
Before you can get started you need to have both the [Arduino IDE](https://www.arduino.cc) and the [Processing IDE](https://www.processing.org) installed and available on your computer. The links above will take you to the Processing and Arduino sites.

**NOTE:** If you are using a Raspberry Pi you need to download the [Linux ARMv6hf](http://download.processing.org/processing-3.3.5-linux-armv6hf.tgz) version of the Processing IDE. Click the link in this paragraph to download the file. When it is completed, extract the contents of the folder to the desktop. Open a terminal at that location and type `./install.sh`.

## Instructions
* First, upload the ad8232.ino file onto your Arduino using the Arduino IDE. Make sure to change the pins to match the physical connections that you make on your hardware.
* Next, make sure to attach the electrodes to your wrists, and one on your right ankle. Be sure to clean the area with an alcohol swab or you might not get a great connection!
* Attach the sensor cable to the electrodes on your wrist according to the table below.

| Blue      | Red         | Black      |
|:---------:|:-----------:|:----------:|
|Left Wrist | Right Ankle | Right Wrist|

* Finally, open the electrocardiogram.pde file using the Processing IDE and click play

## Please hack it!
You should customize the program to make it look the way YOU want it to. Start by going into the Processing code and changing colors. You can do that by modifying the `stroke(255,0,0)` or the `background(0,0,0)` properties.
