#include <iostream>
#include<stdlib.h>
#include <string.h>
#include <Windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<sstream>

/*Definitions*/
#define SCENE 10

using namespace std;

#pragma warning(disable : 4996)

/*Global Variables*/
long int p, q;
char msg[100];
int width = 650, height = 650;
int lineheight = 500;
int linemargin = 500;
int currentheight = 400;
long int  n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
int prime(long int);
void ce();
long int cd(long int);

GLint movement_angle = 0,
packet_angle = 0,
head_angle = 0,
packet_angle1 = 0,
head_angle1 = 0,
packet_angle2 = 0,
head_angle2 = 0,
packet_angle3 = 0,
head_angle3 = 0,
packet_angle4 = 0;
GLdouble mov_speed = 1;
GLint head_angle4 = 0,
packet_angle5 = 0,
head_angle5 = 0,
packet_angle6 = 0,
head_angle6 = 0,
packet_angle7,
head_angle7 = 0,
packet_angle8 = 40;
GLint movement_angle1 = 0, 
arrow_angle = 0, 
rev_arrow_angle = 0, 
phy_header_angle = 0, 
rev_phy_header_angle = 0, 
rev_phy_header_angle1 = 0, 
phy_header_angle1 = 0, 
analog_sig_angle = 0, 
rev_analog_sig_angle = 0;


//enum without a class name or enum name creates constants with values 0, 1, 2, 3, 4 respectively
//https://en.cppreference.com/w/cpp/language/enum
enum {
	FRONTPAGE, ENCRYPTION, ENCRYPTIONINFO, WITHOUTENCRYPTION, EXIT
};


//This is a default font instead  of the array listed below
void* font = GLUT_BITMAP_HELVETICA_12;

/* https://www.opengl.org/resources/libraries/glut/spec3/node76.html */


// This is an array to select fonts while displaying 
void* fonts[] =
{
	GLUT_BITMAP_9_BY_15,         	   //0
	GLUT_BITMAP_TIMES_ROMAN_10,		   //1
	GLUT_BITMAP_TIMES_ROMAN_24,		   //2
	GLUT_BITMAP_HELVETICA_12,		   //3
	GLUT_BITMAP_HELVETICA_10,		   //4
	GLUT_BITMAP_HELVETICA_18,		   //5
	GLUT_BITMAP_8_BY_13,			   //6
};


void* currentfont;

//Function to write on Screen with color as Black
void output(int x, int y, const char* string, int j)
{
	int len, i;
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(fonts[j], string[i]);
}

//Function to write on Screen with color as Yellow
void output2(int x, int y, char* string, int j)
{
	int len, i;
	glColor3f(1.0f, 0.0f, 1.0f);
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(fonts[j], string[i]);
}

//The following two functions are to delay the movement
void delay(void)
{
	int i, j, k;
	for (i = 0; i < 500; i++)
	{
		for (j = 0; j < 1000; j++);
		for (k = 0; k < 15000; k++);
	}
}

void delay1(void)
{
	int i;
	for (i = 0; i < 10000; i++);
}

/*Function to print Front Page*/
void front_page()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glClearColor(0.4f, 0.2f, 0.3f, 1.0f);
	output(200, 650, "SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT", 2);
	output(275, 550, "SUBJECT: COMPUTER GRAPHICS", 5);
	output(345, 500, "A", 5);
	output(310, 450, "MINI PROJECT ON", 5);
	glColor3f(0.30, 1.00, 0.65);
	glBegin(GL_QUADS);										//To create a highlight in the background
	glVertex2f(260, 330);
	glVertex2f(445, 330);
	glVertex2f(445, 380);
	glVertex2f(260, 380);
	glEnd();
	output(305, 350, "RSA ENCRYPTION", 2);
	output(100, 200, "Guide:", 5);
	output(135, 180, "Ms. Megha Rani", 5);
	output(450, 200, "By:", 5);
	output(475, 180, "Niraj R Shetty [4SF18CS095]", 5);
	output(475, 150, "K Samarth N Kamath [4SF18CS055]", 5);
	glColor3f(0.30, 1.00, 0.65);
	glBegin(GL_QUADS);										//To create a highlight in the background
	glVertex2f(300, 30.0);
	glVertex2f(400, 30.0);
	glVertex2f(400, 80.0);
	glVertex2f(300, 80.0);
	glEnd();
	output(305, 50, "->Press S to start", 2);
	glutPostRedisplay();
	glFlush();
	glCallList(SCENE);
	glPopMatrix();
	glutSwapBuffers();
}

