//This file contains the implementation of attributes and its derived types, record and relation
/**********************************************************************************************/
#include"rdb.h"
#include<iostream>
using namespace std;



stringAttribute::stringAttribute(string p)//constructor for  string attribute
    {
        s = p;
    }
    
  bool stringAttribute:: operator==(Attr &right)// == operator overloaded for string attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s == ((stringAttribute *)(&right))->s);
    }

    bool stringAttribute::operator!=(Attr &right)// != operator overloaded for string attribute
    {
         
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 1;
        return (s != ((stringAttribute *)(&right))->s);
    }
    bool stringAttribute:: operator<=(Attr &right)// <= operator overloaded for string attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s <= ((stringAttribute *)(&right))->s);
    }
    bool stringAttribute::operator>=(Attr &right)// >= operator overloaded for string attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s >= ((stringAttribute *)(&right))->s);
    }

    bool stringAttribute::operator<(Attr &right)// < operator overloaded for string attribute

    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s < ((stringAttribute *)(&right))->s);
    }
    bool stringAttribute::operator>(Attr &right)// > operator overloaded for string attribute
    {
       
        if (this->type() != (&right)->type())
            return 0;
            
        return (s > ((stringAttribute *)(&right))->s);
    }
    int stringAttribute::type() { return 0; }//returns the type of attribute
    string stringAttribute::get() { return s; }//returns the value of string attribute

   integerAttribute:: integerAttribute(int i)//constructor for integer attribute
    {
        s = i;
    }
    bool integerAttribute::operator==(Attr &right)// == operator overloaded for integer attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s == ((integerAttribute *)(&right))->s);
    }

    bool integerAttribute::operator!=(Attr &right)// != operator overloaded for integer attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 1;
        return (s != ((integerAttribute *)(&right))->s);
    }
    bool integerAttribute::operator<=(Attr &right)// <= operator overloaded for integer attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s <= ((integerAttribute *)(&right))->s);
    }
    bool integerAttribute::operator>=(Attr &right)// >= operator overloaded for integer attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s >= ((integerAttribute *)(&right))->s);
    }

    bool integerAttribute::operator<(Attr &right)// < operator overloaded for integer attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s < ((integerAttribute *)(&right))->s);
    }
    bool integerAttribute::operator>(Attr &right)// > operator overloaded for integer attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s > ((integerAttribute *)(&right))->s);
    }
    int integerAttribute::type() { return 1; }//returns the type of attribute

    int integerAttribute::get() { return s; }// returns the value of integer attribute

     floatAttribute::floatAttribute(float i)//constructor for float attribute
    {
        s = i;
    }

    bool floatAttribute::operator==(Attr &right)// == operator overloaded for float attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s == ((floatAttribute *)(&right))->s);
    }

    bool floatAttribute::operator!=(Attr &right)// != operator overloaded for float attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 1;
        return (s != ((floatAttribute *)(&right))->s);
    }
   
    bool floatAttribute::operator<=(Attr &right)// <= operator overloaded for float attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s <= ((floatAttribute *)(&right))->s);
    }
    bool floatAttribute::operator>=(Attr &right)// >= operator overloaded for float attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s >= ((floatAttribute *)(&right))->s);
    }

    bool floatAttribute::operator<(Attr &right)// < operator overloaded for float attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s < ((floatAttribute *)(&right))->s);
    }
    bool floatAttribute::operator>(Attr &right)// > operator overloaded for float attribute
    {
        if (this->type() != (&right)->type())
            return 0;
            
        return (s > ((floatAttribute *)(&right))->s);
    }
    int floatAttribute::type() { return 2; }//returns the type of attribute
    float floatAttribute::get() { return s; }//returns the value of float attribute


     doubleAttribute::doubleAttribute(double i )//constructor for double attribute
    {
        s = i;
    }
    bool doubleAttribute::operator==(Attr &right)// == operator overloaded for double attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s == ((doubleAttribute *)(&right))->s);
    }

    bool doubleAttribute::operator!=(Attr &right)// != operator overloaded for double attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 1;
        return (s != ((doubleAttribute *)(&right))->s);
    }   
    
    bool doubleAttribute::operator<=(Attr &right)// <= operator overloaded for double attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s <= ((doubleAttribute *)(&right))->s);
    }
    bool doubleAttribute::operator>=(Attr &right)// >= operator overloaded for double attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s >= ((doubleAttribute *)(&right))->s);
    }

    bool doubleAttribute::operator<(Attr &right)// < operator overloaded for double attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s < ((doubleAttribute *)(&right))->s);
    }
    bool doubleAttribute::operator>(Attr &right)// > operator overloaded for double attribute
    {
        if (this->type() != (&right)->type())//checks if the types of the attribute is same
            return 0;
        return (s > ((doubleAttribute *)(&right))->s);
    }
    int doubleAttribute::type() { return 3; }//returns the type of attribute

    double doubleAttribute::get() { return s; }//returns the value of double attribute



    //record

    Record::Record()//constructor for record
    {
    }
    

    Record::Record(Record &R)//copy constructor for record
    {

        for (auto i = R.getptr().begin(); i < R.getptr().end(); i++)
        {

            int type = (*i)->type();//getting type of attribute

            switch (type)
            {

            case 0://string attribute case
                get(((stringAttribute *)((*i)))->get());

                break;
            case 1://integer attribute case
                get(((integerAttribute *)((*i)))->get());
                break;
            case 2://float attribute case
                get(((floatAttribute *)((*i)))->get());
                break;
            case 3://double attribute case
                get(((doubleAttribute *)((*i)))->get());
                break;
            }
        }
    }
    Record::~Record()//destrucutor for record
    {
        for (int i = 0; i < attrptr.size(); i++)
        {
            delete attrptr[i];//deleting the memory allocated for attributes
        }
    }
   Record Record::operator+=(Record &R)// += operator overloaded for record
    {
        for (auto i = R.getptr().begin(); i < R.getptr().end(); i++)
        {
            int type = (*i)->type();
            switch (type)
            {
            case 0:
                this->get(((stringAttribute *)((*i)))->get());
                break;
            case 1:
                this->get(((integerAttribute *)((*i)))->get());
                break;
            case 2:
                this->get(((floatAttribute *)((*i)))->get());
                break;
            case 3:
                this->get(((doubleAttribute *)((*i)))->get());
                break;
            }
        }
    }
    bool Record::operator==(Record *R2)// == operator overloaded for record
    {
        int i;
        auto it = getptr().begin();
        auto it1 = R2->getptr().begin();
        if(getptr().size()!=R2->getptr().size())
            return 0;
        for (it = getptr().begin(); it != getptr().end(); it++, it1++)
        {
            int flag = 0;
            //checking if the types of attributes are same
            int type = (*it)->type();
            int type1 = (*it1)->type();
            if(type!=type1)
                return 0;
            switch (type)
            {
            case 0://both string attributes case
                if (((stringAttribute *)(*it1))->get() != ((stringAttribute *)(*it))->get())
                {
                    flag = 1;
                    break;
                }

                break;
            case 1: // both are integer attributes case 
                if (((integerAttribute *)(*it1))->get() != ((integerAttribute *)(*it))->get())
                {
                    flag = 1;
                    break;
                }
                break;
            case 2://both are float attributes case
                if (((floatAttribute *)(*it1))->get() != ((floatAttribute *)(*it))->get())
                {
                    flag = 1;
                    break;
                }

                break;
            case 3:// both are double attributes case
                if (((doubleAttribute *)(*it1))->get() != ((doubleAttribute *)(*it))->get())
                {
                    flag = 1;
                    break;
                }

                break;
            }
            if (flag)
                break;
        }
        if (it == getptr().end())
            return 1;
        else
            return 0;
    }

    vector<Attr *>& Record::getptr()//meathod to return the vector of attributes
    {
        return (attrptr);
    }
    void Record::get(string s)//meathod to add a string attribute to record 
    {
        attrptr.push_back(new stringAttribute(s));
    }
    void Record::get(int i)//meadthod to add a integer attribute to record 
    {
        attrptr.push_back(new integerAttribute(i));
    }

    void Record::get(float i)//meathod to add a float attribute to record 
    {
        attrptr.push_back(new floatAttribute(i));
    }

    void Record::get(double i)//meadhod to addd a double attribute to record 
    {
        attrptr.push_back(new doubleAttribute(i));
    }
    void Record::print()//function to print the record 
    {
        for (auto it = attrptr.begin(); it != attrptr.end(); it++)
        {
            int type = (*it)->type();//chceking the type of attribute
            switch (type)
            {
            case 0://string case 
                cout << ((stringAttribute *)(*it))->get() << " ";
                break;
            case 1://integer case 
                cout << ((integerAttribute *)(*it))->get() << " ";
                break;
            case 2://float case 
                cout << ((floatAttribute *)(*it))->get() << " ";
                break;
            case 3://double case 
                cout << ((doubleAttribute *)(*it))->get() << " ";
            }
        }
        cout << "\n";
    }


    //Relation


     Relation::~Relation()//desstrcutor for relation
    {
        for (auto it = recs.begin(); it != recs.end(); it++)
        {
            delete (*it);
        }
    }

 
    void Relation::get()//function to instatiate the relation
    {
        string s;
        int intinput;
        float floatinput;
        double doubleinput;
        cout << "enter the number of attriutes\n";//getting the number of attributes
        cin >> nattr;
        int type[nattr];
        cout << "enter the number of records\n";
        cin >> nrecs;//getting the number of records
        cout << "enter attributes names \n ";
        for (int i = 0; i < nattr; i++)//getting attribute names 
        {
            cin >> s;
            attrnames.push_back(s);
        }
        cout << "types: string->0,int->1,float->2,double->3\n";
        for (int j = 0; j < nattr; j++)// getting attribute types 
        {
            cout << "enter type for " << attrnames[j] << endl;
            cin >> type[j];
        }

        for (int i = 0; i < nrecs; i++)//adding record to the realtion 
        {
            Record *a = new Record;
            cout << "Record: " << i << endl;
            for (int j = 0; j < nattr; j++)
            {
                switch (type[j])
                {
                case 0://case for string attribute
                    cout << "enter a string for the attribute  " << attrnames[j] << " : ";
                    cin >> s;
                    a->get(s);
                    break;
                case 1:// case for integer attribute
                    cout << "enter a integer for the attribute  " << attrnames[j] << " : ";
                    cin >> intinput;
                    a->get(intinput);
                    break;
                case 2://case for float attribute
                    cout << "enter a floating number for the attribute  " << attrnames[j] << " : ";
                    cin >> floatinput;
                    a->get(floatinput);
                    break;
                case 3://case for double attribute
                    cout << "enter a double number for the attribute  " << attrnames[j] << " : ";
                    cin >> doubleinput;
                    a->get(doubleinput);
                    break;
                default://invalid type case;
                    cout << "invalid type\n";
                    j--;
                }
            }
            recs.push_back(a);
        }
    }
    void Relation::print()//fucntion to print the relation
    {
        for (int i = 0; i < nattr; i++)//first printing the attribute names 
        {
            cout << attrnames[i] << " ";
        }
        cout << "\n";
        for (auto it = recs.begin(); it != recs.end(); it++)//priting records wise 
        {
            (*it)->print();// calling the print function of record class
        }
    }
    void Relation::addrecord()//fucntion to add record to the relation
    {
        int i1;
        string s;
        float f;
        double d;
        Record *a = new Record;
        for (int i = 0; i < nattr; i++)//taking input for each attribute
        {
            int type = (*(recs.begin()))->getptr()[i]->type();
            switch (type)
            {
            case 0://case of string attribute
                cout << "enter a string for the atribute " << attrnames[i] << " : " << endl;
                cin >> s;
                a->get(s);
                break;
            case 1://case of integer attribute
                cout << "enter a integer for the atribute " << attrnames[i] << " : " << endl;
                cin >> i1;
                a->get(i1);
                break;
            case 2://case of float attribute
                cout << "enter a float for the atribute " << attrnames[i] << " : " << endl;
                cin >> f;
                a->get(f);
                break;
            case 3:// case of double attribute
                cout << "enter a double for the atribute " << attrnames[i] << " : " << endl;
                cin >> d;
                a->get(d);
                break;
            }
        }
    }

    int Relation::getnrecs()
    {
        return recs.size();
    }












