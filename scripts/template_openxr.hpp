#ifndef OPENXR_HPP_
#define OPENXR_HPP_ 1

/*
** Copyright (c) 2017-2019 The Khronos Group Inc.
** Copyright (c) 2019 Collabora, Ltd.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** ---- Exceptions to the Apache 2.0 License: ----
**
** As an exception, if you use this Software to generate code and portions of
** this Software are embedded into the generated code as a result, you may
** redistribute such product without providing attribution as would otherwise
** be required by Sections 4(a), 4(b) and 4(d) of the License.
**
** In addition, if you combine or link code generated by this Software with
** software that is licensed under the GPLv2 or the LGPL v2.0 or 2.1
** ("`Combined Software`") and if a court of competent jurisdiction determines
** that the patent provision (Section 3), the indemnity provision (Section 9)
** or other Section of the License conflicts with the conditions of the
** applicable GPL or LGPL license, you may retroactively and prospectively
** choose to deem waived or otherwise exclude such Section(s) of the License,
** but only in their entirety and only with respect to the Combined Software.
**
*/

/*
** This header is generated from the Khronos OpenXR XML API Registry.
**
*/

/*% macro make_spec_url(name) %*//*{ "<https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#" + name + ">" }*//*% endmacro %*/

/*% macro forwardCommandArgs(cur_cmd) %*/ /*{ cur_cmd.params | map(attribute="name") | join(", ") }*/ /*% endmacro %*/

/*% include('template_openxr_nongenerated_base.hpp')%*/
/*% include('template_openxr_manualprojections.hpp')%*/
/*% include('template_openxr_dispatchstatic.hpp')%*/

//## These includes are currently unused
//## /*% include('template_openxr_nongenerated_chains.hpp')%*/
//## /*% include('template_openxr_nongenerated_enhanced.hpp')%*/

/*% include('template_openxr_nongenerated_flags.hpp')%*/
/*% include('template_openxr_nongenerated_unique.hpp')%*/
/*% include('template_openxr_enums.hpp')%*/
/*% include('template_openxr_flags.hpp')%*/
/*% include('template_openxr_exceptions.hpp')%*/
/*% include('template_openxr_structs_forward.hpp')%*/
/*% include('template_openxr_handleclasses.hpp')%*/
/*% include('template_openxr_structs.hpp')%*/
/*% include('template_openxr_dispatchdynamic.hpp')%*/

/*
 * Inline implementations of all trampoline methods and free functions follow.
 * Prototypes may be found above, either in the associated handle class, or immediately following the section of handle classes.
 */
/*% include('template_openxr_methodimpls.hpp')%*/

#endif
