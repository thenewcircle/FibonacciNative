#include <jni.h>
#include <string>
#include <android/log.h>


/* Recursive implementation of the fibonacci algorithm (in a helper function) */
static jlong fib(jlong n) {
    return n <= 0 ? 0 : n == 1 ? 1 : fib(n - 1) + fib(n - 2);
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_marakana_android_fibonaccinative_FibLib_fibNR(JNIEnv *env, jclass type, jlong n) {
    __android_log_print(ANDROID_LOG_DEBUG, "native-lib.cpp", "fibNR(%ld)", n);
    return fib(n);
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_marakana_android_fibonaccinative_FibLib_fibNI(JNIEnv *env, jclass type, jlong n) {
    jlong previous = -1;
    jlong result = 1;
    jlong i;
    __android_log_print(ANDROID_LOG_DEBUG, "native-lib.cpp", "fibNI(%ld)", n);
    for (i = 0; i <= n; i++) {
        jlong sum = result + previous;
        previous = result;
        result = sum;
    }
    return result;
}