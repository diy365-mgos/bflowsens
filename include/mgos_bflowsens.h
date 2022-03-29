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

#ifndef MGOS_BFLOWSENS_H_
#define MGOS_BFLOWSENS_H_

#include <stdbool.h>
#include "mgos_bthing.h"
#include "mgos_bsensor.h"

#ifdef __cplusplus
extern "C" {
#endif

struct mg_bthing_sens;
typedef struct mg_bthing_sens *mgos_bflowsens_t;

mgos_bthing_t MGOS_BFLOWSENS_THINGCAST(mgos_bflowsens_t sensor);

mgos_bsensor_t MGOS_BFLOWSENS_DOWNCAST(mgos_bflowsens_t sensor);

mgos_bflowsens_t mgos_bflowsens_create(const char *id, const char *domain);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MGOS_BFLOWSENS_H_ */