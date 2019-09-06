
namespace OPENXR_HPP_NAMESPACE {
//# for enum in gen.api_enums
//#     set projected_type = project_type_name(enum.name)
/*{ protect_begin(enum) }*/
enum class /*{projected_type -}*/ : /*{ 'int32_t' if enum.name == 'XrResult' else 'uint32_t' }*/ {
    //# for val in enum.values
    /*{ protect_begin(val, enum) }*/
    /*{create_enum_value(val.name, enum.name)}*/ = /*{val.name}*/,
    /*{ protect_end(val, enum) }*/
    //# endfor
};

OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR /*{enum.name}*/ get(/*{projected_type}*/ const& v) {
    return static_cast</*{enum.name}*/>(v);
}

OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char* to_string_literal(/*{projected_type}*/ value) {
    switch (value) {
            //# for val in enum.values
        /*{ protect_begin(val, enum) }*/
        //# set valname = create_enum_value(val.name, enum.name)
        case /*{projected_type -}*/ ::/*{- valname }*/:
            return /*{ valname | quote_string }*/;
            /*{ protect_end(val, enum) }*/
            //# endfor
        default:
            return "invalid";
    }
}

OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string to_string(/*{projected_type}*/ value) {
    return {to_string_literal(value)};
}

/*{ protect_end(enum) }*/
//# endfor

}  // namespace OPENXR_HPP_NAMESPACE