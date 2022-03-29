#include "mgos.h"
#include "mg_bflowsens_sdk.h"

/*****************************************
 * Cast Functions
 */

// Convert (mgos_bflowsens_t) into (struct mg_bthing_sens *)
struct mg_bthing_sens *MG_BFLOWSENS_CAST1(mgos_bflowsens_t thing) {
  return (struct mg_bthing_sens *)thing;
}
/*****************************************/

bool mg_bflowsens_init(mgos_bflowsens_t sens, struct mg_bflowsens_cfg *cfg) {
  if (cfg) {
    if (mg_bsensor_init(sens, &cfg->base)) {
      /* initalize overrides cfg */
      cfg->overrides.getting_state_cb = NULL;
      
      return true; // initialization successfully completed
    }
    mg_bflowsens_reset(sens);
  } else {
    LOG(LL_ERROR, ("Invalid NULL 'cfg' parameter."));
  }

  LOG(LL_ERROR, ("Error initializing bFlowSensor '%s'. See above error message for more details.",
    mgos_bthing_get_uid(MGOS_BFLOWSENS_THINGCAST(sens))));
  return false; 
}

void mg_bflowsens_reset(mgos_bflowsens_t sens) {
  struct mg_bflowsens_cfg *cfg = MG_BFLOWSENS_CFG(sens);

  /* clear overrides cfg */
  if (cfg->overrides.getting_state_cb) {
    mg_bthing_on_getting_state(sens, cfg->overrides.getting_state_cb);
    cfg->overrides.getting_state_cb = NULL;
  }

  // reset sensor-base obj
  mg_bsensor_reset(sens);
}
