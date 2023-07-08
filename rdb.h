#include<string>
#include<list>
#include<tuple>
#include<vector>
using namespace std;


class Attr
{ // Base class for attributes
  // Add operators for different attribute type in derived classes
public:
    virtual bool operator==(Attr &right) = 0;
    virtual bool operator!=(Attr &right) = 0;
    virtual bool operator<=(Attr &right) = 0;
    virtual bool operator>=(Attr &right) = 0;
    virtual bool operator<(Attr &right) = 0;
    virtual bool operator>(Attr &right) = 0;
    virtual int type() = 0;
};
typedef struct DNFformula // strucutre for DNF formula
{
    list<list<tuple<string, char, Attr *>>> ops;
} DNFformula;

class stringAttribute : public Attr // class for integer derived from base attribute class
{
    string s;

public:
    stringAttribute(string p = "");//constructor
    
    //operators 
    bool operator==(Attr &right);
    

    bool operator!=(Attr &right);
    
    bool operator<=(Attr &right);
    
    bool operator>=(Attr &right);
    

    bool operator<(Attr &right);

    
    bool operator>(Attr &right);
    
    int type() ;
    string get() ;
};

class integerAttribute : public Attr //class for integer atttributes derived from base attribute class
{
    int s;

public:
    integerAttribute(int i = 0);
    
    bool operator==(Attr &right);
    

    bool operator!=(Attr &right);
    
    bool operator<=(Attr &right);
    
    bool operator>=(Attr &right);
   

    bool operator<(Attr &right);
    
    bool operator>(Attr &right);
    
    int type() ;

    int get() ;
};

class floatAttribute : public Attr// class for float attibute derived from the base attribute class 
{
    float s;

public:
    floatAttribute(float i = 0.0);//constructor

    //operators 
    
    bool operator==(Attr &right);
   

    bool operator!=(Attr &right);
   
    bool operator<=(Attr &right);
    
    bool operator>=(Attr &right);
    

    bool operator<(Attr &right);
    
    bool operator>(Attr &right);
    
    
    int type() ;
    float get() ;
};

class doubleAttribute : public Attr//class for double attribute dereived from the base attribute class
{
    double s;

public:
    doubleAttribute(double i = 0.0);//constructor

    //operators 
    
    bool operator==(Attr &right);
   

    bool operator!=(Attr &right);
    
    bool operator<=(Attr &right);
    
    bool operator>=(Attr &right);
    
    bool operator<(Attr &right);
    
    bool operator>(Attr &right);

    int type() ;
    double get(); 
};
class Record//class for record

{ // storing data for each record
    vector<Attr *> attrptr;
    // methods
public:
    Record();//consturctor 
    

    Record(Record &R);//copy constructor
    
    ~Record();//desctructor
    
    Record operator+=(Record &R);
    
    bool operator==(Record *R2);
    

    vector<Attr *> &getptr();//fucntion to return the vector of attributes
    
    void get(string s);///adding a string attribute to the record 
    void get(int i);//adding a integer attribute to the record 

    void get(float i);//adding a float attribute to the record

    void get(double i);//adding a double attribute to the record 
   
    void print();//funtion to print the record 
    
};
class Relation //classs for reation / table
{
    // storing a relation
    int nattr, nrecs;         // number of attributes and records
    vector<string> attrnames; // schema
    vector<int> attrinds;     // mapping schema to indices
    list<Record *> recs;      // list of records
                              // methods
public:
    ~Relation();//destructor 
    
    void get();//returning the list for recs
    
    void print();//priting an relation
    
    void addrecord();//adding a record to a relation

    int getnrecs();


    // basic operations made friends to relation class to access private members


    friend Relation *runion(Relation *R1, Relation *R2);
    friend Relation *difference(Relation *R1, Relation *R2);
    friend Relation *catersianproduct(Relation *R1, Relation *R2);
    friend Relation *projection(Relation *R1, list<string> projectattrs);
    friend Relation *runion(Relation *R1, DNFformula *f);
    friend Relation *difference(Relation *R1, string s1, string s2);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
    friend Relation* makednf(Relation *R, DNFformula *dnf);
    friend void findcommonatri(Relation *R1, Relation *R2, list<string> *a);
};
typedef struct // strucutre for reln which is used to store the relation name and the relation pointer
{
    string name;
    Relation *r;
    bool ini;
} reln;


// operations on relations
Relation *runion(Relation *R1, Relation *R2);

    
Relation *difference(Relation *R1, Relation *R2);

Relation *catersianproduct(Relation *R1, Relation *R2);
Relation *projection(Relation *R, list<string> projectattrs);

Relation *runion(Relation *R1, DNFformula *f);
Relation *difference(Relation *R1, string s1, string s2);

Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);


int find(string s);//findind the index of the relation in the  rdb array

void createreln();//creatin a relation

Relation* makednf(Relation *R, DNFformula *dnf);//making a dnf formula for selection 

void findcommonatri(Relation *R1, Relation *R2, list<string> *a);//finding common attributes for natural join
