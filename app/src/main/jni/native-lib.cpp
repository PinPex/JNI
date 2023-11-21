#include <jni.h>
#include <GLES2/gl2.h>
#include <GLES/gl.h>

GLfloat a[12] = {
        -1, 1, 0,
        -1, -1, 0,
        1, -1, 0,
        1, 1, 0
};
GLfloat texCoords[8] = {
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f
};
int angle = 0;


extern "C"
JNIEXPORT void JNICALL
Java_com_example_jni_JNIWrapper_onsurfacecreated(JNIEnv *env, jobject thiz) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrthof(-8, 8, -8, 8, -8, 8);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1, 1, 1, 1);
    glClearDepthf(1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_jni_JNIWrapper_onsurfacechanged(JNIEnv *env, jobject thiz, jint width,
                                                 jint height) {
    // TODO: implement onsurfacechanged()
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_jni_JNIWrapper_ondrawframe(JNIEnv *env, jobject thiz) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -1);
    glScalef(5, 2.5, 1);
    glColor4f(1, 1, 1, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);
    angle = (angle == 360) ? 0 : angle + 1;
    glRotatef(angle, -1, -1.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, -1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glRotatef(90, 1, 0, 0);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, -1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}