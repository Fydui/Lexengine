﻿#ifndef BASIC_H
#define BASIC_H

#include <QWidget>
#include <QDesktopWidget>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include "item.h"
//窗口固定大小 安卓自适应 等比例缩放(窗口与窗口内) 等比例缩放(窗口内) 自由缩放 
enum WindowType{Fix, Android, Scale,ScaleIn,Free,Debug}; 

//这个类是比较底层的一些基本管理 他们会在程序运行的时候首先运行 你可以在Basic类中自定义自己的需求
class Basic : public QWidget
{
   Q_OBJECT
    

    
public:
    Basic(QWidget *parent = nullptr);
    //Basic(WindowType t = WindowType::ScaleIn , QWidget *parent = nullptr);
    ~Basic();
    void addItem(Item *i);
    void getScreenPara();            //获得窗口参数
    void setWindowSize(int w, int h);//设置窗口大小
    QPoint getWindowSize();
    void setFixed(WindowType s = WindowType::Fix); //在Windows固定窗口大小与Android全屏自适应之间切换 默认固定
    Item* addItem(QString path, int x=0, int y=0, QString fun="");    
    WindowType getFixedValue();
    void addScene(Scene &s);
    void removeItem(Item &i);
    void removeItem(Item *i);
    void resizeEvent(QResizeEvent * event);    
    void timerEvent(QTimerEvent* event);
    int judgeWidthRatio();  //判断当前窗口宽是否符合比例
    int judgeHeightRatio(); //判断当前窗口高是否符合比例
    
private:
    WindowType windowType;    //当前模式
    View  view;
    Scene  scene;
   
    
    QString titleName = "新项目";             //窗口标题的名字
    int windowHeight= 720;        //窗口的大小
    int windowWidth = 1280;   
    int lastHeight; 
    int lastWidth;
    int screenWindowHeight;          //可用桌面的大小
    int screenWindowWidth;
    int deskWidth;                   //单块屏幕总大小
    int deskHeight;
    int timerEventFlag= 0;
    int viewLastW = 0;
    int viewLastH = 0;
    QString prePath = ""; //安卓下的预路径 请在sdcard下自建MengDieOBJ梦蝶工程文件夹 将包放在该目录下
};

#endif // BASIC_H
