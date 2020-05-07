/*!
 *  @file Adafruit_TCS34725.h
 *
 *  Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, Adafruit Industries
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *  1. Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holders nor the
 *  names of its contributors may be used to endorse or promote products
 *  derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
 *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
 *  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 *  DAMAGE.
 */
#ifndef _TCS34725_H_
#define _TCS34725_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Wire.h>

#define TCS34725_ADDRESS (0x29)     /**< I2C address **/
#define TCS34725_COMMAND_BIT (0x80) /**< Command bit **/
#define TCS34725_ENABLE (0x00)      /**< Interrupt Enable register */
#define TCS34725_ENABLE_AIEN (0x10) /**< RGBC Interrupt Enable */
#define TCS34725_ENABLE_WEN                                                    \
  (0x08) /**< Wait Enable - Writing 1 activates the wait timer */
#define TCS34725_ENABLE_AEN                                                    \
  (0x02) /**< RGBC Enable - Writing 1 actives the ADC, 0 disables it */
#define TCS34725_ENABLE_PON                                                    \
  (0x01) /**< Power on - Writing 1 activates the internal oscillator, 0        \
            disables it */
#define TCS34725_ATIME (0x01) /**< Integration time */
#define TCS34725_WTIME                                                         \
  (0x03) /**< Wait time (if TCS34725_ENABLE_WEN is asserted) */
#define TCS34725_WTIME_2_4MS (0xFF) /**< WLONG0 = 2.4ms   WLONG1 = 0.029s */
#define TCS34725_WTIME_204MS (0xAB) /**< WLONG0 = 204ms   WLONG1 = 2.45s  */
#define TCS34725_WTIME_614MS (0x00) /**< WLONG0 = 614ms   WLONG1 = 7.4s   */
#define TCS34725_AILTL                                                         \
  (0x04) /**< Clear channel lower interrupt threshold (lower byte) */
#define TCS34725_AILTH                                                         \
  (0x05) /**< Clear channel lower interrupt threshold (higher byte) */
#define TCS34725_AIHTL                                                         \
  (0x06) /**< Clear channel upper interrupt threshold (lower byte) */
#define TCS34725_AIHTH                                                         \
  (0x07) /**< Clear channel upper interrupt threshold (higher byte) */
#define TCS34725_PERS                                                          \
  (0x0C) /**< Persistence register - basic SW filtering mechanism for          \
            interrupts */
#define TCS34725_PERS_NONE                                                     \
  (0b0000) /**< Every RGBC cycle generates an interrupt */
#define TCS34725_PERS_1_CYCLE                                                  \
  (0b0001) /**< 1 clean channel value outside threshold range generates an     \
              interrupt */
#define TCS34725_PERS_2_CYCLE                                                  \
  (0b0010) /**< 2 clean channel values outside threshold range generates an    \
              interrupt */
#define TCS34725_PERS_3_CYCLE                                                  \
  (0b0011) /**< 3 clean channel values outside threshold range generates an    \
              interrupt */
#define TCS34725_PERS_5_CYCLE                                                  \
  (0b0100) /**< 5 clean channel values outside threshold range generates an    \
              interrupt */
#define TCS34725_PERS_10_CYCLE                                                 \
  (0b0101) /**< 10 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_15_CYCLE                                                 \
  (0b0110) /**< 15 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_20_CYCLE                                                 \
  (0b0111) /**< 20 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_25_CYCLE                                                 \
  (0b1000) /**< 25 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_30_CYCLE                                                 \
  (0b1001) /**< 30 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_35_CYCLE                                                 \
  (0b1010) /**< 35 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_40_CYCLE                                                 \
  (0b1011) /**< 40 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_45_CYCLE                                                 \
  (0b1100) /**< 45 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_50_CYCLE                                                 \
  (0b1101) /**< 50 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_55_CYCLE                                                 \
  (0b1110) /**< 55 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_PERS_60_CYCLE                                                 \
  (0b1111) /**< 60 clean channel values outside threshold range generates an   \
              interrupt*/
#define TCS34725_CONFIG (0x0D) /**< Configuration **/
#define TCS34725_CONFIG_WLONG                                                  \
  (0x02) /**< Choose between short and long (12x) wait times via               \
            TCS34725_WTIME */
#define TCS34725_CONTROL (0x0F) /**< Set the gain level for the sensor */
#define TCS34725_ID                                                            \
  (0x12) /**< 0x44 = TCS34721/TCS34725, 0x4D = TCS34723/TCS34727 */
#define TCS34725_STATUS (0x13)      /**< Device status **/
#define TCS34725_STATUS_AINT (0x10) /**< RGBC Clean channel interrupt */
#define TCS34725_STATUS_AVALID                                                 \
  (0x01) /**< Indicates that the RGBC channels have completed an integration   \
            cycle */
#define TCS34725_CDATAL (0x14) /**< Clear channel data low byte */
#define TCS34725_CDATAH (0x15) /**< Clear channel data high byte */
#define TCS34725_RDATAL (0x16) /**< Red channel data low byte */
#define TCS34725_RDATAH (0x17) /**< Red channel data high byte */
#define TCS34725_GDATAL (0x18) /**< Green channel data low byte */
#define TCS34725_GDATAH (0x19) /**< Green channel data high byte */
#define TCS34725_BDATAL (0x1A) /**< Blue channel data low byte */
#define TCS34725_BDATAH (0x1B) /**< Blue channel data high byte */

