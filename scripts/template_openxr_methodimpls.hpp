//## Copyright (c) 2017-2019 The Khronos Group Inc.
//## Copyright (c) 2019 Collabora, Ltd.
//##
//## Licensed under the Apache License, Version 2.0 (the "License");
//## you may not use this file except in compliance with the License.
//## You may obtain a copy of the License at
//##
//##     http://www.apache.org/licenses/LICENSE-2.0
//##
//## Unless required by applicable law or agreed to in writing, software
//## distributed under the License is distributed on an "AS IS" BASIS,
//## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//## See the License for the specific language governing permissions and
//## limitations under the License.
//##
//## ---- Exceptions to the Apache 2.0 License: ----
//##
//## As an exception, if you use this Software to generate code and portions of
//## this Software are embedded into the generated code as a result, you may
//## redistribute such product without providing attribution as would otherwise
//## be required by Sections 4(a), 4(b) and 4(d) of the License.
//##
//## In addition, if you combine or link code generated by this Software with
//## software that is licensed under the GPLv2 or the LGPL v2.0 or 2.1
//## ("`Combined Software`") and if a court of competent jurisdiction determines
//## that the patent provision (Section 3), the indemnity provision (Section 9)
//## or other Section of the License conflicts with the conditions of the
//## applicable GPL or LGPL license, you may retroactively and prospectively
//## choose to deem waived or otherwise exclude such Section(s) of the License,
//## but only in their entirety and only with respect to the Combined Software.



namespace OPENXR_HPP_NAMESPACE {

//# for cur_cmd in sorted_cmds
//## /*{ cur_cmd }*/

/*{ protect_begin(cur_cmd) }*/
/*{ discouraged_begin(cur_cmd) }*/

//#     set method = basic_cmds[cur_cmd.name]
//#     set enhanced = enhanced_cmds[cur_cmd.name]

//## Should we hide the result-returning function in enhanced mode?
//#     set hide_simple = enhanced.masks_simple

//# if hide_simple
#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif
template </*{ method.template_defns }*/>
OPENXR_HPP_INLINE /*{method.return_type}*/ /*{method.qualified_name}*/ (
    /*{ method.get_definition_params() | join(", ")}*/) /*{ method.qualifiers }*/ {
    /*{ method.get_invocation() | join("\n") | indent}*/
}
//# if hide_simple
#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
//# else
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif


//# if enhanced.is_two_call
template </*{ enhanced.template_defns }*/>
OPENXR_HPP_INLINE /*{enhanced.return_type}*/ /*{enhanced.qualified_name}*/ (
    /*{ enhanced.get_definition_params() | join(", ")}*/) /*{enhanced.qualifiers}*/ {
    // Two-call idiom
    /*{ enhanced.vec_type }*/ /*{ enhanced.array_param_name }*/;
    /*% set twocallbody %*/
    uint32_t /*{ enhanced.count_output_param_name }*/ = 0;
    uint32_t /*{ enhanced.capacity_input_param_name }*/ = 0;

    /*{ enhanced.pre_statements |join("\n") | indent }*/
    //# if enhanced.item_type == 'char'
    std::basic_string<char, std::char_traits<char>, Allocator> str{vectorAllocator};
    //# endif
    /*{ enhanced.get_main_invoke({enhanced.array_param_name: "nullptr"}) }*/
    if (!unqualifiedSuccess(result) || /*{ enhanced.count_output_param_name }*/ == 0) {

        /*{ enhanced.return_statement }*/
    }
    do {
        /*{ enhanced.array_param_name }*/.resize(/*{ enhanced.count_output_param_name }*/);
        /*{ enhanced.capacity_input_param_name }*/ = static_cast<uint32_t>(/*{enhanced.array_param_name}*/.size());
        //# set raw_array_param = enhanced.array_param_name + ".data()"
        //# set array_param = "reinterpret_cast<" + enhanced.array_param.param.type + "*>(" + raw_array_param + ")"
        /*{ enhanced.get_main_invoke({ enhanced.array_param_name: array_param }) | replace("Result ", "") }*/
    } while (result == xr::Result::ErrorSizeInsufficient);
    if (result == xr::Result::Success) {
        OPENXR_HPP_ASSERT(/*{ enhanced.count_output_param_name }*/ <= /*{enhanced.array_param_name}*/.size());
        /*{enhanced.array_param_name}*/.resize(/*{ enhanced.count_output_param_name }*/);
    }
    /*{ enhanced.post_statements |join("\n") | indent }*/
    //# if enhanced.item_type == 'char'
    str.assign(/*{ enhanced.array_param_name }*/.begin(), /*{ enhanced.array_param_name }*/.end());
    //# endif
    /*{ enhanced.return_statement }*/
    /*% endset %*/
    /*{ twocallbody |replace('vectorAllocator', '{}') }*/
}

template </*{ enhanced.template_defns }*/>
OPENXR_HPP_INLINE /*{enhanced.return_type}*/ /*{enhanced.qualified_name}*/ (
    //# set params = enhanced.get_definition_params(extras=["Allocator const& vectorAllocator"])
    /*{ params | join(", ")}*/) /*{enhanced.qualifiers}*/ {
    // Two-call idiom
    /*{ enhanced.vec_type }*/ /*{ enhanced.array_param_name }*/{vectorAllocator};
    /*{ twocallbody }*/
}
//# else
//## Not two-call

template </*{ enhanced.template_defns }*/>
OPENXR_HPP_INLINE /*{enhanced.return_type}*/ /*{enhanced.qualified_name}*/ (
    /*{ enhanced.get_definition_params() | join(", ")}*/) /*{enhanced.qualifiers}*/ {
    /*{ enhanced.get_invocation() | join("\n") | indent}*/
}
//# endif


//# if enhanced.is_create
#ifndef OPENXR_HPP_NO_SMART_HANDLE

//#     set uniq = unique_cmds[cur_cmd.name]
template </*{ uniq.template_defns }*/>
OPENXR_HPP_INLINE /*{uniq.return_type}*/ /*{uniq.qualified_name}*/ (
    /*{ uniq.get_definition_params() | join(", ")}*/) /*{uniq.qualifiers}*/ {
    /*{ uniq.get_invocation() | join("\n") | indent}*/
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
//# endif
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

/*{ discouraged_end(cur_cmd) }*/
/*{ protect_end(cur_cmd) }*/
//# endfor


}  // namespace OPENXR_HPP_NAMESPACE
