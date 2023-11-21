package com.example.jni

object JNIWrapper {
    init {
        System.loadLibrary("native-lib")
    }

    external fun onsurfacecreated()
    external fun onsurfacechanged(width: Int, height: Int)
    external fun ondrawframe()
}