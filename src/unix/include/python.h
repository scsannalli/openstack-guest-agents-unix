/*
 * vim: tabstop=4 shiftwidth=4 softtabstop=4
 *
 * Copyright (c) 2011 Openstack, LLC.
 * All Rights Reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *    WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 *    License for the specific language governing permissions and limitations
 *    under the License.
 */

#ifndef __NOVA_AGENT_PYTHON_H__
#define __NOVA_AGENT_PYTHON_H__

#include <sys/types.h>
/* Stupid hack.  Python.h redefines this */
#undef _POSIX_C_SOURCE
#include <Python.h>

/* Support for older versions of Python */
#ifndef PyVarObject_HEAD_INIT
#define PyVarObject_HEAD_INIT(type, size)	\
	_PyObject_EXTRA_INIT			\
	1, type, size,
#endif

#ifndef PY_SSIZE_T_MAX
typedef ssize_t Py_ssize_t;
#endif

typedef struct _agent_python_info agent_python_info_t;

agent_python_info_t *agent_python_init(int argc, char * const *argv, int syspython);
void agent_python_deinit(agent_python_info_t *pi);
int agent_python_run_file(agent_python_info_t *pi, const char *filename);
int agent_python_test_mode(agent_python_info_t *pi);
int agent_python_start_interpreter(agent_python_info_t *pi);

#endif /* __NOVA_AGENT_PYTHON_H__ */
