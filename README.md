# bFlowSensors Library
## Overview
A bFlowSensor allows you to easily manage flow sensors, like water flow sensors.
## GET STARTED
Get started using one of the following examples.
* [Wemos D1 Mini + YF-S201 flow meter](https://github.com/diy365-mgos/bflowsens-gpio#get-started)
## Inherited APIs
A bFlowSensor inherits inherits APIs from:
- [bThing](https://github.com/diy365-mgos/bthing)
- [bSensor](https://github.com/diy365-mgos/bsensor)
### Remarks on: mgos_bthing_on_get_state()
The [get-state handler](https://github.com/diy365-mgos/bthing#mgos_bthing_get_state_handler_t) must set following keys: `MGOS_BFLOWSENS_STATE_FLOW_RATE`, `MGOS_BFLOWSENS_STATE_PARTIAL_FLOW` and `MGOS_BFLOWSENS_STATE_TOTAL_FLOW`. For more details see "Remarks on: mgos_bthing_get_state()" below.
```c
static bool my_get_state_handler(mgos_bthing_t thing, mgos_bvar_t state, void *userdata) {
  float flow_rate, partial_flow, total_flow;
  // calculate flow_rate, partial_flow and total_flow...
  mgos_bvar_set_key_decimal(state, MGOS_BFLOWSENS_STATE_FLOW_RATE, flow_rate);
  mgos_bvar_set_key_decimal(state, MGOS_BFLOWSENS_STATE_PARTIAL_FLOW, partial_flow);
  mgos_bvar_set_key_decimal(state, MGOS_BFLOWSENS_STATE_TOTAL_FLOW, total_flow);
  return true;
}
mgos_bflowsens_t sens = mgos_bflowsens_create(...);
mgos_bthing_on_get_state(MGOS_BFLOWSENS_THINGCAST(sens), my_get_state_handler, NULL);
```
### Remarks on: mgos_bthing_get_state()
The [mgos_bthing_get_state()](https://github.com/diy365-mgos/bthing#mgos_bthing_get_state) returns a [bVariantDictionary](https://github.com/diy365-mgos/bvar-dic) having following keys:
|Key|Type||
|--|--|--|
|MGOS_BFLOWSENS_STATE_FLOW_RATE|decimal|The current flow rate (e.g: L/min).|
|MGOS_BFLOWSENS_STATE_PARTIAL_FLOW|decimal|The partial flow measured since the last flow rate update (e.g.: Liters).|
|MGOS_BFLOWSENS_STATE_TOTAL_FLOW|decimal|The total flow measured since the last device power-on/reboot (e.g.: Liters).|
```c
mgos_bflowsens_t sens = mgos_bflowsens_create(...);
mgos_bvarc_t state = mgos_bthing_get_state(MGOS_BFLOWSENS_THINGCAST(sens));
float flow_rate = mgos_bvar_get_decimal(mgos_bvarc_get_key(state, MGOS_BFLOWSENS_STATE_FLOW_RATE));
float partial_flow = mgos_bvar_get_decimal(mgos_bvarc_get_key(state, MGOS_BFLOWSENS_STATE_PARTIAL_FLOW));
float total_flow = mgos_bvar_get_decimal(mgos_bvarc_get_key(state, MGOS_BFLOWSENS_STATE_TOTAL_FLOW));
```
## C/C++ APIs Reference
### MGOS_BFLOWSENS_TYPE
```c
#define MGOS_BFLOWSENS_TYPE
```
The bFlowSensor type ID. It can be used with [mgos_bthing_is_typeof()](https://github.com/diy365-mgos/bthing#mgos_bthing_is_typeof).

Example:
```c
mgos_bflowsens_t sens = mgos_bflowsens_create(...);
if (mgos_bthing_is_typeof(MGOS_BFLOWSENS_THINGCAST(sens), MGOS_BFLOWSENS_TYPE))
  LOG(LL_INFO, ("I'm a bFlowSensor."));
if (mgos_bthing_is_typeof(MGOS_BFLOWSENS_THINGCAST(sens), MGOS_BSENSOR_TYPE))
  LOG(LL_INFO, ("I'm a bSensor."));
if (mgos_bthing_is_typeof(MGOS_BFLOWSENS_THINGCAST(sens), MGOS_BTHING_TYPE_SENSOR))
  LOG(LL_INFO, ("I'm a bThing sensor."));
```
Output console:
```bash
I'm a bFlowSensor.
I'm a bSensor.
I'm a bThing sensor.
```
### MGOS_BFLOWSENS_THINGCAST
```c
mgos_bthing_t MGOS_BFLOWSENS_THINGCAST(mgos_bflowsens_t sensor);
```
Casts a bFlowSensor to a generic bThing to be used with [inherited bThing APIs](https://github.com/diy365-mgos/bthing).

|Parameter||
|--|--|
|sensor|A bFlowSensor.|

Example:
```c
mgos_bflowsens_t sensor = mgos_bflowsens_create(...);
LOG(LL_INFO, ("%s successfully created.", mgos_bthing_get_uid(MGOS_BFLOWSENS_THINGCAST(sensor))));
```
### MGOS_BFLOWSENS_DOWNCAST
```c
mgos_bsensor_t MGOS_BFLOWSENS_DOWNCAST(mgos_bflowsens_t sensor);
```
Casts a bFlowSensor to a bSensor to be used with [inherited bSensor APIs](https://github.com/diy365-mgos/bsensor).

|Parameter||
|--|--|
|sensor|A bFlowSensor.|
### mgos_bflowsens_create
```c
mgos_bflowsens_t mgos_bflowsens_create(const char *id, const char *domain);
```
Creates a bFlowSensor. Returns `NULL` on error.

|Parameter||
|--|--|
|id|The bFlowSensor ID.|
|domain|The domain name or `NULL`.|
## To Do
- Implement javascript APIs for [Mongoose OS MJS](https://github.com/mongoose-os-libs/mjs).
