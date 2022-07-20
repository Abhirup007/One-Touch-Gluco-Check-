# One-Touch-Gluco-Check
# Project Title
## Description
One-TouchGluco Check is one of the emerging glucometer which is based on the NON-INVASIVE technique. This involves the NIR spectroscopy based IR wavelength which is optimsed for glucose monitoring in our blood. We have captured this wavelength IR ligh with a 940nm based IR photodiode. Now for getting the voltage levels, amplification, noise reduction OPAMP (operational amplifier) is used. Finally after getting the voltages, it is converted into equivalent ADC value with the help of Arduino Nano microcontroller. Since arduino has 10 bits of the ADC resolution, now to increase the resolution of getting more voltage accuracy, 16- bit ADC is used hence ADS1115 is used. After that voltage levels and glucose obtained by prick method will be correlated with the help of machine learning algorithms to predict the glucose level.

Miconcontroller used: - Arduino Nano 
Sensors used: - IR sensor, IR photodiode
Programming Language - Arduino interfaced C++ 
IDE: - Arduino IDE version 1.8.16

## Getting Started

### Dependencies

* Spectrum Analyzer is needed to verify the wavelength of the IR led

### Installing

* All the libraries mentioned

## Authors

Author - Abhirup Bhattacharyya, katha Ghosh, Aanchal Gupta

## Version History

* 1.0

## License

This project is licensed under the Abhirup Bhattacharyya
