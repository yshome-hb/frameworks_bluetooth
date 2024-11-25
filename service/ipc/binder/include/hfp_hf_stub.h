/****************************************************************************
 *  Copyright (C) 2023 Xiaomi Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ***************************************************************************/

#ifndef __BT_HFP_HF_STUB_H__
#define __BT_HFP_HF_STUB_H__

#include <stdbool.h>
#include <stdint.h>
#include <uchar.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <android/binder_manager.h>

typedef struct {
    AIBinder_Class* clazz;
    AIBinder_Weak* WeakBinder;
    void* usr_data;
} IBtHfpHf;

typedef struct {
    AIBinder_Class* clazz;
    AIBinder* binder;
} BpBtHfpHf;

typedef enum {
    IHFP_HF_REGISTER_CALLBACK = FIRST_CALL_TRANSACTION,
    IHFP_HF_UNREGISTER_CALLBACK,
    IHFP_HF_IS_CONNECTED,
    IHFP_HF_IS_AUDIO_CONNECTED,
    IHFP_HF_GET_CONNECTION_STATE,
    IHFP_HF_CONNECT,
    IHFP_HF_DISCONNECT,
    IHFP_HF_AUDIO_CONNECT,
    IHFP_HF_AUDIO_DISCONNECT,
    IHFP_HF_START_VOICE_RECOGNITION,
    IHFP_HF_STOP_VOICE_RECOGNITION,
    IHFP_HF_DIAL,
    IHFP_HF_DIAL_MEMORY,
    IHFP_HF_REDIAL,
    IHFP_HF_ACCEPT_CALL,
    IHFP_HF_REJECT_CALL,
    IHFP_HF_HOLD_CALL,
    IHFP_HF_TERMINATE_CALL,
    IHFP_HF_CONTROL_CALL,
    IHFP_HF_QUERY_CURRENT_CALL,
    IHFP_HF_SEND_AT_CMD,
} IBtHfpHf_Call;

#define HFP_HF_BINDER_INSTANCE "Vela.Bluetooth.Hfp.HF"

binder_status_t BtHfpHf_addService(IBtHfpHf* HfpHf, const char* instance);
AIBinder* BtHfpHf_getService(BpBtHfpHf** bpHfpHf, const char* instance);

#ifdef __cplusplus
}
#endif
#endif /* __BT_HFP_HF_STUB_H__ */