//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString L = "abcde";
AnsiString O = "()-+*/";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

double StringToFloat(AnsiString s)
{
	if(s.IsEmpty()) return 0.0;
	for(int i = 1; i <= s.Length(); i++)
		if (s[i] == '.' || s[i] == ',')
			s[i] = FormatSettings.DecimalSeparator;
	double x;
	bool right = TryStrToFloat(s, x);
	if(!right)
	{
		x = 0;
		ShowMessage("ERROR");
	}
	return x;
}

double Field(char x)
{
	if (x=='a') return StringToFloat(Form1->A->Text);
	if (x=='b') return StringToFloat(Form1->B->Text);
	if (x=='c') return StringToFloat(Form1->C->Text);
	if (x=='d') return StringToFloat(Form1->D->Text);
	if (x=='e') return StringToFloat(Form1->E->Text);
    else return 0;
}

int Priority(char x)
{
	if(x=='(')return 1;
	else if(x==')')return 2;
	else if(x=='-' || x=='+')return 3;
	else if(x=='*' || x=='/')return 4;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::DataClick(TObject *Sender)
{
	Expression->Text = "a*(b-c)/(d+e)";
	A->Text = "1.6";
	B->Text = "4.9";
	C->Text = "5.7";
	D->Text = "0.8";
	E->Text = "2.3";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	try
	{
		AnsiString str = "(" + Expression->Text + ")";
		for(int i = 1; i <= str.Length(); i++)
			if((L.Pos(str[i]) == 0) && (O.Pos(str[i]) == 0)) ShowMessage("ERROR");
		Stack<char> Letters;
		Stack<char> y;
		for(int i = 1; i <= str.Length(); i++)
		{
			if((str[i]=='a') || (str[i]=='b') || (str[i]=='c') || (str[i]=='d') || (str[i]=='e'))
				Letters.push_back(str[i]);
			if((str[i]=='(') || (str[i]==')') || (str[i]=='+') || (str[i]=='-') || (str[i]=='/') || (str[i]=='*'))
				switch(str[i])
				{
					case '(':
						y.push_back('(');
						break;
					case ')':
						while(y.current->value != '(')
							Letters.push_back(y.pop_back());
						y.pop_back();
						break;
					default:
						while(Priority(str[i]) <= Priority(y.current->value))
						{
							char q = y.pop_back();
							Letters.push_back(q);
						}
						y.push_back(str[i]);
				}
		}
		if (y.current!=nullptr) ShowMessage("ERROR");

		Stack<char> cur(Letters);
		Letters.rev();
		AnsiString notation;
		while(cur.current!=nullptr)
			 notation += cur.pop_back();
		PolNot->Text = notation;
	}
    catch(...)
	{
		ShowMessage("Wrong expression");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	try
	{
		AnsiString str = PolNot->Text;
		Stack<char> Letter;
		Stack<double> s;
		for(int i = 1; i <= str.Length(); i++)
		{
			Letter.push_back(str[i]);
		}
		Letter.rev();
		while(Letter.current != nullptr)
		{
			if (L.Pos(Letter.current->value) != 0) s.push_back(Field(Letter.current->value));
			if (O.Pos(Letter.current->value) != 0)
			{
				double b = s.pop_back();
				double a = s.pop_back();
				switch(Letter.current->value)
				{
					case '+':
						s.push_back(a + b);
						break;
					case '-':
						s.push_back(a - b);
						break;
					case '/':
						s.push_back(a / b);
						break;
					case '*':
						s.push_back(a * b);
						break;
					default:
						throw 42;
				}
			}
			Letter.pop_back();
		}
		if(s.current == nullptr) throw 42;
		Res->Text = FloatToStr(s.pop_back());
		if(s.current != nullptr) throw 42;
	}
	catch(...)
	{
		ShowMessage("Wrong expression");
	}
}
//---------------------------------------------------------------------------

