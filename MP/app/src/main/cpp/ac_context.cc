//
// Created by xuyunhua on 2018/9/8.
//

#include "ac_context.h"

using namespace xxx;

ac_context::ac_context() {
    static JSClassDefinition jclass_ref ={
            0,                          // version
            kJSClassAttributeNone,      // attributes
            "",                         // class name
            0,                          // parentClass
            0,                          // staticValues
            0,                          // staticFunctions
            0,                          // Initialize
            0,                          // Finalize
            0,                          // has Property
            0,                          // get Property
            0,                          // set Property
            0,                          // delete Property
            0,                          // getPropertyNames
            0,                          // callAsFunction
            0,                          // hasInstance
            0,                          // callAsConstructor
            0                           // convertToType
    };
    JSClassRef jsClass = ::JSClassCreate(&jclass_ref);
    raw_context = JSGlobalContextCreate(jsClass);
    ::JSClassRelease(jsClass);
    if(raw_context != nullptr){
        auto str = ::JSStringCreateWithUTF8CString("MP");
        auto global_obj = ::JSContextGetGlobalObject(raw_context);
        ::JSObjectSetProperty(raw_context,global_obj,str,global_obj,kJSPropertyAttributeReadOnly,
                              nullptr);
        ::JSStringRelease(str);
        global_ref = global_obj;
        ::JSValueProtect(raw_context,global_ref);
    }
}


ac_context::~ac_context() {
    if(raw_context && global_ref){
        ::JSValueUnprotect(raw_context,global_ref);
    }
    if(raw_context){
        ::JSGlobalContextRelease(raw_context);
    }
}

char* ac_context::getValue() {
    return "this is javascript global object";
}