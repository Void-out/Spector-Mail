#include <iostream>
#include <string>
#include <vector>
#include <functional>
//buffer for templates with any kind vect of variable
#include "_buffer.h"
//include functions to be used for displaying data and features in nav-menu
#include "_func_utills.h"

#define MAX_SIZE 20

using namespace std;

class SimpleRender{
 public:
  const max_vect = MAX_SIZE;

 private:
  enum _Structure{
    TextBox = 0,
    NoSpacingTextBox = 1

};
  public:
    SimpleRender(int Element, vector<int> Param)
  : Element(RenderElement),
    Param(ParamType){};

  //operator <<< here for cout render

  private:
    void TextSquare(int height, int width);
    void NoSpacingTextBox(string text);

  private: //temps
    template<typenane ret>
    string FuncConsoleCout(ret* ptrFunc, DatBuffer, datatype(datEnum, datInput<int>);

};

using SimpleRender;
//render display of functions output here
template<typename ret>
string FuncConsoleCout(ret Func&, DatBuffer, datInput<int>){
    string screening = "[render] undefined...";
    functional<ret(&Func(datInput<int>))> Embedded() = &Func(datInput<int>).execute();
    string out =Embedded.render();
    return out;
}

//rendering simple terminal visuals

void TextSqaure(int height, int width){
  int itel = 0;
  while(itel < height){
      cout << "-";
      itel++;
      if(itel == height){
          itel = 0;
          cout << endl;
          break;
        }
      else
        continue;
    }
  while(itel < width){
    if(itel = 0)
      cout << '|' ;
    else if(itel = width - 1;){
      cout << '|' << endl;
      itel = 0;
      break;
      }
    else
      cout << ' ';
    itel++; 
    }
}

void NoSpacingTextBox(string text){
      int itel = 0
  while(itel < height){
      cout << "-";
      itel++;
      if(itel == height){
          itel = 0;
          cout << endl;
          break;
        }
      else
        continue;
    }
  while(itel < 3){
    if(itel = 0)
      cout << '|' ;
    else if(itel = width - 1;){
      cout << '|' << endl;
      itel = 0;
      break;
      }
    else
      cout << text;
    itel++;

  }