/*
 * Copyright (c) 2021 DIY356
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MG_BFLOWSENS_SDK_H_
#define MG_BFLOWSENS_SDK_H_

#include <stdbool.h>
#include "mg_bthing_sdk.h"
#include "mg_bsensor_sdk.h"
#include "mgos_bflowsens.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MG_BFLOWSENS_NEW(s) MG_BTHING_SENS_NEW(s);

/*****************************************
 * Cast Functions
 */

// Convert (mgos_bflowsens_t) into (struct mg_bthing_sens *)
struct mg_bthing_sens *MG_BFLOWSENS_CAST1(mgos_bflowsens_t thing);
/*****************************************/

#define MG_BFLOWSENS_CFG(s) ((struct mg_bflowsens_cfg *)MG_BFLOWSENS_CAST1(s)->cfg)

struct mg_bflowsens_overrides {
  mg_bthing_getting_state_handler_t getting_state_cb;
};

struct mg_bflowsens_cfg {
  struct mg_bsensor_cfg base;
  struct mg_bflowsens_overrides overrides;
  // add here extra fields
};

bool mg_bflowsens_init(mgos_bflowsens_t sens, struct mg_bflowsens_cfg *cfg);

void mg_bflowsens_reset(mgos_bflowsens_t sens);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MG_BFLOWSENS_SDK_H_ */