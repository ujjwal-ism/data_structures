#include "PriorityQueueExample.h"

using namespace std;

template <typename T> void printPQ(T items){
    while(!items.empty()){
        cout << items.top() << endl;
        items.pop();
    }
}


class ClosestToSquareComparator{
private:
    int distanceFromClosestSquare(const int &number) const{
        int i=1;
        for(;i*i < number;i++);
        return min(i*i-number,number-(i-1)*(i-1));
    }

public:
    bool operator()(const int &int1, const int &int2) const{
        return distanceFromClosestSquare(int1) > distanceFromClosestSquare(int2);
    }
};



class Point2D{
private:
    int x;
    int y;

public:
    Point2D(){
        x=0;
        y=0;
    }
    Point2D(int minX, int maxX, int minY, int maxY){
        this->x = rand()%(maxX-minX+1)+minX;
        this->y = rand()%(maxY-minY+1)+minY;
    }
    int getX() const{
        return x;
    }
    void setX(const int &value){
        this->x = value;
    }
    int getY() const{
        return y;
    }
    void setY(const int &value){
        this->y = value;
    }
};

double pointDistance(const Point2D &pointA, const Point2D &pointB){
    return sqrt(pow(pointA.getX()-pointB.getX(),2)+pow(pointA.getY()-pointB.getY(),2));
}


ostream& operator<<(ostream& stream, const Point2D& point) {
    return stream << "(" << point.getX() << "," << point.getY() << ")";
}


class ClosestToPointComparator{
private:
    Point2D referencePoint;
public:
    ClosestToPointComparator(Point2D inputReferencePoint){
        this->referencePoint.setX(inputReferencePoint.getX());
        this->referencePoint.setY(inputReferencePoint.getY());
    }
    ClosestToPointComparator(int x, int y){
        this->referencePoint.setX(x);
        this->referencePoint.setY(y);
    }

    bool operator()(const Point2D &pointA, const Point2D &pointB) const{
        return pointDistance(this->referencePoint,pointA) > pointDistance(this->referencePoint,pointB);
    }
};



int main(){

    int n=100;
    int max=100;


    cout << endl << "prioritize using less-than:" << endl;
    priority_queue<int> intPQ;
    for(int i=0; i<n; i++){
        intPQ.push(rand()%max);
    }
    printPQ<priority_queue<int> >(intPQ);



    cout << endl << "prioritize closest to square:" << endl;
    priority_queue<int, vector<int>, ClosestToSquareComparator> closestToSquarePQ;
    for(int i=0; i<n; i++){
        closestToSquarePQ.push(rand()%max);
    }
    printPQ<priority_queue<int, vector<int>, ClosestToSquareComparator> >(closestToSquarePQ);


    int minX = -100;
    int maxX = 100;
    int minY = -100;
    int maxY = 100;


    cout << endl << "prioritize closests to origin:" << endl;
    ClosestToPointComparator closestToOrigin(0,0);
    priority_queue<Point2D, vector<Point2D>, ClosestToPointComparator> closestToOriginPQ(closestToOrigin);
    for(int i=0; i<n; i++){
        closestToOriginPQ.push(Point2D(minX,maxX,minY,maxY));
    }
    printPQ<priority_queue<Point2D, vector<Point2D>, ClosestToPointComparator> >(closestToOriginPQ);



    cout << endl << "prioritize closests to reference point:" << endl;
    ClosestToPointComparator closestToReferencePoint(50,50);
    priority_queue<Point2D, vector<Point2D>, ClosestToPointComparator> closestToReferencePQ(closestToReferencePoint);
    for(int i=0; i<n; i++){
        closestToReferencePQ.push(Point2D(minX,maxX,minY,maxY));
    }
    printPQ<priority_queue<Point2D, vector<Point2D>, ClosestToPointComparator> >(closestToReferencePQ);



    return 0;
}