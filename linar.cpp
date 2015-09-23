#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Box
{
private:
  int m,n;
  vector<double> line;
  vector< vector<double> >boxinfo;
public:
  Box(int a,int b){m = a;n = b;}
  void printbox();
  void inputbox();
  bool squarebox();
  Box operator + (Box &b1);
  Box operator - (Box &b1);
  Box operator * (Box &b1);
  double boxvalue();
  Box trabox();
};

bool Box::squarebox() //bool if martrix is a square or not
{
    return (m == n);
}
Box Box::trabox()           //codeing,
{
    Box trabox(m,n);
    for(int i = 0; i < n; ++i) trabox.line.push_back(this->boxinfo[0][i]);
    trabox.boxinfo.push_back(line);
	  trabox.line.erase(line.begin(), line.end());
    for(int j = 0;j < this->n - 1; ++j)  // j COL
    {
   		 for(int i = 1;i < this->m; ++i)    //i ROW
   		 {
   		 	for (int k = 0 ;k <= this-> n; ++k)
   		 	{
   		 		//int temp =  boxinfo[i][k] * boxinfo[j][k]/ (- boxinfo[j][j]) + boxinfo[i][k];
   		 	 	//trabox.line.push_back(temp);
   		 	 	if(boxinfo[j][j] == 0) continue;
   		 		this->boxinfo[i][k] = boxinfo[i][k] * boxinfo[j][k]/ (- boxinfo[j][j]) + boxinfo[i][k];
   		 	} //k from 1 to j
   		     //trabox.boxinfo.push_back(line);
       		// trabox.line.erase(line.begin(), line.end());
   		 }
   	}
   	return trabox;
}
double boxvalue()    //codeing,calculate determinant value
{
    return 0;
}
void Box::inputbox()
{
	for (int i = 0; i < this->m; ++i)
	{
		for(int j = 0; j < this->n; ++ j)
        {
            double temp;
            cin >> temp;
            line.push_back(temp);

        }
        boxinfo.push_back(line);
        line.erase(line.begin(), line.end());
	}
}

void Box::printbox()
{
	cout << ">>>Display your Box:" << endl <<endl;
	for (int i = 0; i < this->m; ++i)
	{
		for(int j = 0; j < this->n; ++j)
        {
			    cout.width(6);
			    cout.setf(ios::left);
			    cout.fill(' ');
			    cout << boxinfo[i][j] << " ";
        }
		cout << endl <<endl;
	}
}

Box Box::operator + (Box &b1)
{
	Box b2(n,m);
	for (int i = 0; i < this->m; ++i)
	{
		for(int j = 0; j < this->n; ++ j)
        {
			      double temp = boxinfo[i][j] + b1.boxinfo[i][j];
            b2.line.push_back(temp);
        }
        b2.boxinfo.push_back(b2.line);
        b2.line.erase(b2.line.begin(), b2.line.end());
	}
	return b2;
}
Box Box::operator - (Box &b1)
{
	Box b2(n,m);
	for (int i = 0; i < this->m; ++i)
	{
		for(int j = 0; j < this->n; ++ j)
        {
			      double temp = boxinfo[i][j] - b1.boxinfo[i][j];
            b2.line.push_back(temp);
        }
        b2.boxinfo.push_back(b2.line);
        b2.line.erase(b2.line.begin(), b2.line.end());
	}
	return b2;
}
Box Box::operator * (Box &b1)
{
	Box b2(this->m,b1.n);
	if(this ->n != b1.m)
    {
        cerr << "Error Input! (m!=n)" <<endl;
        return b2;
    }
	for (int i = 0; i < this->m; ++i)
	{
		for(int j = 0; j < b1.n; ++ j)
    {
            double temp (0);
			for(int k = 0; k < this ->n ; ++k)
			{
                temp += boxinfo[i][k] * b1.boxinfo[k][j];
			}
            b2.line.push_back(temp);
    }
    b2.boxinfo.push_back(b2.line);
    b2.line.erase(b2.line.begin(), b2.line.end());
	}
	return b2;
}

Box createbox()
{
    cout <<  ">>>Input box m,n:" ;
    int m,n;
    cin >> m >> n ;
    Box box1(m,n);
    cout <<  ">>>Input box's data:" << endl;
    box1.inputbox();
    return box1;
}

bool legal_input(string str)
{
  if(str == "+" || str == "-" || str == "*" || str == "^" || str == "help" || str == "q")
    return true;
  else return false;
}
void Linar()
{
    cout << "Linarloop is a Tool to calculate martrix values." << endl;
    string op_str;
    while(true){
      cout << ">>>Input your operator(+,-,*,^,q,help):";
      cin >> op_str;
      if(!legal_input(op_str)){
        cout << "Error Input." << endl;
        continue;
      }
      //sys_op
      if(op_str == "q") break;
      else if(op_str == "help"){
        cout << "Help:" << endl;
        cout << "'+','-','*'' is the base operator.\n'^'' to calculate the martrix's power." << endl;
        cout << "'help' to help. q to quit." << endl;
        continue;
      }
      //user_op
      Box box1 (createbox());
      if(op_str == "^")
      {
          int level;
          if(box1.squarebox() == false)
          {
              cerr << "Not a square box!" <<endl;
              continue;
          }
          Box box2(box1);
          cout << ">>>Input your level:";
          cin >> level;
          for(int i = 0; i < level - 1; ++i)
              box2 = box2 * box1;
          box2.printbox();
      }
      Box box2 (createbox());
      if(op_str == "+")
      {
          Box box3(box1 + box2);
          box3.printbox();
      }
      else if(op_str == "-")
      {
          Box box3(box1 - box2);
          box3.printbox();
      }
      else if(op_str == "*")
      {
          Box box3(box1 * box2);
          box3.printbox();
      }
      else
      {
          cout << "System Error!" << endl;
      }
    }
}