/*Display the details that we have entered before*/
void encryptioninfo()
{
	/*To Convert int type variable p and q into string type variables p1 and q1 using sstream*/
	ostringstream str1;
	ostringstream str2;
	str1 << p;
	char* p1 = strdup(str1.str().c_str());
	str2 << q;
	char* q1 = strdup(str2.str().c_str());
	/**/

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	output(200, 550, "The Entered Primes are:", 2);
	output(300, 500, p1 , 2);
	output(400, 500, q1, 2);
	output(200, 400, "The Message is:", 2);
	glColor3f(0.30, 1.00, 0.65);
	glBegin(GL_QUADS);										//To create a highlight in the background
	glVertex2f(260, 330);
	glVertex2f(445, 330);
	glVertex2f(445, 380);
	glVertex2f(260, 380);
	glEnd();
	output(343, 350, msg, 2);
	glColor3f(0.30, 1.00, 0.65);
	glBegin(GL_QUADS);										//To create a highlight in the background
	glVertex2f(200, 30.0);
	glVertex2f(500, 30.0);
	glVertex2f(500, 80.0);
	glVertex2f(200, 80.0);
	glEnd();
	output(240, 50, "->Press W or w to know about RSA Algorithm", 2);
	glutPostRedisplay();
	glFlush();
	glCallList(SCENE);
	glPopMatrix();
	glutSwapBuffers();
}

/*animating the transfer*/
void animation_encryp(void)
{	
	delay();
	if ((arrow_angle += mov_speed) >= 130)                 //This is to move the message 
		arrow_angle = 150;
	if (arrow_angle == 150)
		if ((phy_header_angle += mov_speed) >= 100)        //This is to move the e from left to right
			phy_header_angle = 100;
	if (phy_header_angle == 100)
		//if ((phy_header_angle1 += mov_speed) >= 100)	   //For message Downward
			phy_header_angle1 = 100;
	if (phy_header_angle1 == 100)
		if ((analog_sig_angle += mov_speed) >= 100)        //For cypher Downward
			analog_sig_angle = 100;
	if (analog_sig_angle == 100)
		if ((movement_angle1 += mov_speed) >= 420)         //For Cypher Left to right
			movement_angle1 = 420;
	if (movement_angle1 == 420)
		if ((rev_analog_sig_angle += mov_speed) >= 100)    //For Cypher Upward
			rev_analog_sig_angle = 100;
	if (rev_analog_sig_angle == 100)
		if ((rev_phy_header_angle += mov_speed) >= 200)    //For d to move left
			rev_phy_header_angle = 200;
	if (rev_phy_header_angle == 200)
		if ((rev_phy_header_angle1 += mov_speed) >= 100)   //For message Upwards
			rev_phy_header_angle1 = 100;
	if (rev_phy_header_angle == 200)
		if ((rev_arrow_angle += mov_speed) >= 100)         //For message 
			rev_arrow_angle = 100;
	glutPostRedisplay();
}


