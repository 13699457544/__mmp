//
// Created by xuyunhua on 2018/9/8.
//

#ifndef MP_AC_UTIL_H
#define MP_AC_UTIL_H

#include "ac_context.h"
#include <string>
#include <android/log.h>
#define __FUNC_PARA__ JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception
#define LOG_TAG "System.out.cpp"
#define LOGE(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

inline bool jsc_object_attach_function(JSContextRef context,JSObjectRef object,char* name,JSObjectCallAsFunctionCallback callback){
    if(!context || !object || !name || !callback)
        return false;
    JSStringRef jsString = ::JSStringCreateWithUTF8CString(name);
    auto _callback =JSObjectMakeFunctionWithCallback(context,jsString,callback);
    JSObjectSetProperty(context,object,jsString,_callback,kJSClassAttributeNone, nullptr);
    ::JSStringRelease(jsString);
    return true;
}

inline std::string jsvalue_to_json_cstr(JSContextRef context,JSValueRef value){
    if(!context || !value)return "";
    auto js_str = ::JSValueCreateJSONString(context,value,0, nullptr);
    if(!js_str)return "";
    std::string c_str_;
    size_t max_size = ::JSStringGetMaximumUTF8CStringSize(js_str);
    if(max_size>0){
        char buffer_byte[max_size] ;
        size_t write_size = ::JSStringGetUTF8CString(js_str,buffer_byte,max_size);
        c_str_= std::string(buffer_byte,write_size-1);
    }
    ::JSStringRelease(js_str);
    return c_str_;
}


inline std::string jsc_value_to_cstr(JSContextRef context, JSValueRef value) {
    if (!value || !context) { return ""; }

    JSStringRef js_str = ::JSValueToStringCopy(context, value, nullptr);
    if (!js_str) {
        return "";
    }

    std::string c_str;
    size_t max_size = ::JSStringGetMaximumUTF8CStringSize(js_str);
    if (0 < max_size) {
        char str_buffer[max_size];
        size_t write_size =
                ::JSStringGetUTF8CString(js_str, &(str_buffer[0]), max_size);
        c_str = std::string(&(str_buffer[0]), write_size -1);
    }
    ::JSStringRelease(js_str);

    return c_str;
}


inline void check_jsc_exception(JSContextRef context, JSValueRef value) {
    if (!value || !context) {
        return;
    }
    auto line = ::JSStringCreateWithUTF8CString("line");
    auto path = ::JSStringCreateWithUTF8CString("sourceURL");
    auto obje = ::JSValueToObject(context, value, nullptr);
    auto js_value_line = ::JSObjectGetProperty(context, obje, line, nullptr);
    auto js_value_file = ::JSObjectGetProperty(context, obje, path, nullptr);
    auto c_line = jsc_value_to_cstr(context, js_value_line);
    auto c_path = jsc_value_to_cstr(context, js_value_file);
    auto c_info = jsc_value_to_cstr(context, value);
    LOGE("JSError:%s %s %s\n",c_line.c_str(),c_path.c_str(),c_info.c_str());
    ::JSStringRelease(line); ::JSStringRelease(path);
}
#endif //MP_AC_UTIL_H
