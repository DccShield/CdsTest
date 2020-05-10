//--------------------------------------------------------------------------------
// Cdsセンサテストスケッチ
// [Cds.h]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
// https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#ifndef CDS_H_
#define CDS_H_

#include <stdio.h>

// 状態基底クラス
class Cds
{
public:
  Cds(char ch , char ct , int LTh, int HTh);
  char statechk( char range );
  void Reset( void );

private:
  int LThreshold;
  int HThreshold;
  int Ain;
  int cnt;
  int cntup;
  char port;
  char state;
  
  static unsigned long PreviosTimer;
  enum{
      ST_INIT = 0,
      ST_MEAS,
      ST_DETECTION,
  };
};

#endif
