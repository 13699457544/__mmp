//
// Created by xuyunhua on 2018/9/8.
//

#include "ac_isolate.h"
using namespace xxx;

ac_isolate::ac_isolate() {
    js_context = std::make_shared<ac_context>();
    ::JSObjectSetPrivate(js_context->global_ref,this);
}

void ac_isolate::build() {
    console_ = std::make_shared<console>(js_context,js_context->global_ref);
}

void ac_isolate::evalute(char * js) {
    if(!js_context || !js) return;
    JSStringRef js_ = ::JSStringCreateWithUTF8CString(js);
    JSValueRef evaluate_exception = nullptr;
    ::JSEvaluateScript(js_context->raw_context,js_,0,0,0, &evaluate_exception);
    if(evaluate_exception){
        check_jsc_exception(js_context->raw_context,evaluate_exception);
        printf("js evalutate error");
    }
}

ac_isolate::~ac_isolate() {
    ::JSObjectSetPrivate(js_context->global_ref, nullptr);
}