//Drawing the computer
void computer()
{
	glColor3f(0.0, 1.0, 0.0);//sender Keyboard
	glBegin(GL_QUADS);
	glVertex2f(55.0, 340.0);
	glVertex2f(145.0, 340.0);
	glVertex2f(150.0, 350.0);
	glVertex2f(60.0, 350.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);//Sender Processor
	glBegin(GL_LINE_LOOP);
	glVertex2f(60.0, 355.0);
	glVertex2f(150.0, 355.0);
	glVertex2f(150.0, 370.0);
	glVertex2f(60.0, 370.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);//Sender Frame
	glBegin(GL_QUADS);
	glVertex2f(75.0, 380.0);
	glVertex2f(135.0, 380.0);
	glVertex2f(135.0, 430.0);
	glVertex2f(75.0, 430.0);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);//Sender Screen
	glBegin(GL_QUADS);
	glVertex2f(80.0, 385.0);
	glVertex2f(130.0, 385.0);
	glVertex2f(130.0, 425.0);
	glVertex2f(80.0, 425.0);
	glEnd();


	glColor3f(0.0, 1.0, 0.0);//Sender Stand
	glBegin(GL_QUADS);
	glVertex2f(90.0, 370.0);
	glVertex2f(120.0, 370.0);
	glVertex2f(120.0, 380.0);
	glVertex2f(90.0, 380.0);
	
	glEnd();
}

//Drawing the computer
void computer_dest()
{
	glColor3f(0.0, 0.0, 1.0);//Receiver keyboard
	glBegin(GL_QUADS);
	glVertex2f(545.0, 525.0);
	glVertex2f(635.0, 525.0);
	glVertex2f(640.0, 535.0);
	glVertex2f(550.0, 535.0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);//Receiver Processor
	glBegin(GL_LINE_LOOP);
	glVertex2f(550.0, 540.0);
	glVertex2f(640.0, 540.0);
	glVertex2f(640.0, 555.0);
	glVertex2f(550.0, 555.0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);//Reciever Frame
	glBegin(GL_QUADS);
	glVertex2f(565.0, 565.0);
	glVertex2f(625.0, 565.0);
	glVertex2f(625.0, 615.0);
	glVertex2f(565.0, 615.0);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);//Reciever Screen
	glBegin(GL_QUADS);
	glVertex2f(570.0, 570.0);
	glVertex2f(620.0, 570.0);
	glVertex2f(620.0, 610.0);
	glVertex2f(570.0, 610.0);
	glEnd();


	glColor3f(0.0, 0.0, 1.0);//Receiver Stand
	glBegin(GL_QUADS);
	glVertex2f(580.0, 555.0);
	glVertex2f(610.0, 555.0);
	glVertex2f(610.0, 565.0);
	glVertex2f(580.0, 565.0);
	
	glEnd();
}

//Drawing the computer
void computer_mid()
{
	glColor3f(1.0, 0.0, 0.0);//Intruder Keyboard
	glBegin(GL_QUADS);
	glVertex2f(315.0, 50.0);
	glVertex2f(405.0, 50.0);
	glVertex2f(415.0, 60.0);
	glVertex2f(325.0, 60.0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);//Intruder Processor
	glBegin(GL_LINE_LOOP);
	glVertex2f(325.0, 65.0);
	glVertex2f(415.0, 65.0);
	glVertex2f(415.0, 80.0);
	glVertex2f(325.0, 80.0);
	glEnd();

	glColor3f(1.0,0.0,0.0);//Intruder Frame
	glBegin(GL_QUADS);
	glVertex2f(340.0, 90.0);
	glVertex2f(400.0, 90.0);
	glVertex2f(400.0, 140.0);
	glVertex2f(340.0, 140.0);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);//Intruder Screen
	glBegin(GL_QUADS);
	glVertex2f(345.0, 95.0);
	glVertex2f(395.0, 95.0);
	glVertex2f(395.0, 135.0);
	glVertex2f(345.0, 135.0);
	glEnd();


	glColor3f(1.0, 0.0, 0.0);//Intruder Stand
	glBegin(GL_QUADS);
	glVertex2f(355.0, 90.0);
	glVertex2f(385.0, 90.0);
	glVertex2f(385.0, 80.0);
	glVertex2f(355.0, 80.0);
	
	glEnd();
}

