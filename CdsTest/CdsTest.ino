//--------------------------------------------------------------------------------
// Cdsセンサテストスケッチ
// [CdsTest.ino]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
//
// http://maison-dcc.sblo.jp/ http://dcc.client.jp/ http://ayabu.blog.shinobi.jp/
// https://twitter.com/masashi_214
//
// DCC電子工作連合のメンバーです
// https://desktopstation.net/tmi/ https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#include "cds.h"

// 1-GND
// 2-AIN1->A3
// 3-AIN2->A4
// 4-5V
// 5-
// 6-
// 7-
// 8-

unsigned long PreviosTime = 0;
char a,b;

Cds CdsA0(0,2,200,200);
Cds CdsA1(1,2,200,200);

void setup()
{
  Serial.begin(115200);
  Serial.println("cds test program");
  PreviosTime = millis();
}
void loop()
{
//  static Cds CdsA0(0,2,200,200);
//  static Cds CdsA1(1,2,200,200);

  if( (millis() - PreviosTime ) >= 100 ){  // 1000:1000msec 前回から1000ms経過したかチェック
    PreviosTime = millis();
    a = CdsA0.statechk(LOW);
    b = CdsA1.statechk(LOW);

//char temp[20];
//sprintf(temp,"A0:%d , A1:%d",a,b);
//Serial.println(temp);
 
    if(a==HIGH)
      CdsA0.Reset();

      if(b==HIGH)
      CdsA1.Reset();
  }
}
