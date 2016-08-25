/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
#include "s3e.h"
#include "IwDebug.h"
#include "IwGL.h"
#include "InputScene.h"
#define FRAME_TIME (30.0f / 1000.0f)

bool InitAndSetGL() {
    //Initialise graphics system(s)
    if (!IwGLInit())
    {
        IwTrace(GL, ("IwGLInit failed"));
        return false;
    }

    glViewport(0, 0, IwGLGetInt(IW_GL_WIDTH), IwGLGetInt(IW_GL_HEIGHT));

    glEnable(GL_DEPTH_TEST);
    
    return true;
}

int main()
{
    if (!InitAndSetGL())
        return 1;           //in case when sth went wrong

    
    Assets* assets = new Assets();
    InputScene* inputScene{ new InputScene(*assets) };
    
    while (!s3eDeviceCheckQuitRequest())
    {

        uint64 new_time = s3eTimerGetMs();

        s3ePointerUpdate();

        inputScene->update();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
              
        inputScene->draw();

        IwGLSwapBuffers();

        int yield = (int)(FRAME_TIME * 1000 - (s3eTimerGetMs() - new_time));
        if (yield < 0)
            yield = 0;
        s3eDeviceYield(yield);
    }
    
    delete inputScene;//i have to delete those objects before IWGLTerminate() to avoid context problem
    delete assets; 
    IwGLTerminate();

    return 0;
}