/*Helper Functions for RSA*/
//https://www.sanfoundry.com/cpp-program-implement-rsa-algorithm/ use this link for code related to RSA encryption and decryption

//To check if the number is a prime
int prime(long int pr)
{
	int i;
	j = sqrt(pr);
	for (i = 2; i <= j; i++)
	{
		if (pr % i == 0)
			return 0;
	}
	return 1;
}

void ce()
{
	int k;
	k = 0;
	for (i = 2; i < t; i++)
	{
		if (t % i == 0)
			continue;
		flag = prime(i);
		if (flag == 1 && i != p && i != q)
		{
			e[k] = i;
			flag = cd(e[k]);
			if (flag > 0)
			{
				d[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
}

//create decryption key
long int cd(long int x)
{
	long int k = 1;
	while (1)
	{
		k = k + t;
		if (k % x == 0)
			return (k / x);
	}
}
//Actual Encryption Happens in this function
void encrypter()
{
	long int pt, ct, key = e[0], k, len;
	i = 0;
	len = strlen(msg);
	while (i != len)
	{
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * pt;
			k = k % n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	cout << "\nTHE ENCRYPTED MESSAGE IS\n";
	for (i = 0; en[i] != -1; i++)
		printf("%c", en[i]);
}

//Decryption Function
void decrypter()
{
	long int pt, ct, key = d[0], k;
	i = 0;
	while (en[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * ct;
			k = k % n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}
	m[i] = -1;
	cout << "\nTHE DECRYPTED MESSAGE IS\n";
	for (i = 0; m[i] != -1; i++)
		printf("%c", m[i]);
}

//To position and call encryptor function
void encrypt(int x, int y, int z)
{
	glRasterPos3i(x, y, z);
	encrypter();
	for (i = 0; en[i] != '\0'; i++)
	{
		glutBitmapCharacter(font, en[i]);
	}
	cout << en << endl;
	glutPostRedisplay();
	glFlush();
}

void cipher()
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glScalef(40, 20, .5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	encrypt(-1, 0, 0);
	glPopMatrix();
}

void cipher2()
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glScalef(40, 20, .5);
	glTranslatef(0, 0, 0);
	glutWireCube(2);
	output(-1, 0, msg, 2);
	glPopMatrix();
}

void message_data()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glScalef(40, 20, .5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	output(-1, 0, msg, 2);
	glPopMatrix();
}

void message_key(void)
{
	ostringstream str1;
	
	str1 << e[0];
	char* p1 = strdup(str1.str().c_str());
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glScalef(20, 20, .5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	output(-1, 0, p1, 2);
	glPopMatrix();
}

void message_key1(void)
{
	ostringstream str2;
	str2 << d[0];
	char* q1 = strdup(str2.str().c_str());

	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glScalef(20, 20, .5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	output(-1, 0, q1, 2);
	glPopMatrix();
}

void decrypt(float x, float y, float z)
{
	glRasterPos3i(x, y, z);
	decrypter();

	for (i = 0; m[i] != -1; i++)
	{
		glutBitmapCharacter(font, (char)m[i]);
	}
	glutPostRedisplay();
	glFlush();
}

void message_data2()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glScalef(40, 20, .5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	decrypt(-1, 0, 0);
	glPopMatrix();
}

void message_data3()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glScalef(40, 20, .5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	output(-1, 0, "ERROR", 2);
	glPopMatrix();
}

void RSAinfo()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	output(150, 525+75, "RSA ENCRYPTION & DECRYPTION", 2);
	
	output(160, 500+75, "RSA(Rivest–Shamir–Adleman) is an algorithm used by modern computers to encrypt and decrypt messages.",0);
	output(160, 485+75, "It is an asymmetric cryptographic algorithm.", 0);
	output(160, 470+75, "Asymmetric means that there are two different keys.", 0);
	output(160, 455+75, "This is also called public key cryptography, because one of the keys can be given to anyone.", 0);
	output(160, 440+75, "The other key must be kept private.",0);
	output(160, 425+75, "The algorithm is based on the fact that finding the factors of a large composite number is difficult:", 0);
	output(165, 410+75, "when the factors are prime numbers, the problem is called prime factorization.",0); 
	output(160, 395+75, "It is also a key pair (public and private key) generator.",0);

	output(160, 365+75, "RSA involves a public key and private key.",0); 
	output(160, 350+75, "The public key can be known to everyone- it is used to encrypt messages.",0);
	output(160, 335+75, "Messages encrypted using the public key can only be decrypted with the private key.",0); 
	output(160, 320+75, "The private key needs to be kept secret.",0); 
	output(160, 305+75, "Calculating the private key from the public key is very difficult.",0);
	output(305, 100, "->Press E or e to send your message", 2);

	glColor3f(0.30, 1.00, 0.65);
	glBegin(GL_QUADS);
	glVertex2f(100, 360);
	glVertex2f(600, 360);
	glVertex2f(600, 190);
	glVertex2f(100, 190);
	glEnd();

	output(150, 500-170, "Begin", 5);
	output(160, 485-170, "1. Choose two prime numbers p and q.", 5);
	output(160, 470-170, "2. Compute n = p * q.", 5);
	output(160, 455-170, "3. Calculate phi = (p - 1) * (q - 1).",5);
	output(160, 440-170, "4. Choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., eand phi(n) are coprime.", 5);
	output(160, 425-170, "5. Calculate d as d ≡ e−1(mod phi(n)); here, d is the modular multiplicative inverse of e modulo phi(n).", 5);
	output(160, 410-170, "6. For encryption, c = me mod n, where m = original message.", 5);
	output(160, 395-170, "7. For decryption, m = c d mod n.", 5);
	output(150, 370-170, "End", 5);
	glutPostRedisplay();
	glFlush();
	glCallList(SCENE);
	glPopMatrix();
	glutSwapBuffers();
	
}

void encryption()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0f, 1.0f, 1.0f);
	output(320, 670, "USING RSA ENCRYPTION", 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glColor3f(0.30, 1.00, 0.65);
	glBegin(GL_QUADS);
	glVertex2f(55, 660);
	glVertex2f(95, 660);
	glVertex2f(95, 635);
	glVertex2f(55, 635);
	glEnd();
	glTranslatef(-30, 200, 0);
	output(90, 440, "Sender", 2);
	computer();
	glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glColor3f(0.30, 1.00, 0.65);
	glBegin(GL_QUADS);
	glVertex2f(570, 650);
	glVertex2f(620, 650);
	glVertex2f(620, 625);
	glVertex2f(570, 625);
	glEnd();
	output(575, 630, "Receiver", 2);
	computer_dest();
	glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glColor3f(0.90, 0.60, 0.20);
	glBegin(GL_QUADS);
	glVertex2f(345, 170);
	glVertex2f(395, 170);
	glVertex2f(395, 145);
	glVertex2f(345, 145);
	glEnd();
	output(350, 150, "Intruder", 2);
	computer_mid();
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);      //Left box where conversion happens
	glPushMatrix();
	glScalef(70, 35, 0.5);
	glTranslatef(1.5, 8, 0);
	glutWireCube(2);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);      //Right box where conversion happens
	glPushMatrix();
	glTranslatef(450, 0, 0);
	glScalef(70, 35, 0.5);
	glTranslatef(1.5, 8, 0);
	glutWireCube(2);
	glPopMatrix();

	if (phy_header_angle1 != 100)
	{
		glPushMatrix();
		glTranslatef(0, -phy_header_angle1, 0);
		glPushMatrix();
		glTranslatef(0, -arrow_angle, 0);
		glTranslatef(0, 150, 0);
		message_data();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(phy_header_angle, 0, 0);
		glTranslatef(-100, 0, 0);
		message_key();
		glPopMatrix();
		glPushMatrix();
	}
	glPushMatrix();
	glTranslatef(movement_angle1, 0, 0);

	if (phy_header_angle1 == 100)
	{
		glPushMatrix();
		if (movement_angle1 >= 420)
		{
			glTranslatef(0, rev_analog_sig_angle, 0);
			
		}
		glTranslatef(0, -analog_sig_angle, 0);
		
		if (rev_analog_sig_angle != 100) {
			cipher();
		}
			
		glPopMatrix();
	}
	glPopMatrix();
	if (rev_analog_sig_angle == 100)
	{
		glPushMatrix();
		glTranslatef(450, rev_phy_header_angle1, 0);
		glPushMatrix();
		glTranslatef(0, rev_arrow_angle, 0);
		glTranslatef(0, 0, 0);
		message_data2();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(rev_phy_header_angle, 0, 0);
		glTranslatef(-10, 0, 0);
		if (rev_phy_header_angle < 200)
			message_key1();
		glPopMatrix();
		glPopMatrix();
	}
	animation_encryp(); 
	glFlush();
	glutSwapBuffers();
}

void myinit()
{
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 700.0, 0.0, 700.0);

}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	front_page();
	glFlush();
	glutSwapBuffers();
}

void key(unsigned char key, int x, int y)
{
	switch (key) {
	case 'S':
	case 's':glutDisplayFunc(encryptioninfo);
		break;
	case 'W':
	case 'w':glutDisplayFunc(RSAinfo);
		break;
	case 'E':
	case 'e':glutDisplayFunc(encryption);
		break;
	case 'q':
	case 'Q':exit(0);
	}
	glutPostRedisplay();
}

/*
static void menu(int mode)
{
	switch (mode) {
	case FRONTPAGE:glutDisplayFunc(front_page);
		break;
	case ENCRYPTIONINFO:glutDisplayFunc(encryptioninfo);
		break;
	case WITHOUTENCRYPTION:glutDisplayFunc(WITHOUTENCRYPTION);
		break;
	case ENCRYPTION:glutDisplayFunc(encryption);
		break;
	case EXIT:exit(0);
	}
	glutPostRedisplay();
}*/

void main(int argc, char** argv)
{

	/*Code to run on Terminal*/
	cout << "\nENTER FIRST PRIME NUMBER\n";
	cin >> p;
	flag = prime(p);
	if (flag == 0)
	{
		cout << "\nWRONG INPUT\n";
		exit(1);
	}
	cout << "\nENTER ANOTHER PRIME NUMBER\n";
	cin >> q;
	flag = prime(q);
	if (flag == 0 || p == q)
	{
		cout << "\nWRONG INPUT\n";
		exit(1);
	}
	cout << "\nENTER MESSAGE\n";
	fflush(stdin);
	cin >> msg;
	for (i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
	n = p * q;
	t = (p - 1) * (q - 1);
	ce();
	cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
	for (i = 0; i < j - 1; i++)
		cout << e[i] << "\t" << d[i] << "\n";


	/*code to run on OpenGL*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(0, 0);
	glClearColor(0.9f, 0.5f, 0.2f, 1.0);
	glutCreateWindow("RSA ENCRYPTION");
	glutKeyboardFunc(key);

	myinit();
	glutDisplayFunc(display);
	/*glutCreateMenu(menu);
	glutAddMenuEntry("Front Page", FRONTPAGE);
	glutAddMenuEntry("ENCRYPTION INFO", ENCRYPTIONINFO);
	glutAddMenuEntry("WITHOUT ENCRYPTION", RSAinfo);
	glutAddMenuEntry("ENCRYPTION", ENCRYPTION);
	glutAddMenuEntry("EXIT", EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	*/
	glutMainLoop();

}