//
// Created by xuyunhua on 2018/9/8.
//

#include "console.h"

using namespace xxx;
console::console(std::shared_ptr<ac_context>context, JSObjectRef object) {
    if(!context->raw_context || !object)return ;
    auto raw_context_ = context->raw_context;
    JSObjectRef console_object = ::JSObjectMake(raw_context_, nullptr, nullptr);
    JSStringRef str_ = ::JSStringCreateWithUTF8CString("console");
    ::JSObjectSetProperty(raw_context_,object,str_,console_object,kJSPropertyAttributeNone, nullptr);
    ::JSStringRelease(str_);
    ::JSValueProtect(raw_context_,console_object);
    jsc_object_attach_function(raw_context_,console_object,"log",[](__FUNC_PARA__)->JSValueRef{
        if(!ctx || !thisObject )return nullptr;
        if(argumentCount<1)return nullptr;
        auto c_str = jsvalue_to_json_cstr(ctx,arguments[0]);
        LOGE("JSLOG :%s\n ",c_str.c_str());
        printf("c_printf : %s\n",c_str.c_str());
        return nullptr;
    });
}

console::~console() {

}