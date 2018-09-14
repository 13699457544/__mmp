#include <jni.h>
#include <string>
#include "ac_isolate.h"
using namespace xxx;
extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_xuyunhua_miniprogram_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {



    std::string hello = "Hello from C++";
    return env->NewStringUTF("hello from c++");
}

extern "C"  JNIEXPORT jboolean

JNICALL
Java_com_example_xuyunhua_miniprogram_NativeCall_executor(JNIEnv *env,jobject object,jstring str,jobject json,jobject call){
    if(object == nullptr || json == nullptr){
        return false;
    }
    jclass jcs = env->GetObjectClass(object);

    // parser json and call function with params of json result
    const char* event_t = env->GetStringUTFChars(str, false);
    std::shared_ptr<ac_isolate> isolate_ = std::make_shared<ac_isolate>();
    isolate_->build();
    isolate_->evalute("console.log('xuyunhua@iqiyi.com')");
    jclass call_jcs = env->GetObjectClass(call);
    jmethodID success_id = env->GetMethodID(call_jcs,"onSucess","(Ljava/lang/String;)V");
    jstring s_msg = env->NewStringUTF("onSucess");
    env->CallVoidMethod(call,success_id,s_msg);
    return true;
}
