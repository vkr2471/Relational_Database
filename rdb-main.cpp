/*This file contains implementation of main fucntion and all other helping functions */
/***************************************************************************************/

#include"rdb.h"
#include<iostream>
using namespace std;
vector<reln> rdb;//global vector of relations... which are stored in the form of reln

int find(string s)
{
    for (int i = 0; i < rdb.size(); i++)
    {
        if (s == rdb[i].name)
        {
            return i; // an relation with given name found
        }
    }
    return -1; // no match found
}

void createreln()//creating a new realtion
{
    reln x;
    cout << "enter the name of the relation: ";
    cin >> x.name;
    int t = find(x.name); // Checking if name exists already
    if (t != -1)
    {
        cout << "A relation already exists with that name\n ";

        return;
    }
    (x).ini = 0;
    x.r = new Relation;
    rdb.push_back(x);
}
Relation* makednf(Relation *R, DNFformula *dnf)//making a dnf formula for selection
{
    string name;
    char c;
    R->print();
    int i = 0;
    int flag=0;
    string s;
    int j;
    float f;
    double d;
    char ch;
    vector<Attr *> v;
    cout<<"enter name of the atributes to be taken in a product term also enter the correspoding value enter -1 to end a product term press -2  to complete the dnf formula\n";
    cout << "comparison operators :\n0: ==\n1: !=\n2: <\n3: <=\n4: >\n5: >=\n"; 
    cin>>name;
    while(name!="-2")//loop for taking the product terms
    {
        flag=0;//to remember if we had pushed any thing to the list, this makes sure we dont add empty list
        cin.clear();
        list<tuple<string, char, Attr *>> a;
        while(name!="-1")//loop for takking each term of a product term
        {
        for( i=0;i<R->nattr;i++)//finding index of the atribute 
        {
            if(R->attrnames[i]==name)
            {
                switch(((*(R->recs.begin()))->getptr()[i])->type())//type safety, chechking for type of the atribute
                {
                    case 0://string
                    cout<<"enter a string for the atribute "<<name<<endl;
                    cin>>s;
                    cin.clear();
                    cout<<"enter the operator for the atribute "<<name<<endl;
                    cin>>ch;
                    flag=1;
                    v.push_back(new stringAttribute(s));//creating a new temporary atribute with entered value
                    a.push_back(make_tuple(name,ch,v.back()));
                    break;
                    case 1://integer
                    cout<<"enter a int for the atribute "<<name<<endl;
                    cin>>j;
                    cin.clear();
                    cout<<"enter the operator for the atribute "<<name<<endl;
                    cin>>ch;
                    v.push_back(new integerAttribute(j));//creating a new temporary atribute with entered  value
                    a.push_back(make_tuple(name,ch,v.back()));
                    flag=1;
                    break;
                    case 2://float
                    cout<<"enter a float for the atribute "<<name<<endl;
                    cin>>f;
                    cin.clear();
                    cout<<"enter the operator for the atribute "<<name<<endl;
                    cin>>ch;
                    v.push_back(new floatAttribute(f));//creating a new temporary atribute with entered value
                    a.push_back(make_tuple(name,ch,v.back()));
                    flag=1;
                    break;
                    case 3://double
                    cout<<"enter a double for the atribute "<<name<<endl;
                    cin>>d;
                    cin.clear();
                    flag=1;

                    cout<<"enter the operator for the atribute "<<name<<endl;
                    cin>>ch;
                    v.push_back(new doubleAttribute(d));//creatig new tempoary atribute with entered value
                    a.push_back(make_tuple(name,ch,v.back()));
                    break;


                }
                break;
                          
            }
        }
        cin.clear();
        cin>>name;
        
    }
    if(flag)dnf->ops.push_back(a);//adding non empty lists to the dnf formula
    cin>>name;
    
    }
    Relation* R1=runion(R,dnf);//creating the new relation with the dnf formula
    for(auto it= v.begin();it!=v.end();it++) delete (*it);//deleting all the temporary attributes
    return R1;
}
void findcommonatri(Relation *R1, Relation *R2, list<string> *a)// a fucntion to find common attributes of two relations , used forw natural join
{
    for (int i = 0; i < R1->nattr; i++)
    {
        for (int j = 0; j < R2->nattr; j++)
        {
            if (R1->attrnames[i] == R2->attrnames[j])
                a->push_back(R1->attrnames[i]);
        }
    }
    // for(auto it=a->begin();it!=a->end();it++) cout<<(*it)<<" ";
}

