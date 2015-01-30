
/* Copyright (c) 2015 Open Networking Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>
#include <string.h>

#include <libnetconf.h>

#ifdef __GNUC__
#   define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#   define UNUSED(x) UNUSED_ ## x
#endif

int
ofcds_init(void *UNUSED(data))
{
    return EXIT_SUCCESS;
}

void
ofcds_free(void *UNUSED(data))
{
    return;
}

int
ofcds_changed(void *UNUSED(data))
{
    return (0);
}

int
ofcds_rollback(void *UNUSED(data))
{
    return EXIT_SUCCESS;
}

int
ofcds_lock(void *UNUSED(data), NC_DATASTORE UNUSED(target),
           const char *UNUSED(session_id), struct nc_err **UNUSED(error))
{
    return EXIT_SUCCESS;
}

int
ofcds_unlock(void *UNUSED(data), NC_DATASTORE UNUSED(target),
             const char *UNUSED(session_id), struct nc_err **UNUSED(error))
{
    return EXIT_SUCCESS;
}

char *
ofcds_getconfig(void *UNUSED(data), NC_DATASTORE UNUSED(target),
                struct nc_err **UNUSED(error))
{
    return strdup("");
}

int
ofcds_copyconfig(void *UNUSED(data), NC_DATASTORE UNUSED(target),
                 NC_DATASTORE UNUSED(source), char *UNUSED(config),
                 struct nc_err **UNUSED(error))
{
    return EXIT_SUCCESS;
}

int
ofcds_deleteconfig(void *UNUSED(data), NC_DATASTORE UNUSED(target),
                   struct nc_err **UNUSED(error))
{
    return EXIT_SUCCESS;
}

int
ofcds_editconfig(void *UNUSED(data), const nc_rpc * UNUSED(rpc),
                 NC_DATASTORE UNUSED(target), const char *UNUSED(config),
                 NC_EDIT_DEFOP_TYPE UNUSED(defop),
                 NC_EDIT_ERROPT_TYPE UNUSED(errop),
                 struct nc_err **UNUSED(error))
{
    return EXIT_SUCCESS;
}

struct ncds_custom_funcs ofcds_funcs = {
    .init = ofcds_init,
    .free = ofcds_free,
    .was_changed = ofcds_changed,
    .rollback = ofcds_rollback,
    .lock = ofcds_lock,
    .unlock = ofcds_unlock,
    .is_locked = NULL,
    .getconfig = ofcds_getconfig,
    .copyconfig = ofcds_copyconfig,
    .deleteconfig = ofcds_deleteconfig,
    .editconfig = ofcds_editconfig,
};