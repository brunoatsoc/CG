#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265359 //Valor de PI para ajudar a fazer o desenho da bolinha
#define RADIUS 0.1 //Raio que a bolinha vai ter
#define SPEED 0.05 //Velocidade da bolinha

//Onde a bolinha vai ser criada na janela
float circleX = 0.0; //Posição em X
float circleY = 0.0; //Posição em Y

//Protótipo das funções
void display();
void moveCircle(int k, int x, int y);
void initWindow();

/*
    Projeto de Computação Grafica de Flavia Alessandra Santos De Jesus e Bruno Santos Costa
    Este projeto mostra uma bolinha na tela onde você pode movimenta-la para cima, baixo, esquerda e direita

    Para compilar pelo terminal do linux você deve usar "gcc circle.c -o circle -lGL -lGLU -lglut -lm"
    Para executar pelo terminal do linux você deve usar "./circle"
*/
//Função principal
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Move Circle");
    initWindow();
    glutDisplayFunc(display);
    glutSpecialFunc(moveCircle);
    glutMainLoop();

    return 0;
}//Fim main

//Função para criar a bolinha
void display(){
    float i;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0); //Cor da bolinha

    glBegin(GL_POLYGON); //GL_POLYGON serve para ela ser uma bolinha preenchida

    //Laço de repetição para gerar o desenho da bolinha
    for(i = 0; i < 2 * PI; i += 0.1){
        glVertex2f(circleX + RADIUS * cos(i), circleY + RADIUS * sin(i));
    }

    glEnd(); //Fim da criação da bolinha

    glFlush();
}//Fim display

//Função paramover a bolinha na tela com base nos direcionais do teclado
//Todos os ifs dentro do switch case servem para quando a bolinha chegar na borda na tela
//ela poder voltar para a outra extremidade da tela
//Os cases são para incrementar ou decrementar a posição da bolinha em uma direção
void moveCircle(int k, int x, int y){
    switch(k){
        case GLUT_KEY_UP:
            circleY += SPEED;

            if(circleY >= 1.0){
                circleY = -1.0;
            }

            break;
        case GLUT_KEY_DOWN:
            circleY -= SPEED;

            if(circleY <= -1.0){
                circleY = 1.0;
            }

            break;
        case GLUT_KEY_LEFT:
            circleX -= SPEED;

            if(circleX <= -1.0){
                circleX = 1.0;
            }

            break;
        case GLUT_KEY_RIGHT:
            circleX += SPEED;

            if(circleX >= 1.0){
                circleX = -1.0;
            }

            break;
    }

    glutPostRedisplay(); //Essa parte faz uma solicitação para a janela ser redesenhada
}//Fim moveCircle

//Função para iniciar as cores da janela
void initWindow(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); //Define o espaço da tela onde vão ser desenhada a bolinha
}//Fim initWindow