//
// Created by xuyunhua on 2018/9/8.
//

#ifndef MP_CONTEXT_T_H
#define MP_CONTEXT_T_H

#include <memory>
#include "include/JavaScript.h"
#include "include/JSBase.h"
#include "include/JSObjectRef.h"

namespace xxx{
    class ac_context : public std::enable_shared_from_this<ac_context> {
    public:
        ac_context();
        ~ac_context();

    public:
        JSGlobalContextRef raw_context;
        JSObjectRef global_ref;
    public:
        char* getValue();
    };
}



#endif //MP_CONTEXT_T_H
