/**
 * TODO Description
 */
#include <inttypes.h>
#include "WProgram.h"
#include "SteinhartHart.h"
#include <math.h>

	
void SteinhartHart::init(uint8_t reading_pin, double ntc_resistance, double a, double b, double c)
{
	_reading_pin = reading_pin;
	_ntc_resistance = ntc_resistance;
	_a = a;
	_b = b;
	_c = c;
}


SteinhartHart::SteinhartHart(uint8_t reading_pin, double ntc_resistance, double a, double b, double c)
{
	init(reading_pin, ntc_resistance, a, b, c);
}


SteinhartHart::SteinhartHart(uint8_t reading_pin, double ntc_resistance)
{
	init(reading_pin, ntc_resistance, 1.129148e-3, 2.34125e-4, 8.76741e-8);
}


SteinhartHart::SteinhartHart(uint8_t reading_pin) 
{
	init(reading_pin, 10000.0, 1.129148e-3, 2.34125e-4, 8.76741e-8);
}


double SteinhartHart::steinhartHart(double r)
{
	double logR  = log(r);
	double logR3 = logR * logR * logR;

	return 1.0 / (_a + _b * logR + _c * logR3 );
}


double SteinhartHart::getTempKelvin() 
{
	double adc_raw = analogRead(_reading_pin);
	double voltage = adc_raw / 1024 * V_IN;
	double resistance = ((1024 * _ntc_resistance / adc_raw) - _ntc_resistance);
	double kelvin = steinhartHart(resistance) - voltage * voltage / (K * _ntc_resistance);

	return kelvin;
}


double SteinhartHart::getTempCelsius() 
{
	return getTempKelvin() - 273.15;
}


double SteinhartHart::getTempFahrenheit()
{
	return getTempCelsius() * 9/5 + 32;
}