int main()
{
    int choice;
    string name;
    int t,t1,t2;
    while (1)
    {
        //priting all the available choices
        cout << "Choices: \n"
             << "0 : create a new relation\n";
        cout << "1 : enter data to a empty table\n";
        cout << "2 : delete an entire table\n";
        cout << "3: enter a record to a table\n";
        cout << "4: print a table\n ";
        cout<<"5: union\n";
        cout<<"6: difference\n";
         cout<<"7: cartesian product\n";
         cout<<"8: projection\n";
         cout<<"9: selection\n";
         cout<<"10 : rename\n";
         cout<<"11 : natural join\n";
         cout<<"12 : print all relations\n";
         cout<<"13 : exit\n";
         cout<<"enter a choice\n";
         cin>>choice;
        switch (choice)
        {
        case 0://creating a new empty realtion
            createreln();
            break;
        case 1://initilizing a empty relation
            cout << "enter name of the table\n";
            cin >> name;
             t = find(name);//finding the name 
            if (t == -1)
                cout << "no such relation exits\n";
            else
            {
                if (rdb[t].ini)// if already initialized
                    cout << "Non empty table";
                else
                    rdb[t].r->get();
                rdb[t].ini = 1;
            }
            break;
        case 2://deleting a whole table
            cout << "enter name of the table\n";
            cin >> name;
             t = find(name);//finding the index in rdb
            if (t == -1)
                cout << "no such relation exits\n";
            else
            {
                delete rdb[t].r;//freeing up the allocated memory for the realtion 
                rdb.erase(rdb.begin() + t);//deleting the relation from rdb
            }
            break;
        case 3://adding a record to a table
            cout << "enter name of the table\n";
            cin >> name;
             t = find(name);//finding for index
            if (t == -1)
                cout << "no such relation exits\n";
            else
            {
                if (!rdb[t].ini)// if not initialzed laready asking to initialize
                    cout << "initialize the table first\n";
                else
                {
                    rdb[t].r->addrecord();
                }
            }
            break;
        case 4://priting a relation
            cout << "enter name of the relation";
            cin >> name;
             t = find(name);//finding for index in rdb
            if (t == -1)
                cout << "no such relation\n";
            else
            {
                if (!rdb[t].ini)
                    cout << "not initialized\n";
                else
                {
                    rdb[t].r->print();
                }
            }
            break;
        case 5://union of two relations 
            cout << "enter name of relation1 \n";
            cin >> name;
             t = find(name);//finding the index for first realtion 
            if (t == -1)
            {
                cout << "no such relation\n";
                break;
            }
            else
            {
                cout << "enter name of relation2 \n";
                cin >> name;
                 t1 = find(name);//finding the relation for second index

                if (t1 == -1)
                {
                    cout << "no such relation\n";
                    break;
                }
                else
                {
                    Relation *r = runion(rdb[t].r, rdb[t1].r);//finding the union 
                    reln a;
                    a.ini = 1;
                    if(r->getnrecs()!=0)
                    {
                    cout << "enter name for the union\n";
                    cin >> name;
                     t = find(name);
                    while (t != -1)
                    {
                        cout << "a relation already exists with that name try again!!\n";
                        cin >> name;
                        t = find(name);
                    }
                    a.name = name;
                    a.r = r;
                    cout << "the union is :\n";
                    r->print();
                    rdb.push_back(a);// adding the new relation to rdb
                    }
                }
            }
            break;
        case 6://difference of two relations 
            cout << "enter name of relation1 \n";
            cin >> name;
             t = find(name);//finding for relation 1
            if (t == -1)
            {
                cout << "no such relation\n";
                break;
            }
            else
            {
                cout << "enter name of relation2 \n";
                cin >> name;
                 t1 = find(name);//finding for realtion 2
                if (t1 == -1)
                {
                    cout << "no such relation\n";
                    break;
                }
                else
                {
                
                    Relation *r = difference(rdb[t].r, rdb[t1].r);//finding for their difference
                    reln a;
                    a.ini = 1;
                    if(r->getnrecs()!=0)
                    {
                    cout << "enter name for the difference\n";
                    cin >> name;
                     t = find(name);
                    while (t != -1)
                    {
                        cout << "a relation already exists with that name try again!!\n";
                        cin >> name;
                        t = find(name);
                    }
                    a.name = name;
                    a.r = r;
                    cout << "the difference is :\n";
                    r->print();
                    rdb.push_back(a);//adding the realion to rdb
                    }
                }
            }
            break;
        case 7://cartesian product
            cout << "enter name of relation1 \n";
            cin >> name;
             t = find(name);//finding index of realtion 1
            if (t == -1)
            {
                cout << "no such relation\n";
                break;
            }
            else
            {
                cout << "enter name of relation2 \n";
                cin >> name;
                 t1 = find(name);//finding index of realtion 2  
                if (t1 == -1)
                {
                    cout << "no such relation\n";
                    break;
                }
                else
                {
                    Relation *r = catersianproduct(rdb[t].r, rdb[t1].r);//finding the cartesian product
                    reln a;
                    a.ini = 1;
                    if(r->getnrecs()!=0)
                    {
                    cout << "enter name for the cartesian product\n";
                    cin >> name;
                     t = find(name);
                    while (t != -1)
                    {
                        cout << "a relation already exists with that name try again!!\n";
                        cin >> name;
                        t = find(name);
                    }
                    a.name = name;
                    a.r = r;
                    cout << "the cartesian product is :\n";
                    r->print();
                    rdb.push_back(a);//adding the realtion to rdb
                    }
                }
            }
            break;
        case 8:
            cout << "enter name of the relation";
            cin >> name;
             t = find(name);//finding the index of the realtion
            if (t == -1)
                cout << "no such relation\n";
            else
            {
                if (!rdb[t].ini)
                    cout << "not initialized\n";
                else
                {
                    string b;
                    list<string> c;
                    cout << "enter strings ,enter -1 to terminate\n";
                    cin >> b;
                    while (b != "-1")//taking the attributes to project
                    {
                        c.push_back(b);
                        cin >> b;
                    }
                    Relation *r = projection(rdb[t].r, c);//finding the projection
                    reln a;
                    a.ini = 1;
                    cout << "enter name for the projection\n";
                    cin >> name;
                     t = find(name);
                    while (t != -1)
                    {
                        cout << "a relation already exists with that name try again!!\n";
                        cin >> name;
                        t = find(name);
                    }
                    a.name = name;
                    a.r = r;
                    cout << "the projection  is :\n";
                    r->print();
                    rdb.push_back(a);//adding the realtion to rdb
                }
            }
            break;
        case 9://slection
            cout << "enter name of the relation for selction\n";
            cin >> name;
             t = find(name);//finding the index of the realtion
            if (t == -1)
                cout << "no such relation\n";
            else
            {
                DNFformula dnf;
                Relation* r=makednf(rdb[t].r, &dnf);// the selected result
                
                reln a;
                a.ini = 1;
                cout << "enter name for the selected result \n";
                cin >> name;
                 t2 = find(name);
                while (t2 != -1)
                {
                    cout << "a relation already exists with that name try again!!\n";
                    cin >> name;
                    t2 = find(name);
                }
                a.name = name;
                a.r = r;
                cout << "the selected ressult   is :\n";
                r->print();
                rdb.push_back(a);//adding the realtion to rdb
            }
            break;
        case 10://rename
            cout << "enter name of the relation \n";
            cin >> name;
             t = find(name);//finding the index of the realtion
            if (t == -1)
                cout << "no such relation\n";
            else
            {
                string name1;//name the be replaced
                cout << "enter the name of the atribute to be replaced \n";
                cin >> name;
                cout << "enter the name of new atrribute name \n";
                cin >> name1;//name to be replaced with
                Relation *r = difference(rdb[t].r, name, name1);
                cout << "the new relation is :\n";
                r->print();
            }
            break;
        case 11://natural join
            cout << "enter name of relation1 \n";
            cin >> name;
             t = find(name);//finding the index of the realiton1
            if (t == -1)
            {
                cout << "no such relation\n";
                break;
            }
            else
            {
                cout << "enter name of relation2 \n";
                cin >> name;
                 t1 = find(name);//finding the index of the realtion2
                if (t1 == -1)
                {
                    cout << "no such relation\n";
                    break;
                }
                else
                {
                    list<string> b;
                    findcommonatri(rdb[t].r, rdb[t1].r, &b);//finding the common attributes

                    Relation *r = naturaljoin(rdb[t].r, rdb[t1].r, b);//finding the natural join
                    reln a;
                    a.ini = 1;
                  
                    cout << "enter name for the natural join\n";
                    cin >> name;
                    int t = find(name);
                    while (t != -1)
                    {
                        cout << "a relation already exists with that name try again!!\n";
                        cin >> name;
                        t = find(name);
                    }
                    a.name = name;
                    a.r = r;
                    cout << "the natural join is  is :\n";
                    r->print();
                    rdb.push_back(a);//adding the result relation in rdb
                }
            }
            break;
        case 12:
            for(int i=0;i<rdb.size();i++)
            {
                cout<<rdb[i].name<<endl;
                rdb[i].r->print();
                cout<<"\n";
            }
            break;
        
        case 13://exit
            cout << "exiting";
            exit(0);
            break;
        default://indvalid choice
            cout << "invalid choice\n";
            break;
        }
        cin.clear();
        
    }
    
}