#!/bin/bash

base_dir=$(cd "`dirname "0"`" && pwd)
in="$base_dir/djinni/greeter.djinni"
cpp_out="$base_dir/android/Greeter/app/src/main/cpp/djinni"
jni_out="$base_dir/android/Greeter/app/src/main/cpp/djinni/jni"
objc_out="$base_dir/ios/objc"
java_out="$base_dir/android/Greeter/app/src/main/java/com/hsfl/greeter/djinni"
java_package="com.hsfl.greeter.djinni"
objc_prefix="HSFL"

$base_dir/deps/djinni/src/run \
   --java-out $java_out \
   --java-package $java_package \
   --ident-java-field mFooBar \
    \
    --cpp-out $cpp_out \
    --cpp-namespace libgreeter \
    --cpp-optional-template std::experimental::optional \
    --cpp-optional-header "<experimental/optional>" \
    --ident-cpp-enum-type foo_bar \
    \
    --jni-out $jni_out \
    --ident-jni-class NativeFooBar \
    --ident-jni-file NativeFooBar \
    \
    --objc-out $objc_out \
    --objcpp-out $objc_out \
    --objc-type-prefix $objc_prefix \
    \
    --idl "$in"
