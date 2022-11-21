#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MuSoenMath.h"

#pragma comment(lib, "OpenGL32")
using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;

float objectAngle = 0;
float objectScale = 1;

enum ScaleTrigger { INCREASE, DECREASE };
ScaleTrigger trigger;

struct Vertex
{
    vec3 pos;
    float r, g, b, a;
};

struct Transform
{
    mat3 translate;
    mat3 scale;
    mat3 rotation;
};



Vertex star[5];                     // static mesh
Vertex transformedStar[5];          //화면에 그릴 오망성
Vertex circle[360];                 // static mesh 
Vertex transformedCircle[360];      // 화면에 그려질 원

Transform transform;                //world 행렬이 될 transform

void Init();
void Update();
void Release();
int main(void);

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    //object생성부
     /// Star(오망성) 생성
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {

        star[i].pos.x(-sin(radians(theta)) * 0.5f);
        star[i].pos.y(cos(radians(theta)) * 0.5f);
        star[i].pos.z(1.0f); 


        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;


        transformedStar[i] = star[i];

        i++;
    }

    // 원 생성
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.x(-sin(radians((float)theta)) * 0.5);
        circle[theta].pos.y(cos(radians((float)theta)) * 0.5);
        circle[theta].pos.z(1.0f);

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }


    //트랜스폼 초기화 (기본형 제공)
    transform.translate = mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
    transform.rotation = mat3(
        cos(radians(0.0f)), -sin(radians(0.0f)), 0,
        sin(radians(0.0f)), cos(radians(0.0f)), 0,
        0, 0, 1
    );
    transform.scale = mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );

    trigger = INCREASE;
}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        transform.translate += mat3(
            0, 0, 0,
            0, 0, 0,
            0.001, 0, 0
        );

        objectAngle += 1.0f;
        transform.rotation = mat3(
            std::cos(radians(objectAngle)), -std::sin(radians(objectAngle)), 0,
            std::sin(radians(objectAngle)), std::cos(radians(objectAngle)), 0,
            0, 0, 1
        );

        if (trigger == INCREASE)
        {
            transform.scale += mat3(
                0.01, 0, 0,
                0, 0.01, 0,
                0, 0, 0
            );
        }
        else
        {
            transform.scale -= mat3(
                0.01, 0, 0,
                0, 0.01, 0,
                0, 0, 0
            );

        }

        if (transform.scale.val[0][0] >= 1.3f)
        {
            trigger = DECREASE;
        }
        else if (transform.scale.val[0][0] <= 0.8f)
        {
            trigger = INCREASE;
        }


        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = circle[i].pos * transform.scale * transform.rotation * transform.translate ;
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = star[i].pos * transform.scale * transform.rotation * transform.translate ;
        }

        //색 초기화
        glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //선두께
        glLineWidth(7.0f);

        //오망성 그리기
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x(), transformedStar[a].pos.y(), 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x(), transformedStar[a].pos.y(), 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x(), transformedStar[a].pos.y(), 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x(), transformedStar[a].pos.y(), 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x(), transformedStar[a].pos.y(), 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x(), transformedStar[a].pos.y(), 0.0f);
        glEnd();

        //원그리기
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.x(), transformedCircle[theta].pos.y(), 0.0f);
        }
        glEnd();



        //화면 스왑
        glfwSwapBuffers(window);
        glfwPollEvents();

        //렌더시간 측정
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));

        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;

    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
}