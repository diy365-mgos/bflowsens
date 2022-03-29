#include "mgos.h"
#include "mgos_bthing.h"
#include "mg_bflowsens_sdk.h"
#include "mgos_bflowsens.h"

#ifdef MGOS_HAVE_MJS
#include "mjs.h"
#endif

mgos_bthing_t MGOS_BFLOWSENS_THINGCAST(mgos_bflowsens_t sensor) {
  return MG_BTHING_SENS_CAST4(MG_BFLOWSENS_CAST1(sensor));
}

mgos_bsensor_t MGOS_BFLOWSENS_DOWNCAST(mgos_bflowsens_t sensor) {
  return (mgos_bsensor_t)sensor;
}

mgos_bflowsens_t mgos_bflowsens_create(const char *id, const char *domain) {
  mgos_bflowsens_t MG_BFLOWSENS_NEW(sens);
  if (mg_bthing_init(MG_BTHING_SENS_CAST3(sens), id, MGOS_BFLOWSENS_TYPE, domain)) {
    struct mg_bflowsens_cfg *cfg = calloc(1, sizeof(struct mg_bflowsens_cfg));
    if (cfg) {
      mgos_bthing_t thing = MGOS_BFLOWSENS_THINGCAST(sens);
      if (mg_bflowsens_init(sens, cfg) && mg_bthing_register(thing)) {
        LOG(LL_INFO, ("bFlowSensor '%s' successfully created.", mgos_bthing_get_uid(thing)));
        return sens;
      }
      mg_bthing_reset(MG_BTHING_SENS_CAST3(sens));
    } else {
      LOG(LL_ERROR, ("Unable to allocate memory for 'mg_bflowsens_cfg'"));
    }
    free(cfg);
  }
  free(sens);
  LOG(LL_ERROR, ("Error creating bFlowSensor '%s'. See above error message for more details.'", (id ? id : "")));
  return NULL; 
}

bool mgos_bflowsens_init() {
  return true;
}