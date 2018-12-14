
#define In1  A5
#define In2  A1
#define In3  A6
#define In4  A3

#define Pin_ss5  5
#define Pin_ss4  6
#define Pin_ss3  7
#define Pin_ss2  8
#define Pin_ss1  9

#define DO_PHAN_GIAI  255
#define TI_LE         1
#define DELAY         1
typedef enum
{
  giuaLine = 0,
  lechTrai1,
  lechTrai2,
  lechTrai3,
  lechTrai4,
  lechTrai5,
  lechPhai1,
  lechPhai2,
  lechPhai3,
  lechPhai4,
  lechPhai5,
  lechHoanToan
}
eHuongLech;

typedef enum
{
  motorTrai,
  motorPhai,
}
eMotor;

typedef enum
{
  chayToi,
  chayLui
}
ePhuongHuong;

int ss1, ss2, ss3, ss4, ss5, reg, tocDoTam;
eHuongLech huongLech;
void setup() {
  // initialize serial communications at 9600 bps:
  pinMode(Pin_ss1, INPUT);//Set chân cảm biến 1 là input
  pinMode(Pin_ss2, INPUT);//Set chân cảm biến 2 là input
  pinMode(Pin_ss3, INPUT);//Set chân cảm biến 3 là input
  pinMode(Pin_ss4, INPUT);//Set chân cảm biến 4 là input
  pinMode(Pin_ss5, INPUT);//Set chân cảm biến 5 là input
  Serial.begin(9600);
}

void loop()
{
  switch (timHuongLech())
  {
    case giuaLine:  
      if (huongLech >= lechTrai1 && huongLech <= lechTrai5)
        {
        chayMotor(motorTrai, chayToi, tocDo(50));
        delayMicroseconds(2*DELAY);
        }
      else if (huongLech >= lechPhai1 && huongLech <= lechPhai5)
      {
        chayMotor(motorPhai, chayToi, tocDo(150));
        delayMicroseconds(2*DELAY);
      }
      else
      {
        chayMotor(motorTrai, chayToi, tocDo(50));
        chayMotor(motorPhai, chayToi, tocDo(150));

        giamQuanTinh();  
      }
      huongLech = giuaLine;
      break;
    case lechTrai1:
      chayMotor(motorTrai, chayToi, tocDo(45));
      chayMotor(motorPhai, chayToi, tocDo(80));

      giamQuanTinh();
      huongLech = lechTrai1;
      break;
    case lechTrai2:
      chayMotor(motorTrai, chayToi, tocDo(40));
      chayMotor(motorPhai, chayToi, tocDo(80));

      giamQuanTinh();
      huongLech = lechTrai2;
      break;
    case lechTrai3:
      chayMotor(motorTrai, chayToi, tocDo(40));
      chayMotor(motorPhai, chayToi, tocDo(80));

      giamQuanTinh();
      huongLech = lechTrai3;
      break;
    case lechTrai4:
      chayMotor(motorTrai, chayToi, tocDo(40));
      chayMotor(motorPhai, chayToi, tocDo(95));

      giamQuanTinh();
      huongLech = lechTrai4;
      break;
     case lechTrai5:
      chayMotor(motorTrai, chayToi, tocDo(35));
      chayMotor(motorPhai, chayToi, tocDo(95));

      giamQuanTinh();
      huongLech = lechTrai5;
      break;
    case lechPhai1:
      chayMotor(motorTrai, chayToi, tocDo(70));
      chayMotor(motorPhai, chayToi, tocDo(65));

      giamQuanTinh();
      huongLech = lechPhai1;
      break;
    case lechPhai2:
      chayMotor(motorTrai, chayToi, tocDo(70));
      chayMotor(motorPhai, chayToi, tocDo(55));

      giamQuanTinh();
      huongLech = lechPhai2;
      break;
    case lechPhai3:
      chayMotor(motorTrai, chayToi, tocDo(70));
      chayMotor(motorPhai, chayToi, tocDo(50));

      giamQuanTinh();
      huongLech = lechPhai3;
      break;
    case lechPhai4:
      chayMotor(motorTrai, chayToi, tocDo(70));
      chayMotor(motorPhai, chayToi, tocDo(45));

      giamQuanTinh();
      huongLech = lechPhai4;
      break;
    case lechPhai5:
      chayMotor(motorTrai, chayToi, tocDo(70));
      chayMotor(motorPhai, chayToi, tocDo(40));

      giamQuanTinh();
      huongLech = lechPhai5;
      break;
    default:
      switch (huongLech)
      {
        case lechTrai1:
        case lechTrai2:
        case lechTrai3:
        case lechTrai4:
        case lechTrai5:
          chayMotor(motorPhai, chayToi, tocDo(95));
          chayMotor(motorTrai, chayToi, tocDo(35));

          giamQuanTinh();
          break;
        case lechPhai1:
        case lechPhai2:
        case lechPhai3:
        case lechPhai4:
        case lechPhai5:
          chayMotor(motorPhai, chayToi, tocDo(40));
          chayMotor(motorTrai, chayToi, tocDo(70));

          giamQuanTinh();
          break;
        }
      break;
  }
  

}

