/**
 * TODO description
 */
#ifndef SteinhartHart_h
#define SteinhartHart_h

#include <inttypes.h>

#define V_IN 5.0	// Input voltage
#define K 9.5		// mW dec C - dissipation factor


class SteinhartHart 
{
	public:
		SteinhartHart(uint8_t reading_pin, double ntc_resistance, double a, double b, double c);
		SteinhartHart(uint8_t reading_pin, double ntc_resistance);
		SteinhartHart(uint8_t reading_pin);
		double getTempKelvin();
		double getTempCelsius();
		double getTempFahrenheit();
		
	private:
		void init(uint8_t, double, double, double, double);
		double steinhartHart(double);
		
		double _ntc_resistance;
		uint8_t _reading_pin;
		double _a;
		double _b;
		double _c;
};

#endif