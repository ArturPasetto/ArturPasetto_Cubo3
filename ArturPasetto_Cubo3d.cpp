#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define janela_altura 480
#define janela_largura 640


void reshape(GLsizei largura, GLsizei altura) {
	if (altura == 0) altura = 1; // previne a divisão por zero
	GLfloat aspecto = (GLfloat)largura / (GLfloat)altura;
	glViewport(0, 0, largura, altura);
	glMatrixMode(GL_PROJECTION); // manipulando matriz de projeção
	glLoadIdentity(); // zerando a matriz
	gluPerspective(45, aspecto, 0.1, 100);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // configura fundo sem transparencia
	glEnable(GL_DEPTH_TEST); // alunos devem testar
	glShadeModel(GL_SMOOTH); // acabamento com suavização
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // correcao de perspectiva
}

void keyboard(unsigned char tecla, int x, int y) {

	if (tecla == '\x1B') {
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}



void piramide() {
	glBegin(GL_TRIANGLES);
	// triangulo 1 de 4 frente
	glColor3f(1.0f, 0.0f, 0.0f); // vermelho troca em todos
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// triangulo 2 de 4 direita
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// triangulo 3 de 4 atras
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// triangulo 4 de 4 esquerda
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glEnd();
}

void cubo() {
	glBegin(GL_QUADS);


	//frente
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	//direita
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);


	//atras
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -2.0f);
	glVertex3f(1.0f, 0.0f, -2.0f);

	//esquerda
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(1.0f, 1.0f, -2.0f);
	glVertex3f(1.0f, 0.0f, -2.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 1.0f, -1.0f);

	//baixo
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -2.0f);
	glVertex3f(2.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	//cima
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -2.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glEnd();


}

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // executa a limpeza
	glMatrixMode(GL_MODELVIEW); // operando com a camera de modelos
	// desenho da piramide 3d
	glLoadIdentity();


	glPushMatrix();
	glTranslatef(-1.5f, 0.0f, -6.0f);
	piramide();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(30, 1, 0 , 0);
	cubo();
	glPopMatrix();

	glutSwapBuffers(); // trocar a matriz da tela por esta aqui.
}


int main(int argc, char** argv) {

	glutInit(&argc, argv); // Ligar GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Display com Duplo Buffer
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(50, 50); // Pos. onde surge a janela
	glutCreateWindow("desenho 3d"); // Criar Janela
	glutDisplayFunc(display); // imagem
	glutReshapeFunc(reshape); // config telas
	glutKeyboardFunc(keyboard);
	glutMainLoop(); // loop
	return 0;
}
