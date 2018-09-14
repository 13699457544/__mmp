//
// Created by xuyunhua on 2018/9/8.
//

#ifndef MP_CONSOLE_H
#define MP_CONSOLE_H

#include <memory>
#include "ac_util.h"

namespace xxx{
    class console {
    public:
        console(std::shared_ptr<ac_context>,JSObjectRef);
        ~console();
    };
}



#endif //MP_CONSOLE_H
