#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QGLWidget>
#include "math.h"
#include "QtGui/QMouseEvent"
#include "iostream"
#include "QTimer"
using namespace std;


class mywidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit mywidget(QWidget *parent = 0);

signals:

public slots:
    void slot1(){

    }


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    /*---- environment ---------*/
    float View_Volume_Len;
    float Camera_Pos_X;
    float Camera_Pos_Y;
    float Camera_Pos_Z;

    /*---- color ---------*/
    float COLOR_BLACK[4];  //black
    float COLOR_WHITE[4];  //white
    float COLOR_RED[4];  //red
    float COLOR_YELLOW[4];  //yellow
    float COLOR_GREEN[4];  //green
    float COLOR_BLUE[4];  //blue
    float COLOR_ORANGE[4];  //orange

    /*---- math ---------*/
    float PI;

    /*---- letter X,Y,Z ---------*/
    float X_Y_Z_LEN;  //X Y Z三个字母的的边长

    /*---- axis ---------*/
    float AXIS_WIDTH;  //the width of axis
    float AXIS_LEN;  //坐标轴正部分长度
    float n_pyramid_r;  //圆锥体底部的正多边形的半径
    float n_pyramid_h;  //圆锥体的高度

    /*---- cube ---------*/
    float COLOR_OF_CUBE[9][4][4];  //储存二阶魔方顔色信息
    float CUBE_PER_ROTATE_ANGEL;  //每次旋转的角度
    float CUBE_NOW_ROTATE_ANGEL;  //当前旋转的角度
    float A_CUBE_LEN;  //二阶魔角块的边长
    float A_CUBE_LINE_WIDTH;

    /*---- rotation ---------*/
    int WHICH_ROTATION;  //1,2,3:up,front,right
    int ROTATION_SPEED;

    /*---- mouse ---------*/
    bool mouseLeftDown;
    float mouseX, mouseY;
    float AngleX, AngleY;




    void init();

    void typeXYZ();
    void draw_n_pyramid(int n);
    void xyzAxis(void);

    void q1(int x,int y,float color[4]);  //give a color to a face.
    void colorInit(void);  //initialize the color the MagicCube
    void draw_a_cube_face(int whichFace, int kind);  //kind[1,2:line,quads]
    void draw_a_cube(float c_up[4],float c_down[4],float c_front[4],float c_back[4],float c_left[4],float c_right[4]);
    void draw_MagicCube(int ope,float angel);  //ope[1,2,3:up,front,right]

    void tempToA(float temp[4], int x, int y);  // move temp -> color(x,y)
    void ATotemp(int x, int y, float temp[4]);
    void AToA(int x1, int y1, int x2, int y2);  // move color(x1,y1) -> color(x2,y2)
    void a_up_90_degree_color_change();
    void a_front_90_degree_color_change();
    void a_right_90_degree_color_change();
    void a_90_degree(int angel);
    void a_180_degree(int angel);
    void a_minus_90_degree(int angel);
    void rot1(int kind);  //rotate 90 degrees   [1,2,3 : up,front,right]
    void rot2(int kind);  //rotate 180 degrees   [1,2,3 : up,front,right]
    void rot3(int kind);  //rotate -90 degrees   [1,2,3 : up,front,right]

};

#endif // MYWIDGET_H
