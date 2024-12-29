#include "../include/Const.h"

#include <iostream>

using namespace std;

namespace Const
{
  const int MENULENGTH = 3;
  const string welcomeMessage = "Selamat Datang di Sistem Laundry";
  const string dividerEqual = "================================";
  const string dividerHyphen = "--------------------------------";
  const array<string, MENULENGTH> roleMessage = {
      "1. Admin",
      "2. Staff",
      "3. Keluar",
  };
}
