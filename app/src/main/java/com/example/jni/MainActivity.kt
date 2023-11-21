package com.example.jni

import android.app.Activity
import android.app.ActivityManager
import android.opengl.GLSurfaceView
import android.os.Build
import android.os.Bundle
import android.widget.Toast


class MainActivity : Activity() {
    private var glSurfaceView: GLSurfaceView? = null
    private var rendererSet = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        glSurfaceView = GLSurfaceView(this)
        glSurfaceView!!.setEGLConfigChooser(8, 8, 8, 8, 16, 0)
        glSurfaceView!!.setRenderer(RendererWrapper(this))
        rendererSet = true
        setContentView(glSurfaceView)
    }

    override fun onPause() {
        super.onPause()
        if (rendererSet) {
            glSurfaceView!!.onPause()
        }
    }

    override fun onResume() {
        super.onResume()
        if (rendererSet) {
            glSurfaceView!!.onResume()
        }
    }
}