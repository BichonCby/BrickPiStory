#ifndef __Remote_h__
#define __Remote_h__

#define STREMOTE_WAITINI 1
#define STREMOTE_WAIT_RECEIVE 2
#define STREMOTE_WAIT_SEND 3

// les identifiants de trame
#define ID_INFO 0x01
#define ID_ORDERMOVE 0x02
#define ID_ORDERACT 0x03
#define ID_ORDERPOS 0x04
//#define ID_CALSET 0x0A
#define ID_CALGET 0x0B
//#define ID_CALWRITE 0x0C
#define ID_PARAM 0x0D
#define ID_BUTTON		0x0E
#define ID_POSITION 0x10
#define ID_ASSERV 0x11
#define ID_ROBOT 0x12
#define ID_ACTION 0x13
#define ID_DETECTION 0x14
#define ID_IA 0x15
#define ID_SENSORS 0x16
#define ID_MOTORS 0x17
#define ID_EMUL 0x18
#define ID_OBSTACLE		0x50
#define ID_ACK 0x90
#define ID_NACK 0x91

// les réponses de la trame Ack
#define ACK_OK 0
#define ACK_BAD_VERSION 1
#define ACK_IMPOSSIBLE 2
#define ERR_VERSION 0x03 // mauvaise version du robot
#define ERR_SIZE_FRAME 0x04 // mauvaise taille de trame
#define ERR_BAD_ID 0x05 // mauvais identifiant de trame
#define ERR_PARAM_REQ 0x06 // erreur de requete liée aux paramètres
#define ERR_BAD_MOVE 0x07 // mauvais type de déplacement
#define ERR_PARAM_NAME 0x08 // mauvais nom de paramètre

class Remote{
public:
Remote(void); // constructeur
void threadRemote();
private:
int decodeFrame();
int encodeFrame(char id,char err=0);// on va mettre dans stWrite le contenue de la trame id
char checkSum();
int stRemote; // etat de la machine de lecture/écriture
char strRead[500]; // ça fait beaucoup
char strWrite[20];
int sizeWrite;
int sizeRead;
float calibf;
};

#endif
