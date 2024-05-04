//9th June 2023
//QtPy Death Star Plans by Okubo Heavy Industries based on
//3D_Cube for Arduino OLED module by Colin Ord, 9/1/2015


#include <U8g2lib.h>
#include "deathstar.h"
//#include "ArduinoLowPower.h"

void clearOLED();

//The following line will need changing depending on your board type!
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

float tx, nx, p;
float ty, ny, py;
float rot, rotx, roty, rotz, rotxx, rotyy, rotzz, rotxxx, rotyyy, rotzzz;
int i; //0 to 360
int fl, scale; //focal length
int wireframe[800][2];
float vector;
int angle;
int yangle;
int zangle;
float yrot;
float zrot;

float scalefactor = 0;

int originx = 64;
int originy = 32; //32

int fd = 2; //0=orthographic


void setup(void)
{
 u8g2.begin();

 u8g2.firstPage();
 do {
 } while ( u8g2.nextPage() );
}

void draw_vertices(void)
{
  if (rotzzz>0){
  u8g2.drawPixel (rotxxx, rotyyy);
  }
}

void draw_wireframe(void)
{
 
 //equator
 u8g2.drawLine(wireframe[4][0], wireframe[4][1], wireframe[13][0], wireframe[13][1]);
 u8g2.drawLine(wireframe[13][0], wireframe[13][1], wireframe[22][0], wireframe[22][1]);
 u8g2.drawLine(wireframe[22][0], wireframe[22][1], wireframe[31][0], wireframe[31][1]);
 u8g2.drawLine(wireframe[31][0], wireframe[31][1], wireframe[40][0], wireframe[40][1]);
 //u8g2.drawLine(wireframe[40][0], wireframe[40][1], wireframe[49][0], wireframe[49][1]); //centre of super laser
 //u8g2.drawLine(wireframe[49][0], wireframe[49][1], wireframe[58][0], wireframe[58][1]); //centre of super laser
 u8g2.drawLine(wireframe[58][0], wireframe[58][1], wireframe[67][0], wireframe[67][1]);
 u8g2.drawLine(wireframe[67][0], wireframe[67][1], wireframe[76][0], wireframe[76][1]);
 u8g2.drawLine(wireframe[76][0], wireframe[76][1], wireframe[85][0], wireframe[85][1]);
 u8g2.drawLine(wireframe[85][0], wireframe[85][1], wireframe[94][0], wireframe[94][1]);
 u8g2.drawLine(wireframe[94][0], wireframe[94][1], wireframe[103][0], wireframe[103][1]);
 u8g2.drawLine(wireframe[103][0], wireframe[103][1], wireframe[112][0], wireframe[112][1]);
 u8g2.drawLine(wireframe[112][0], wireframe[112][1], wireframe[121][0], wireframe[121][1]);
 u8g2.drawLine(wireframe[121][0], wireframe[121][1], wireframe[130][0], wireframe[130][1]);
 u8g2.drawLine(wireframe[130][0], wireframe[130][1], wireframe[139][0], wireframe[139][1]);
 u8g2.drawLine(wireframe[139][0], wireframe[139][1], wireframe[148][0], wireframe[148][1]);
 u8g2.drawLine(wireframe[148][0], wireframe[148][1], wireframe[157][0], wireframe[157][1]);
 u8g2.drawLine(wireframe[157][0], wireframe[157][1], wireframe[166][0], wireframe[166][1]);
 u8g2.drawLine(wireframe[166][0], wireframe[166][1], wireframe[175][0], wireframe[175][1]);
 u8g2.drawLine(wireframe[175][0], wireframe[175][1], wireframe[4][0], wireframe[4][1]);
 

//super laser inner
 u8g2.drawLine(wireframe[180][0], wireframe[180][1], wireframe[181][0], wireframe[181][1]);
 u8g2.drawLine(wireframe[181][0], wireframe[181][1], wireframe[182][0], wireframe[182][1]);
 u8g2.drawLine(wireframe[182][0], wireframe[182][1], wireframe[183][0], wireframe[183][1]);
 u8g2.drawLine(wireframe[183][0], wireframe[183][1], wireframe[184][0], wireframe[184][1]);
 u8g2.drawLine(wireframe[184][0], wireframe[184][1], wireframe[185][0], wireframe[185][1]);
 u8g2.drawLine(wireframe[185][0], wireframe[185][1], wireframe[186][0], wireframe[186][1]);
 u8g2.drawLine(wireframe[186][0], wireframe[186][1], wireframe[187][0], wireframe[187][1]);
 u8g2.drawLine(wireframe[187][0], wireframe[187][1], wireframe[188][0], wireframe[188][1]);
 u8g2.drawLine(wireframe[188][0], wireframe[188][1], wireframe[189][0], wireframe[189][1]);
 u8g2.drawLine(wireframe[189][0], wireframe[189][1], wireframe[190][0], wireframe[190][1]);
 u8g2.drawLine(wireframe[190][0], wireframe[190][1], wireframe[191][0], wireframe[191][1]);
 u8g2.drawLine(wireframe[191][0], wireframe[191][1], wireframe[192][0], wireframe[192][1]);
 u8g2.drawLine(wireframe[192][0], wireframe[192][1], wireframe[193][0], wireframe[193][1]);
 u8g2.drawLine(wireframe[193][0], wireframe[193][1], wireframe[194][0], wireframe[194][1]);
 u8g2.drawLine(wireframe[194][0], wireframe[194][1], wireframe[180][0], wireframe[180][1]);

 //super laser outer
 u8g2.drawLine(wireframe[195][0], wireframe[195][1], wireframe[196][0], wireframe[196][1]);
 u8g2.drawLine(wireframe[196][0], wireframe[196][1], wireframe[197][0], wireframe[197][1]);
 u8g2.drawLine(wireframe[197][0], wireframe[197][1], wireframe[198][0], wireframe[198][1]);
 u8g2.drawLine(wireframe[198][0], wireframe[198][1], wireframe[199][0], wireframe[199][1]);
 u8g2.drawLine(wireframe[199][0], wireframe[199][1], wireframe[200][0], wireframe[200][1]);
 u8g2.drawLine(wireframe[200][0], wireframe[200][1], wireframe[201][0], wireframe[201][1]);
 u8g2.drawLine(wireframe[201][0], wireframe[201][1], wireframe[202][0], wireframe[202][1]);
 u8g2.drawLine(wireframe[202][0], wireframe[202][1], wireframe[203][0], wireframe[203][1]);
 u8g2.drawLine(wireframe[203][0], wireframe[203][1], wireframe[204][0], wireframe[204][1]);
 u8g2.drawLine(wireframe[204][0], wireframe[204][1], wireframe[205][0], wireframe[205][1]);
 u8g2.drawLine(wireframe[205][0], wireframe[205][1], wireframe[206][0], wireframe[206][1]);
 u8g2.drawLine(wireframe[206][0], wireframe[206][1], wireframe[207][0], wireframe[207][1]);
 u8g2.drawLine(wireframe[207][0], wireframe[207][1], wireframe[208][0], wireframe[208][1]);
 u8g2.drawLine(wireframe[208][0], wireframe[208][1], wireframe[209][0], wireframe[209][1]);
 u8g2.drawLine(wireframe[209][0], wireframe[209][1], wireframe[195][0], wireframe[195][1]);

 //super laser spokes
 u8g2.drawLine(wireframe[180][0], wireframe[180][1], wireframe[195][0], wireframe[195][1]);
 u8g2.drawLine(wireframe[181][0], wireframe[181][1], wireframe[196][0], wireframe[196][1]);
 u8g2.drawLine(wireframe[182][0], wireframe[182][1], wireframe[197][0], wireframe[197][1]);
 u8g2.drawLine(wireframe[183][0], wireframe[183][1], wireframe[198][0], wireframe[198][1]);
 u8g2.drawLine(wireframe[184][0], wireframe[184][1], wireframe[199][0], wireframe[199][1]);
 u8g2.drawLine(wireframe[185][0], wireframe[185][1], wireframe[200][0], wireframe[200][1]);
 u8g2.drawLine(wireframe[186][0], wireframe[186][1], wireframe[201][0], wireframe[201][1]);
 u8g2.drawLine(wireframe[187][0], wireframe[187][1], wireframe[202][0], wireframe[202][1]);
 u8g2.drawLine(wireframe[188][0], wireframe[188][1], wireframe[203][0], wireframe[203][1]);
 u8g2.drawLine(wireframe[189][0], wireframe[189][1], wireframe[204][0], wireframe[204][1]);
 u8g2.drawLine(wireframe[190][0], wireframe[190][1], wireframe[205][0], wireframe[205][1]);
 u8g2.drawLine(wireframe[191][0], wireframe[191][1], wireframe[206][0], wireframe[206][1]);
 u8g2.drawLine(wireframe[192][0], wireframe[192][1], wireframe[207][0], wireframe[207][1]);
 u8g2.drawLine(wireframe[193][0], wireframe[193][1], wireframe[208][0], wireframe[208][1]);
 u8g2.drawLine(wireframe[194][0], wireframe[194][1], wireframe[209][0], wireframe[209][1]);

 
}

