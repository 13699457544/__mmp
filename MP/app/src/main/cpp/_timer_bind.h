//
// Created by xuyunhua on 2018/9/8.
//

#ifndef MP_TIMER_BIND_H
#define MP_TIMER_BIND_H

#include <memory>
#include "ac_util.h"
namespace xxx {
    class _timer_bind {
    public:
        _timer_bind(std::shared_ptr<ac_context>,JSObjectRef);
        ~_timer_bind();
    };
}



#endif //MP_TIMER_BIND_H
