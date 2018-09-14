//
// Created by xuyunhua on 2018/9/8.
//

#include "_timer_bind.h"
using namespace xxx;
_timer_bind::_timer_bind(std::shared_ptr<ac_context> context, JSObjectRef object) {
    if(!context || !object)return ;
    auto context_ref = context->raw_context;
    jsc_object_attach_function(context_ref,object,"set_timeout",[](__FUNC_PARA__)->JSValueRef {

    });
}