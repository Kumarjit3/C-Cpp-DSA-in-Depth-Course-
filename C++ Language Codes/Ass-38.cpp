#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;

void q1();
void q2();
void q3();
void q4();
void q5();
void q6_7();
void q8();

class person
{
    private:
      string name;
      int age;
    protected:
      void set_age(int age) { this->age=age; }
      void set_name(string name) { this->name=name; }
      int get_age() { return age; }  
      string get_name() { return name; }
      public:
       person() { name="kumarjit"; age=22; }
};

class employee: public person
{
    private:
      double salary;
    public:
    employee() { salary=30000; }
      void set_employee(string name,int age,double salary)
        {
         set_name(name);
         set_age(age);
         this->salary=salary;
        }
       void show_employee()
        {
             cout<<endl<<"NAME : "<<get_name();
             cout<<endl<<"AGE : "<<get_age();
             cout<<endl<<"SALARY : "<<salary<<endl;
        }    
};


class circle
{
    private:
      int radius;
    public:
      circle() { radius=3; }
      void set_radius(int radius) { this->radius=radius; } 
      int get_radius() { return radius; } 
      float get_area() { return (3.14*radius*radius); }  
};


class ThickCircle:public circle
{
     private:
       float thickness;
     public:
     ThickCircle(): thickness(3.3) { }
    void set_thickness(float thickness) { this->thickness=thickness; }
    float get_thickness() { return thickness; }
    float get_area() {  return (3.14*((get_radius()+thickness)*(get_radius()+thickness)-get_radius()*get_radius()));  }
};


class coordinate
{
     private:
        int x,y;
     public:
        coordinate()
        {
           x=3; y=4;
        }
        void setCoordinate(int x,int y) { this->x=x; this->y=y; }
        void showCoordinate() 
        { 
          cout<<endl<<"( "<<x<<","<<y<<" )"<<endl;
        }
        int getX() { return x; }
        int getY() { return y; }
        float getDistance()
         { 
           return sqrt((x*x)+(y*y)); 
         }
        float getDistance(coordinate c1)
         {
           return sqrt(((x-c1.x)*(x-c1.x))+((y-c1.y)*(y-c1.y))); 
         }   
};


class shape
{
     private:
        string shapeName;
     public:
       shape() { shapeName="circle"; }
       void setShapeName(string shapeName) { this->shapeName=shapeName; }
       string getShapeName() { return shapeName; }   
};

class straightLine : public shape
{
    private:
      coordinate A,B;
    public:
      void setLine(coordinate A,coordinate B)
      {
        this->A=A;
        this->B=B;
      }
      float getDistance()
       {
          return A.getDistance(B);
       }
      void showLine()
      {
        A.showCoordinate();
        B.showCoordinate();
      } 
};

class Game
{
     private:
        int arr[5];
     public:
        void setScore(int round,int score) 
        {
          arr[round]=score;
        }
        int getScore(int round)
        {
            return arr[round];
        }   
};


class GameResult : public Game
{
    private:
      int rrr[5];
    public:
      void setResult(int r,int s) { rrr[r]=s; }
      int getResult(int r) { return rrr[r]; }
      void finalResult()
       { 
           int i,f=0;
           for(i=0; i<5; i++)
           {
               f+=getResult(i);
           }
           cout<<endl<<"The Final Result Is : "<<f<<endl;   
       }
        
};


class Actor
{
    private:
       string name;
       int age;
    public:
        Actor() : name("kumarjit"),age(20) { }
        void setAge(int age) { this->age=age; }
        void setName(string name) { this->name=name; }
        int getAge() {  return age;  }
        string getName() { return name; } 
};

class TVActor : virtual public Actor
{
   private:
      int projects;
      public:
      TVActor(): projects(3) { }
      void setProjects(int projects) { this->projects=projects; }
      int getProjects() { return projects; }
      void setTVActor(string name,int age,int projects)
      {
         setName(name);
         setAge(age);
         setProjects(projects);
      }
      void ShowTVActor()
      {
        cout<<endl<<"NAME : "<<getName();
        cout<<endl<<"AGE : "<<getAge();
        cout<<endl<<"PROJECTS : "<<getProjects()<<endl;
      }

};


class MovieActor : virtual public Actor
{
     private:
       int movies;
     public:
     MovieActor() : movies(3) { }
     void setMovies(int movies) { this->movies=movies; }
     int getMovies() { return movies; }
     void setMovieActor(string name,int age,int movies)
     {
       setName(name);
       setAge(age);
       setMovies(movies);
     }
     void showMovieActor()
     {
      cout<<endl<<"NAME : "<<getName();
      cout<<endl<<"Age : "<<getAge();
      cout<<endl<<"MOVIES : "<<getMovies()<<endl;
     }  
};


class AllScreenActor : public TVActor,public MovieActor
{
    public:
      void setActorData(string name,int age,int projects,int movies)
      {
          setName(name);
          setAge(age);
          setProjects(projects);
          setMovies(movies);
      }
      void showActorData() 
      {
         cout<<endl<<"NMAE : "<<getName();
         cout<<endl<<"AGE : "<<getAge();
         cout<<endl<<"MOVIES : "<<getMovies();
         cout<<endl<<"PROJECTS : "<<getProjects()<<endl;
      }
};

void q1()
{
   employee e1;
   e1.set_employee("Kumarjit Mongal",23,33000);
   e1.show_employee();
   cout<<endl;
}

void q2()
{
     ThickCircle t1;
     t1.set_thickness(33);
     cout<<endl<<"AREA OF THICKNESS : "<<t1.get_area();
    cout<<endl;
}

void q3()
{
    coordinate c1;
    c1.setCoordinate(2,2);
    cout<<c1.getDistance()<<endl;;
    cout<<endl<<c1.getDistance(c1);
    cout<<endl;
}

void q4()
{
   shape s1;
   s1.setShapeName("square");
   s1.getShapeName();
   cout<<endl;
}

void q5()
{
   straightLine s1; coordinate c1,c2;
   c1.setCoordinate(12,13);
   c2.setCoordinate(22,33);
   s1.setLine(c1,c2);
   s1.showLine();
   cout<<endl;
}

void q6_7()
{
    Game g1; GameResult gr1; int i,n=5,s;
    for(i=0; i<n; i++)
    {
      cout<<endl<<"Enter score of "<<i+1<<" game : "; cin>>s;
      gr1.setScore(i,s);
    }
    for(i=0; i<n; i++)
    {
      cout<<endl<<i+1<<" No game : "<<gr1.getScore(i);
    }
    cout<<endl;
    gr1.finalResult();
    cout<<endl;
}


void q8()
{
     MovieActor m1;  TVActor t1;   AllScreenActor a1;
    cout<<endl<<"TV ACTORS DETAILS______________"<<endl;
    t1.setTVActor("Kumarjit Mongal",20,22);
    t1.ShowTVActor();
    cout<<endl<<"MOVIE ACTORS DETAILS______________"<<endl;
    m1.setMovieActor("Neil Roy",21,30);
    m1.showMovieActor();
    cout<<endl<<"ALL SCREEN ACTORS DETAILS______________"<<endl;
    a1.setActorData("Sidharth Sukla",21,33,30);
    a1.showActorData();
    cout<<endl;
}


int main()
{
   system("cls");
    //q1();
    //q2();
    //q3();
    //q4();
    //q5();
    //q6_7();
    q8();
    cout<<endl;
    return 0;
}