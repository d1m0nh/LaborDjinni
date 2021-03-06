// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from greeter.djinni

#include "NativeGreeter.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeGreeter::NativeGreeter() : ::djinni::JniInterface<::libgreeter::Greeter, NativeGreeter>("com/hsfl/greeter/djinni/Greeter$CppProxy") {}

NativeGreeter::~NativeGreeter() = default;


CJNIEXPORT void JNICALL Java_com_hsfl_greeter_djinni_Greeter_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::libgreeter::Greeter>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_hsfl_greeter_djinni_Greeter_createGreeter(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::libgreeter::Greeter::create_greeter();
        return ::djinni::release(::djinni_generated::NativeGreeter::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_hsfl_greeter_djinni_Greeter_00024CppProxy_native_1welcomeFromCpp(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::libgreeter::Greeter>(nativeRef);
        auto r = ref->welcomeFromCpp();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
