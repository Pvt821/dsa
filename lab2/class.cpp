#include<iostream>

using namespace std;

class area {
private:
    int length;
    int breadth;
    int height;
public:
    void setl(int len) {
        this->length = len;
    } 
    void seth(int heig) {
        this->height = heig;
    }
    void setb(int bread) {
        this->breadth = bread;
    } 

    int square() {
        int area = length * length;
        cout << "Area of the given Square is " << area << endl;
        return 0;
    }

    int cuboid() {
        int area = 2 * (height * breadth + height * length + length * breadth);
        cout << "Area of the given Cuboid is " << area << endl;
        return 0;
    }

    int cube() {
        int area = 6 * length * length;
        cout << "Area of the given Cube is " << area << endl;
        return 0;
    }

    int rectangle() {
        int area = length * breadth;
        cout << "Area of the given Rectangle is " << area << endl;
        return 0;
    }
};

int main() {
    int choice;
    area obj;
    int l;
    int h, b;

    do {
        cout << "Menu card" << endl;
        cout << "Enter 1 : To find the Area of Square" << endl;
        cout << "Enter 2 : To find the Area of Cube" << endl;
        cout << "Enter 3 : To find the Area of Rectangle" << endl;
        cout << "Enter 4 : To find the Area of Cuboid" << endl;
        cout << "Enter 5 : To Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the side of the Square: ";
                cin >> l;
                if (l > 0) {
                    obj.setl(l);
                    obj.square();
                } else {
                    printf("Enter positive values \n\n");
                }
                break;
            case 2:
                cout << "Enter the side of the Cube: ";
                cin >> l;
                if (l > 0) {
                    obj.setl(l);
                    obj.cube();
                } else {
                    printf("Enter positive values  \n\n");
                }
                break;
            case 3:
                cout << "Enter the length of the Rectangle: ";
                cin >> l;
                if (l > 0) {
                    obj.setl(l);
                    cout << "Enter the breadth of the Rectangle: ";
                    cin >> b;
                    if (b > 0) {
                        obj.setb(b);
                        obj.rectangle();
                    } else {
                        printf("Enter positive values  \n\n");
                    }
                } else {
                    printf("Enter positive values  \n\n");
                }
                break;
            case 4:
                cout << "Enter the length of the Cuboid: ";
                cin >> l;
                if (l > 0) {
                    obj.setl(l);
                    cout << "Enter the breadth of the Cuboid: ";
                    cin >> b;
                    if (b > 0) {
                        obj.setb(b);
                        cout << "Enter the height of the Cuboid: ";
                        cin >> h;
                        if (h > 0) {
                            obj.seth(h);
                            obj.cuboid();
                        } else {
                            printf("Enter positive values  \n\n");
                        }
                    } else {
                        printf("Enter positive values  \n\n");
                    }
                } else {
                    printf("Enter positive values  \n\n");
                }
                break;
            case 5:
                cout << "Program Ended" << endl;
                cout << "Thank You";
                break;
            default:
                cout << " Please enter the number between 1 to 5 " << endl;
        }
    } while (choice != 5);
    
    return 0;
}