void draw_wireframe2(void){
  u8g2.drawLine(wireframe[6][0], wireframe[6][1], wireframe[7][0], wireframe[7][1]);
  u8g2.drawLine(wireframe[7][0], wireframe[7][1], wireframe[8][0], wireframe[8][1]);

  //u8g2.drawLine(wireframe[15][0], wireframe[15][1], wireframe[16][0], wireframe[16][1]);
  //u8g2.drawLine(wireframe[16][0], wireframe[16][1], wireframe[17][0], wireframe[17][1]);

 u8g2.drawLine(wireframe[24][0], wireframe[24][1], wireframe[25][0], wireframe[25][1]);
 u8g2.drawLine(wireframe[25][0], wireframe[25][1], wireframe[26][0], wireframe[26][1]);

 //u8g2.drawLine(wireframe[33][0], wireframe[33][1], wireframe[34][0], wireframe[34][1]);
 //u8g2.drawLine(wireframe[34][0], wireframe[34][1], wireframe[35][0], wireframe[35][1]);

 u8g2.drawLine(wireframe[36][0], wireframe[36][1], wireframe[37][0], wireframe[37][1]);
 u8g2.drawLine(wireframe[37][0], wireframe[37][1], wireframe[38][0], wireframe[38][1]);

 //u8g2.drawLine(wireframe[42][0], wireframe[42][1], wireframe[43][0], wireframe[43][1]);
 //u8g2.drawLine(wireframe[43][0], wireframe[43][1], wireframe[44][0], wireframe[44][1]);

 u8g2.drawLine(wireframe[51][0], wireframe[51][1], wireframe[52][0], wireframe[52][1]);
 u8g2.drawLine(wireframe[52][0], wireframe[52][1], wireframe[53][0], wireframe[53][1]);

 //u8g2.drawLine(wireframe[60][0], wireframe[60][1], wireframe[61][0], wireframe[61][1]);
 //u8g2.drawLine(wireframe[61][0], wireframe[61][1], wireframe[62][0], wireframe[62][1]);

 u8g2.drawLine(wireframe[69][0], wireframe[69][1], wireframe[70][0], wireframe[70][1]);
 u8g2.drawLine(wireframe[70][0], wireframe[70][1], wireframe[71][0], wireframe[71][1]);

 //u8g2.drawLine(wireframe[78][0], wireframe[78][1], wireframe[79][0], wireframe[79][1]);
 //u8g2.drawLine(wireframe[79][0], wireframe[79][1], wireframe[80][0], wireframe[80][1]);

 u8g2.drawLine(wireframe[87][0], wireframe[87][1], wireframe[88][0], wireframe[88][1]);
 u8g2.drawLine(wireframe[88][0], wireframe[88][1], wireframe[89][0], wireframe[89][1]);

 //u8g2.drawLine(wireframe[96][0], wireframe[96][1], wireframe[97][0], wireframe[97][1]);
 //u8g2.drawLine(wireframe[97][0], wireframe[97][1], wireframe[98][0], wireframe[98][1]);

 u8g2.drawLine(wireframe[105][0], wireframe[105][1], wireframe[106][0], wireframe[106][1]);
 u8g2.drawLine(wireframe[106][0], wireframe[106][1], wireframe[107][0], wireframe[107][1]);

 //u8g2.drawLine(wireframe[114][0], wireframe[114][1], wireframe[115][0], wireframe[115][1]);
 //u8g2.drawLine(wireframe[115][0], wireframe[115][1], wireframe[116][0], wireframe[116][1]);

 u8g2.drawLine(wireframe[123][0], wireframe[123][1], wireframe[124][0], wireframe[124][1]);
 u8g2.drawLine(wireframe[124][0], wireframe[124][1], wireframe[125][0], wireframe[125][1]);

 //u8g2.drawLine(wireframe[132][0], wireframe[132][1], wireframe[133][0], wireframe[133][1]);
 //u8g2.drawLine(wireframe[133][0], wireframe[133][1], wireframe[134][0], wireframe[134][1]);

 u8g2.drawLine(wireframe[141][0], wireframe[141][1], wireframe[142][0], wireframe[142][1]);
 u8g2.drawLine(wireframe[142][0], wireframe[142][1], wireframe[143][0], wireframe[143][1]);

 //u8g2.drawLine(wireframe[150][0], wireframe[150][1], wireframe[151][0], wireframe[151][1]);
 //u8g2.drawLine(wireframe[151][0], wireframe[151][1], wireframe[152][0], wireframe[152][1]);

 u8g2.drawLine(wireframe[159][0], wireframe[159][1], wireframe[160][0], wireframe[160][1]);
 u8g2.drawLine(wireframe[160][0], wireframe[160][1], wireframe[161][0], wireframe[161][1]);

 //u8g2.drawLine(wireframe[168][0], wireframe[168][1], wireframe[169][0], wireframe[169][1]);
 //u8g2.drawLine(wireframe[169][0], wireframe[169][1], wireframe[170][0], wireframe[170][1]);

 //u8g2.drawLine(wireframe[177][0], wireframe[177][1], wireframe[178][0], wireframe[178][1]);
 //u8g2.drawLine(wireframe[178][0], wireframe[178][1], wireframe[179][0], wireframe[179][1]);
}

