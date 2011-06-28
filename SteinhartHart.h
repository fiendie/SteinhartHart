/**
 * SteinhartHart.h - Library for interacting with NTC thermistors
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SteinhartHart_h
#define SteinhartHart_h

#include <inttypes.h>

#define V_IN 5.0	// Input voltage
#define K 9.5		// mW dec C - dissipation factor


class SteinhartHart 
{
	public:
		SteinhartHart(
			uint8_t reading_pin, 
			double ntc_resistance = 10000.0, 
			double a = 1.129148e-3, 
			double b = 2.34125e-4, 
			double c = 8.76741e-8) : 
			_reading_pin(reading_pin), 
			_ntc_resistance(ntc_resistance), 
			_a(a), _b(b), _c(c) {};

		double getTempKelvin();
		double getTempCelsius();
		double getTempFahrenheit();
		
	private:
		double _ntc_resistance;
		uint8_t _reading_pin;
		double _a;
		double _b;
		double _c;
};

#endif