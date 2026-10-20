// address 0x00d8ea  size 18 bytes
// callers: 00b256,

/* Initialise fan timers and sensor faults */

undefined1 fan_init(void)

{
  fan_runon_lo = 0xff;
  fan_runon_hi = 0xff;
  fan_heater_runon_lo = 0xff;
  fan_heater_runon_hi = 0xff;
  device_sensor_fault = 0;
  dryer_sensor_fault = 0;
  presence_flags = 0;
  return 0;
}