void loop(void)
{
//picture loop

u8g2.setClipWindow(27, 0, 100, 64);
 //zoom in
 angle = 90; 
 while (scalefactor < 0.7){
  u8g2.firstPage();
  u8g2.drawFrame(28,0,72,64);
  do {
    
   for (i = 0; i < death_sphere_vertices_cnt; i++) {

     rot = angle * 0.0174532; //0.0174532 = one degree
//rotateY
    rotz = death_sphere_vertices[i][2] * cos(rot) - death_sphere_vertices[i][0] * sin(rot);
    rotx = death_sphere_vertices[i][2] * sin(rot) + death_sphere_vertices[i][0] * cos(rot);
    roty = death_sphere_vertices[i][1];
//rotateX
    rotyy = roty * cos(rot) - rotz * sin(rot);
    rotzz = roty * sin(rot) + rotz * cos(rot);
    rotxx = rotx;
//rotateZ
    rotxxx = rotxx * cos(rot) - rotyy * sin(rot);
    rotyyy = rotxx * sin(rot) + rotyy * cos(rot);
    rotzzz = rotzz;

//orthographic projection
    rotxxx = rotxxx * scalefactor + originx;
    rotyyy = rotyyy * scalefactor + originy;

//store new vertices values for wireframe drawing
    wireframe[i][0] = rotxxx;
    wireframe[i][1] = rotyyy;
    //wireframe[i][2] = rotzzz;

     draw_vertices();
     
   }
    draw_wireframe();
  if (scalefactor < 0.7 ) scalefactor = scalefactor + 0.02;
  
   } while (u8g2.nextPage());
 }
 //delay(2000);
 
 //turn around
 yangle = 90;
 zangle = 90;
 
 for (angle = 90; angle <= 450; angle = angle +  1) {
  
  do {
    u8g2.firstPage();
    u8g2.drawFrame(28,0,72,64);
   for (i = 0; i < death_sphere_vertices_cnt; i++) {

     rot = angle * 0.0174532; //0.0174532 = one degree
     yrot = yangle * 0.0174532; //0.0174532 = one degree
     zrot = zangle * 0.0174532; //0.0174532 = one degree
     
//rotateY
    rotz = death_sphere_vertices[i][2] * cos(yrot) - death_sphere_vertices[i][0] * sin(yrot);
    rotx = death_sphere_vertices[i][2] * sin(yrot) + death_sphere_vertices[i][0] * cos(yrot);
    roty = death_sphere_vertices[i][1];
//rotateX
    rotyy = roty * cos(rot) - rotz * sin(rot);
    rotzz = roty * sin(rot) + rotz * cos(rot);
    rotxx = rotx;
//rotateZ
    rotxxx = rotxx * cos(zrot) - rotyy * sin(zrot);
    rotyyy = rotxx * sin(zrot) + rotyy * cos(zrot);
    rotzzz = rotzz;

//orthographic projection
    rotxxx = rotxxx * scalefactor + originx;
    rotyyy = rotyyy * scalefactor + originy;

//store new vertices values for wireframe drawing
    wireframe[i][0] = rotxxx;
    wireframe[i][1] = rotyyy;
    //wireframe[i][2] = rotzzz;

     draw_vertices();
     
   }
    draw_wireframe();
  //if (scalefactor < 0.8) scalefactor = scalefactor + 0.05;
  
   } while (u8g2.nextPage());
 }
//up
  yangle = 90;
  zangle = 180;
  
 for (angle = 90; angle <= 180; angle = angle + 1) {
  
  do {
    u8g2.firstPage();
    u8g2.drawFrame(28,0,72,64);
   for (i = 0; i < death_sphere_vertices_cnt; i++) {

     rot = angle * 0.0174532; //0.0174532 = one degree
     yrot = yangle * 0.0174532; //0.0174532 = one degree
     zrot = zangle * 0.0174532; //0.0174532 = one degree
     
//rotateY
    rotz = death_sphere_vertices[i][2] * sin(yrot) - death_sphere_vertices[i][0] * cos(yrot);
    rotx = death_sphere_vertices[i][2] * cos(yrot) + death_sphere_vertices[i][0] * sin(yrot);
    roty = death_sphere_vertices[i][1];
//rotateX
    rotyy = roty * cos(rot) - rotz * sin(rot);
    rotzz = roty * sin(rot) + rotz * cos(rot);
    rotxx = rotx;
//rotateZ
    rotxxx = rotxx * cos(zrot) - rotyy * sin(zrot);
    rotyyy = rotxx * sin(zrot) + rotyy * cos(zrot);
    rotzzz = rotzz;

//orthographic projection
    rotxxx = rotxxx * scalefactor + originx;
    rotyyy = rotyyy * scalefactor + originy;

//store new vertices values for wireframe drawing
    wireframe[i][0] = rotxxx;
    wireframe[i][1] = rotyyy;
    //wireframe[i][2] = rotzzz;

     draw_vertices();
     
   }
    draw_wireframe();
  //if (scalefactor < 0.8) scalefactor = scalefactor + 0.05;
  
   } while (u8g2.nextPage());
 }
    //down
  yangle = 90;
  zangle = 180;
 for (angle = 180; angle >= 130; angle = angle - 1) {
  
  do {
    u8g2.firstPage();
    u8g2.drawFrame(28,0,72,64);
   for (i = 0; i < death_sphere_vertices_cnt; i++) {

     rot = angle * 0.0174532; //0.0174532 = one degree
     yrot = yangle * 0.0174532; //0.0174532 = one degree
     zrot = zangle * 0.0174532; //0.0174532 = one degree
     
//rotateY
    rotz = death_sphere_vertices[i][2] * sin(yrot) - death_sphere_vertices[i][0] * cos(yrot);
    rotx = death_sphere_vertices[i][2] * cos(yrot) + death_sphere_vertices[i][0] * sin(yrot);
    roty = death_sphere_vertices[i][1];
//rotateX
    rotyy = roty * cos(rot) - rotz * sin(rot);
    rotzz = roty * sin(rot) + rotz * cos(rot);
    rotxx = rotx;
//rotateZ
    rotxxx = rotxx * cos(zrot) - rotyy * sin(zrot);
    rotyyy = rotxx * sin(zrot) + rotyy * cos(zrot);
    rotzzz = rotzz;

//orthographic projection
    rotxxx = rotxxx * scalefactor + originx;
    rotyyy = rotyyy * scalefactor + originy;

//store new vertices values for wireframe drawing
    wireframe[i][0] = rotxxx;
    wireframe[i][1] = rotyyy;
    //wireframe[i][2] = rotzzz;

     draw_vertices();
     
   }
    draw_wireframe();
    draw_wireframe2();
  //if (scalefactor < 0.8) scalefactor = scalefactor + 0.05;
  u8g2.drawBox(wireframe[51][0]-scalefactor*5, wireframe[51][1]-scalefactor*5, scalefactor*15, scalefactor*15);
   } while (u8g2.nextPage());
 }

 //zoom in more
  yangle = 90;
  zangle = 180;
  angle = 120; 
 while (scalefactor < 7){
  
  do {
    u8g2.firstPage();
    u8g2.drawFrame(28,0,72,64);
    //u8g2.setClipWindow(27, 0, 100, 64);
   for (i = 0; i < death_sphere_vertices_cnt; i++) {

     rot = angle * 0.0174532; //0.0174532 = one degree
     yrot = yangle * 0.0174532; //0.0174532 = one degree
     zrot = zangle * 0.0174532; //0.0174532 = one degree
     
//rotateY
    rotz = death_sphere_vertices[i][2] * sin(yrot) - death_sphere_vertices[i][0] * cos(yrot);
    rotx = death_sphere_vertices[i][2] * cos(yrot) + death_sphere_vertices[i][0] * sin(yrot);
    roty = death_sphere_vertices[i][1];
//rotateX
    rotyy = roty * cos(rot) - rotz * sin(rot);
    rotzz = roty * sin(rot) + rotz * cos(rot);
    rotxx = rotx;
//rotateZ
    rotxxx = rotxx * cos(zrot) - rotyy * sin(zrot);
    rotyyy = rotxx * sin(zrot) + rotyy * cos(zrot);
    rotzzz = rotzz;

//orthographic projection
    rotxxx = rotxxx * scalefactor + originx;
    rotyyy = rotyyy * scalefactor + originy;

// keep the vertices in the box
    if (rotxxx < 28){rotxxx = 28;};
    if (rotxxx > 100){rotxxx = 100;};
    if (rotyyy < 0){rotyyy = 0;};
    if (rotyyy > 64){rotyyy = 64;};
    
//store new vertices values for wireframe drawing
    wireframe[i][0] = rotxxx;
    wireframe[i][1] = rotyyy;
    //wireframe[i][2] = rotzzz;

     draw_vertices();
     
   }
    draw_wireframe();
    draw_wireframe2();
    u8g2.drawBox(wireframe[51][0]-scalefactor*5, wireframe[51][1]-scalefactor*5, scalefactor*15, scalefactor*15);
  if (scalefactor < 15) scalefactor = scalefactor + 0.5;
  
   } while (u8g2.nextPage());
 }
  u8g2.firstPage();
  u8g2.drawBox(28,0,72,64);

  //Zoom in on the grid

  for (int j = 1; j<32; j=j+2){
    for (int i = j;i<32; i=i+2*j){

    u8g2.drawFrame(28,0,72,64);

    u8g2.drawLine(64,0,64,32); 
  

    u8g2.drawLine(28,31+i,99,31+i);
    u8g2.drawLine(28,33-i,99,33-i);
    u8g2.drawLine(63+i,0,63+i,64);
    u8g2.drawLine(65-i,0,65-i,64);
    }
  u8g2.nextPage();

  delay(100);

u8g2.clearBuffer();


}
/* do{
    
  for (int lg = 0; lg < 72; lg=lg+1) {
  for (int vl = 28; vl < 100; vl=vl+lg) {
    u8g2.drawLine(vl,0,vl,64);
    }
   for (int hl = 0; hl < 64; hl=hl+lg) {
    u8g2.drawLine(28,hl,100,hl);
    } 
    u8g2.nextPage();
    
    } 
  }while (u8g2.nextPage());
  
 */ 
  
delay(1000);

u8g2.setMaxClipWindow();
u8g2.nextPage();
delay(2000);
 scalefactor = 0;
  clearOLED();
  delay(2000);
  u8g2.clearBuffer();
    u8g2.setDrawColor(1);
    u8g2.drawBox(0,0,128,64);
    u8g2.sendBuffer();
    delay(100);
    u8g2.setDrawColor(0);
    u8g2.clearBuffer();
    u8g2.drawBox(0,0,128,64);
    u8g2.sendBuffer();
    delay(500);
    //cursor flash
    for (int i = 0; i < 3; i++) {
    
    u8g2.setDrawColor(1);
    u8g2.clearBuffer();
    u8g2.drawBox(1,1,3,5);
    u8g2.sendBuffer();
    delay(300);
    
    u8g2.clearBuffer();
    u8g2.setDrawColor(0);
    u8g2.drawBox(1,1,3,5);
    u8g2.sendBuffer();
    delay(300);
    }
   
    u8g2.setDrawColor(1);
    u8g2.clearBuffer();
}

void clearOLED(){
    u8g2.firstPage();  
    do {
    } while( u8g2.nextPage() );

}

void explode(){

  
}
