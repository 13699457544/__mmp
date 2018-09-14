//
// Created by xuyunhua on 2018/9/8.
//

#ifndef MP_AC_ISOLATE_H
#define MP_AC_ISOLATE_H

#include "ac_context.h"
#include "console.h"
namespace xxx{
    class ac_isolate :public std::enable_shared_from_this<ac_isolate>{
    public:
        ac_isolate();
        ~ac_isolate();

    public:
        std::shared_ptr<ac_context> js_context;
    public:
        void build();
        void evalute(char*);
    public:
        std::shared_ptr<console>    console_;
    };
}



#endif //MP_AC_ISOLATE_H