/** Integration time settings for TCS34725 */
/* 100ms is evenly divisible by 50Hz periods and by 60Hz periods */
// hex FF   cycles   1   integ 2.40   60Hz cycles 0.14   50Hz cycles 0.12
#define TCS34725_INTEGRATIONTIME_2_4MS (0xFF)/* 2.4ms - 1 cycle - Max Count: 1024 */
// hex F6   cycles  10   integ 24.00   60Hz cycles 1.44   50Hz cycles 1.20
#define TCS34725_INTEGRATIONTIME_24MS (0xF6) /* 24ms - 10 cycles - Max Count: 10240 */
// hex EB   cycles  21   integ 50.40   60Hz cycles 3.02   50Hz cycles 2.52
#define TCS34725_INTEGRATIONTIME_50MS (0xEB) /* 50.4ms - 21 cycles - Max Count: ???? */
// hex E7   cycles  25   integ 60.00   60Hz cycles 3.60   50Hz cycles 3.00
#define TCS34725_INTEGRATIONTIME_60MS (0xE7)
// hex D6   cycles  42   integ 100.80   60Hz cycles 6.05   50Hz cycles 5.04
#define TCS34725_INTEGRATIONTIME_101MS (0xD6)/* 100.8ms - 42 cycles - Max Count: 43008 */
// hex CE   cycles  50   integ 120.00   60Hz cycles 7.20   50Hz cycles 6.00
#define TCS34725_INTEGRATIONTIME_120MS (0xCE)
// hex C0   cycles  64   integ 153.60   60Hz cycles 9.22   50Hz cycles 7.68
#define TCS34725_INTEGRATIONTIME_154MS (0xC0)/* 153.6ms - 64 cycles - Max Count: 65535 */
// hex B5   cycles  75   integ 180.00   60Hz cycles 10.80   50Hz cycles 9.00
#define TCS34725_INTEGRATIONTIME_180MS (0xB5)
// hex AD   cycles  83   integ 199.20   60Hz cycles 11.95   50Hz cycles 9.96
#define TCS34725_INTEGRATIONTIME_154MS (0xAD)
// hex 9C   cycles 100   integ 240.00   60Hz cycles 14.40   50Hz cycles 12.00
#define TCS34725_INTEGRATIONTIME_240MS (0x9C)
// hex 83   cycles 125   integ 300.00   60Hz cycles 18.00   50Hz cycles 15.00
#define TCS34725_INTEGRATIONTIME_300MS (0x83)/* 300ms - 125 cycles - Max Count: 65535 */
// hex 6A   cycles 150   integ 360.00   60Hz cycles 21.60   50Hz cycles 18.00
#define TCS34725_INTEGRATIONTIME_360MS (0x6A)
// hex 59   cycles 167   integ 400.80   60Hz cycles 24.05   50Hz cycles 20.04
#define TCS34725_INTEGRATIONTIME_401MS (0x59)
// hex 51   cycles 175   integ 420.00   60Hz cycles 25.20   50Hz cycles 21.00
#define TCS34725_INTEGRATIONTIME_420MS (0x51)
// hex 38   cycles 200   integ 480.00   60Hz cycles 28.80   50Hz cycles 24.00
#define TCS34725_INTEGRATIONTIME_480MS (0x38)
// hex 30   cycles 208   integ 499.20   60Hz cycles 29.95   50Hz cycles 24.96
#define TCS34725_INTEGRATIONTIME_499MS (0x30)
// hex 1F   cycles 225   integ 540.00   60Hz cycles 32.40   50Hz cycles 27.00
#define TCS34725_INTEGRATIONTIME_540MS (0x1F)
// hex 06   cycles 250   integ 600.00   60Hz cycles 36.00   50Hz cycles 30.00
#define TCS34725_INTEGRATIONTIME_600MS (0x06)
// hex 00   cycles 256   integ 614.40   60Hz cycles 36.86   50Hz cycles 30.72
#define TCS34725_INTEGRATIONTIME_614MS (0x00)/* 614.4ms - 256 cycles - Max Count: 65535 */

/** Gain settings for TCS34725  */
typedef enum {
  TCS34725_GAIN_1X = 0x00,  /**<  No gain  */
  TCS34725_GAIN_4X = 0x01,  /**<  4x gain  */
  TCS34725_GAIN_16X = 0x02, /**<  16x gain */
  TCS34725_GAIN_60X = 0x03  /**<  60x gain */
} tcs34725Gain_t;

/*!
 *  @brief  Class that stores state and functions for interacting with
 *          TCS34725 Color Sensor
 */
class Adafruit_TCS34725 {
public:
  Adafruit_TCS34725(uint8_t = TCS34725_INTEGRATIONTIME_2_4MS,
                    tcs34725Gain_t = TCS34725_GAIN_1X);

  boolean begin(uint8_t addr, TwoWire *theWire);
  boolean begin(uint8_t addr);
  boolean begin();
  boolean init();

  void setIntegrationTime(uint8_t it);
  void setGain(tcs34725Gain_t gain);
  void getRawData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);
  void getRGB(float *r, float *g, float *b);
  void getRawDataOneShot(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);
  uint16_t calculateColorTemperature(uint16_t r, uint16_t g, uint16_t b);
  uint16_t calculateColorTemperature_dn40(uint16_t r, uint16_t g, uint16_t b,
                                          uint16_t c);
  uint16_t calculateLux(uint16_t r, uint16_t g, uint16_t b);
  void write8(uint8_t reg, uint32_t value);
  uint8_t read8(uint8_t reg);
  uint16_t read16(uint8_t reg);
  void setInterrupt(boolean flag);
  void clearInterrupt();
  void setIntLimits(uint16_t l, uint16_t h);
  void enable();
  void disable();

private:
  TwoWire *_wire;
  uint8_t _i2caddr;
  boolean _tcs34725Initialised;
  tcs34725Gain_t _tcs34725Gain;
  uint8_t _tcs34725IntegrationTime;
};

#endif
