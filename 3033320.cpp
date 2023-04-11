//INDEX NUMBER: 3033320
//NAME: KWOFIE ENOCH JACKSON

#include <iostream>
#include <conio.h>

using namespace std;

class CPolygon{

    protected:
        float width;
        float height;

    public:
        //Base class set_values
        void setValues(){
            cout << "===========================\n";
            cout << "Enter polygon dimensions.\n";
            cout << "Width: ";
            cin >> width;
            cout << "Height: ";
            cin >> height;
            cout << "===========================\n";
        }

        virtual float area(void) = 0; // pure virtual function

        void printArea(){
            cout << this->area() << endl;
        }
};

//Derived Rectangle class
class CRectangle : public CPolygon{
    public:
        float area(){
            return (width * height);
        }
};

//Derived Triangle class
class CTriangle : public CPolygon {
    public:
        float area(){
            return (width * height)/2;
        }
};

//Derived Sqaure class
class CSquare : public CPolygon {
    public:
        float area(){
            return (width * height);
        }
};


const int MAX_POLYGONS = 100; // maximum number of polygons that can be stored in the array

int main()
{

   CPolygon* polygons[MAX_POLYGONS]; // array of pointers to CPolygon objects
   int n = 0; // next index to be filled in the array
   char choice;

   do{
        // ask the user to select a polygon type
        cout << "\n";
        cout << "Select a polygon type (1=Rectangle, 2=Triangle, 3=Square): \n";
        cout << "Choice: ";
        cin >> choice;

        // create a new polygon object based on the user's choice
        CPolygon* polygon[MAX_POLYGONS];

        switch(choice){
            case '1':
            {
                polygons[n] = new CRectangle;// create a new rectangle object
                polygons[n]->setValues();
                n++;

                cout << "\nDo you want to add another polygon? Y/N";
                choice = getch();
                break;// Break if choice is N
            }

            case '2':
            {
                polygons[n] = new CTriangle;// create a new triangle object
                polygons[n]->setValues();
                n++;

                cout << "\nDo you want to add another polygon? Y/N";
                choice = getch();
                break;// Break if choice is N
            }

            case '3':
            {
                polygons[n] = new CSquare;// create a new square object
                polygons[n]->setValues();
                n++;

                cout << "\nDo you want to add another polygon? Y/N";
                cout << "\n";
                choice = getch();
                break;// Break if choice is N
            }

            default:
                cout << "Invalid choice." << endl;
                continue; // go back to the beginning of the loop
        }
   }

   while(choice == 'y');

    cout << "\n";

   for(int i=0;i<n;i++){
        cout << "\n";
        cout << "\nArea for polygon " << i+1 << ": ";
        polygons[i]->printArea();
        cout << "=======================";
        cout << endl;
   }


    return 0;
}
