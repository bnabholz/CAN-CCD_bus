//Thanks to oh2nlt for documenting OBD-I information over a decade ago.  Codes listed here were reverse engineered from OBD-II Jeep electronics.

/*
Not actually an ID in usage?  This is the same as an open bus.
ID - 0xFF
*/
#define ECHO_ID (0xFF)

/*
ID - MPH - KPH
MPH = Value
KPH = Value
*/
#define SPEED_ID (0x24)

/*
Note: The RPM and MAP need to be updated on the CCD bus every few seconds if the engine is not running.
Otherwise the odometer will display "no bus" on late 1990s models after twenty seconds.
ID - RPM - MAP
RPM = Value * 32  Example: 25(DEC) * 32 = 800 RPM
MAP = (Value * 41) / 100
*/
#define RPM_MAP_ID (0xE4)

/*
ID - TPS - Cruise On/Off
Float TPS = (Value * 67) / 100
Cruise = 0x00 (off) or 0x?? (on)
*/
#define CRUISE_ID (0x42)

/*
Pre-OBD-II and/or export vehicles.
ID - Current Voltage - Target Voltage
Float voltage = Value / 16
Float target voltage = Value / 16
*/
#define VOLTAGE_ID (0xD4)

/*
Pre-OBD-II and/or export vehicles.
ID - Coolant Temperature - Battery Temperature
Coolant = Value - 128
Battery = Value - 128
*/
#define TEMPERATURE_ID (0x8C)

/*
Pre-OBD-II and/or export vehicles.
ID - 0x000000
*/
#define TRIP_DIST_ID (0xEE)

/*
ID - Shift Light - ??
Shift Light = 0x00 off, 0xFF on
Cruise Light = 0x00 off, 0xFF on
*/
#define SHIFT_CRUISE_LIGHT_ID (0xA4)

/*
ID - Check Gauges Light - ??
Check Gauges Light = 0x00 off, 0xFF on
?? = Unknown
*/
#define CG_LIGHT_ID (0xEC)

/*
ID - Check Engine Light - ??
Check Engine Light = 0x00 off, 0xFF on
?? = Unknown
*/
#define CE_LIGHT_ID (0xF5)

/*
ID - Sentry Key Immobilizer Light
SKIM Light = 0x00 off, 0xFF on (with brief buzz)
*/
#define SKIM_LIGHT_ID (0x0B)

/*
ID - Buzzer
Buzzer = 0x00 off, 0xFF buzz briefly.
*/
#define BUZZER_ID (0x9A)

/*
ID - Airbag Good Status
Status = Any value turns off airbag light.
*/
#define AIRBAG_GOOD_ID (0x50)

/*
ID - Airbag Bad Status
Status = Any value turns on airbag light.
*/
#define AIRBAG_BAD_ID (0x51)

/*
Variable byte width, minimum 4 bytes.  Unknown functionality past byte #3.
ID - Voltage - Oil PSI - Coolant Temperature
Voltage = Value / 8  Example: 112 / 8 = 14 volts
Oil PSI = Value / 2  Example: 160 / 2 = 80 PSI
Coolant Temperature = Uhhhh?  The scaling on XJ cluster is fucky.
145(0x91) = 180ºF displayed
145(0x96) = 182.5ºF displayed
165(0xA5) = 210ºF displayed
185(0xB9) = 220ºF displayed, so 2 decimal = 1ºF
188 to 192 = 250ºF displayed, automatically the "engine doesn't feel so good" reading.
193 or higher = 260ºF displayed, "OH SHIT".  Value has to drop to 191 past 192 to back to 250ºF.
Value * 0.78571429  Example: 210 * 0.78571429
*/
#define VOLTS_OILPSI_COOLTEMP_ID (0x0C)

/*
Increments vehicle odometer and trip odometer.
ID - ?? - Miles Increased
?? = This is most likely kilometers increased.
Miles Increased = Value * 0.3~ OR about 0.0416~ miles per bit.
*/
#define DIST_INCR_ID (0x84)
