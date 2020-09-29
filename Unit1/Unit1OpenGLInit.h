#ifndef UNIT1OPENGLINIT_H
#define UNIT1OPENGLINIT_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>

//P12：1.5.2：OpenGL的初始化过程
//QOpenGLWidget渲染OpenGL场景
//QOpenGLFunctions封装OpenGL的API，Core核心模式，Compatibility模式可以用一些固定管线的API
class Unit1OpenGLInit : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core
{
    Q_OBJECT
public:
    //继承构造函数
    using QOpenGLWidget::QOpenGLWidget;
    ~Unit1OpenGLInit();

protected:
    //QOpenGLWidget提供了三个虚函数接口：
    //设置OpenGL资源和状态。在第一次调用resizeGL或paintGL之前被调用一次
    void initializeGL() override;
    //渲染OpenGL场景，每当需要更新小部件时使用
    void paintGL() override;
    //设置OpenGL视口、投影等，每当尺寸大小改变时调用
    void resizeGL(int width, int height) override;

private:
    //顶点数组对象
    GLuint VAOs[1];
    //缓存对象
    GLuint Buffers[1];
    //着色器程序对象
    GLuint shaderProgram;
};

#endif // UNIT1OPENGLINIT_H
