package com.example.jni

import android.content.Context
import android.graphics.BitmapFactory
import android.opengl.EGLConfig
import android.opengl.GLSurfaceView
import android.opengl.GLUtils
import javax.microedition.khronos.opengles.GL10


internal class RendererWrapper(var c: Context) : GLSurfaceView.Renderer {
    private fun loadGLTexture(gl: GL10) {
        gl.glGenTextures(1, textures, 0)
        for (i in texture_name.indices) {
            gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[i])
            gl.glTexParameterf(
                GL10.GL_TEXTURE_2D,
                GL10.GL_TEXTURE_MIN_FILTER,
                GL10.GL_LINEAR.toFloat()
            )
            val `is` = c.resources.openRawResource(texture_name[i])
            val bitmap = BitmapFactory.decodeStream(`is`)
            GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bitmap, 0)
            bitmap.recycle()
        }
    }

    override fun onSurfaceCreated(gl: GL10?, config: javax.microedition.khronos.egl.EGLConfig?) {
        gl?.let { loadGLTexture(it) }
        JNIWrapper.onsurfacecreated()
    }

    override fun onSurfaceChanged(gl: GL10, width: Int, height: Int) {
        JNIWrapper.onsurfacechanged(width, height)
    }

    override fun onDrawFrame(gl: GL10) {
        JNIWrapper.ondrawframe()
    }

    companion object {
        var texture_name = intArrayOf(
            R.drawable.lava
        )
        var textures = IntArray(texture_name.size)
    }
}