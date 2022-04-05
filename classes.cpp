#include <iostream>

using std::cout, std::endl, std::string, std::ostream;

// This declaration is normally in a separate header file
class Pixel {
    // Private attributes
    private:
        int r = 0;
        int g = 0;
        int b = 0;
        int x = 0;
        int y = 0;
    
    // Public functions
    public:
        Pixel(int r, int g, int b, int x, int y);
        Pixel(int r, int g, int b);
        Pixel(int x, int y);

        // Getters
        int getR() const;
        int getG() const;
        int getB() const;
        int getX() const;
        int getY() const;

        // Setters
        void setR(int r);
        void setG(int g);
        void setB(int b);
        void setX(int x);
        void setY(int y);

        // Operator overloads
        friend std::ostream& operator << (ostream& out, const Pixel &pixel);
        Pixel operator + (const Pixel &pixel);
        Pixel operator - (const Pixel &pixel);
        Pixel& operator += (const Pixel &pixel);
};  // Don't forget the semicolon

// Defining the functions
// First three are constructors
Pixel::Pixel(int r, int g, int b, int x, int y) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->x = x;
    this->y = y;
}
Pixel::Pixel(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}
Pixel::Pixel(int x, int y) {
    this->x = x;
    this->y = y;
}

int Pixel::getR() const { return this->r; }
int Pixel::getG() const { return this->g; }
int Pixel::getB() const { return this->b; }
int Pixel::getX() const { return this->x; }
int Pixel::getY() const { return this->y; }

void Pixel::setR(int r) { this->r = r; }
void Pixel::setG(int g) { this->g = g; }
void Pixel::setB(int b) { this->b = b; }
void Pixel::setX(int x) { this->x = x; }
void Pixel::setY(int y) { this->y = y; }

std::ostream& operator << (ostream& out, const Pixel &pixel) {
    out << "R: " << pixel.r << " G: " << pixel.g << " B: " << pixel.b << endl;
    out << "X: " << pixel.x << " Y: " << pixel.y << endl;

    return out;
}

Pixel Pixel::operator + (const Pixel &pixel) {
    int new_r = this->r + pixel.r;
    int new_g = this->g + pixel.g;
    int new_b = this->b + pixel.b;
    int new_x = this->x + pixel.x;
    int new_y = this->y + pixel.y;

    return Pixel(new_r, new_g, new_b, new_x, new_y);
}

Pixel Pixel::operator - (const Pixel &pixel) {
    int new_r = this->r - pixel.r;
    int new_g = this->g - pixel.g;
    int new_b = this->b - pixel.b;
    int new_x = this->x - pixel.x;
    int new_y = this->y - pixel.y;

    return Pixel(new_r, new_g, new_b, new_x, new_y);
}

Pixel& Pixel::operator += (const Pixel &pixel) {
    this->r += pixel.r;
    this->g += pixel.g;
    this->b += pixel.b;
    this->x += pixel.x;
    this->y += pixel.y;

    return *this;
}

int main() {
    Pixel p1(1, 2, 3);
    Pixel p2(4, 5);
    Pixel p3(6, 7, 8, 9, 10);

    p3 += p1;
    Pixel p4 = p2 - p1;
    Pixel p5 = p2 + p1;

    cout << p1 << endl; // RGB: 1,2,3    XY: 0, 0
    cout << p2 << endl; // RGB: 0,0,0    XY: 4,5
    cout << p3 << endl; // RGB: 7,9,11   XY: 9,10
    cout << p4 << endl; // RGB: -1,-2,-3 XY: 4, 5
    cout << p5 << endl; // RGB: 1,2,3    XY: 4,5
}

/* UML FOR THE CLASS
class Pixel:
    Attributes {
        - r : Number
        - g : Number
        - b : Number
        - x : Number
        - y : Number
    }
    Methods {
        + Pixel(r : Number, g : Number, b : Number)
        + Pixel(x : Number, y : Number)
        + Pixel(r : Number, g : Number, b : Number, x : Number, y : Number)
        + getR() : Number
        + getG() : Number
        + getB() : Number
        + getX() : Number
        + getY() : Number
        + setR(r : Number) : void
        + setG(g : Number) : void
        + setB(b : Number) : void
        + setx(x : Number) : void
        + sety(y : Number) : void
        + operator << (out : ostream, pixel : Pixel) : ostream  **
        + operator + (pixel : Pixel) : Pixel
        + operator - (pixel : Pixel) : Pixel
        + operator += (pixel : Pixel) : Pixel pointer
    }

    **Note: This is a global function so it is not technically a member function (can't do Pixel::) 
    but still has its declaration within the class
}


*/