eHuongLech timHuongLech()
{
  ss1 = digitalRead(Pin_ss1);
  ss2 = digitalRead(Pin_ss2);
  ss3 = digitalRead(Pin_ss3);
  ss4 = digitalRead(Pin_ss4);
  ss5 = digitalRead(Pin_ss5);
  reg = 0b00000;
  reg = ss1 << 4 | ss2 << 3 | ss3 << 2 | ss4 << 1 | ss5;
  //Serial.println(reg, BIN);
  switch (reg)
  {
    case 0b11011:
      return giuaLine;
      break;
    case 0b10001:
      return giuaLine;
      break;
    case 0b10011:
      return lechTrai1;
      break;
    case 0b10111:
      return lechTrai2;
      break;
    case 0b00111:
      return lechTrai3;
      break;
    case 0b01111:
      return lechTrai4;
      break;
     case 0b00011:
      return lechTrai5;
      break;
    case 0b11001:
      return lechPhai1;
      break;
    case 0b11101:
      return lechPhai2;
      break;
    case 0b11100:
      return lechPhai3;
      break;
    case 0b11110:
      return lechPhai4;
      break;
     case 0b11000:
      return lechPhai5;
      break;
    default:
      return lechHoanToan;
      break;
  }
}

void chayMotor(eMotor m, ePhuongHuong phuongHuong, int tocDo)
{
  switch (m)
  {
    case motorTrai:
      {
        switch (phuongHuong)
        {
          case chayToi:
            analogWrite(In4, tocDo);
            analogWrite(In3, 0);
            break;
          case chayLui:
            analogWrite(In4, 0);
            analogWrite(In3, tocDo);
            break;
        }
        //delay(100);
        break;
      }
    case motorPhai:
      {
        switch (phuongHuong)
        {
          case chayToi:
            analogWrite(In2, tocDo);
            analogWrite(In1, 0);
            break;
          case chayLui:
            analogWrite(In2, 0);
            analogWrite(In1, tocDo);
            break;
        }
        //delay(100);
        break;
      }
  }
}

int tocDo(int phanTram)
{
  if (phanTram < 0)
    return 0;
  if (phanTram > 100)
    phanTram = 100;
  tocDoTam =  round((phanTram / 100.0) * DO_PHAN_GIAI * TI_LE);
  Serial.println(tocDoTam);
  return tocDoTam;
}

void giamQuanTinh()
{
  delayMicroseconds(DELAY);
  chayMotor(motorPhai, chayToi, tocDo(0));
  chayMotor(motorTrai, chayToi, tocDo(0));
  delayMicroseconds(DELAY);
}
