
//This fiile contains the implementation of basic operations on relations
/*******************************************************************************************/

#include"rdb.h"
#include<iostream>
using namespace std;



Relation *runion(Relation *R1, Relation *R2)//fucntion to find the union of two relations
{
    int j = 0;
    Relation *r = new Relation;
    //checking if the relations are union compatible
    if (R1->nattr != R2->nattr)
    {
        cout << "Relations are not union compatable\n";
        return r;
    }
    for (int i = 0; i < R1->nattr; i++)
    {
        for (j = 0; j < R2->nattr; j++)
        {
            if (R1->attrnames[i] == R2->attrnames[j])//checking if the attributes are of same name
            {
                if ((((*(*((R1->recs).begin()))).getptr())[i])->type() != (((*(*((R2->recs).begin()))).getptr())[j])->type())//checking if the attributes are of same type
                {
                    cout << "Relations are not union compatable\n";
                    return r;
                }
                break;
            }
        }
        if (j == R2->nattr)
        {
            cout << "relations are not union compatible\n";
            return r;
        }
    }
    //if the relations are union compatible then we initialize the union relation
    r->nattr = R1->nattr;
    r->nrecs = (R1->nrecs) + (R2->nrecs);
    for (int i = 0; i < r->nattr; i++)
    {
        r->attrnames.push_back(R1->attrnames[i]);
    }
    // printf("hello\n");
    for (auto it = R1->recs.begin(); it != R1->recs.end(); it++)//adding record of R1 to the union relation
    {
        Record *a = new Record(*(*it));

        r->recs.push_back(a);
    }
    for (auto it = R2->recs.begin(); it != R2->recs.end(); it++)//adding record of R2 to the union relation and also checking if the record is already present in the union relation
    {
        Record *a = new Record(*(*it));
        for(int j=0;j<R2->nattr;j++)//making the attributes in of R1 and R2 in the same order
        {
            for(int i=0;i<R1->nattr;i++)
            {
                if(R1->attrnames[i]==R2->attrnames[j])
                {
                    switch((*it)->getptr()[j]->type())
                    {
                        case 0:
                        a->getptr()[i]=new stringAttribute(((stringAttribute *)(*it)->getptr()[j])->get());                 break;
                        case 1:
                        a->getptr()[i]=new integerAttribute(((integerAttribute *)(*it)->getptr()[j])->get());                 break;
                        case 2:
                        a->getptr()[i]=new floatAttribute(((floatAttribute *)(*it)->getptr()[j])->get());                 break;
                        case 3:
                        a->getptr()[i]=new doubleAttribute(((doubleAttribute *)(*it)->getptr()[j])->get());                 break;
                         
                    }
                }
            }
        }

        auto it1 = r->recs.begin();

        for (; it1 != r->recs.end(); it1++)// checking if the record is already present in the union relation
        {
            int i = 0;
            bool flag = 0;
            if (!((*a) == (*it1)))
                flag = 1;
            if (!flag)
                break;
        }

        if (it1 == r->recs.end())
            r->recs.push_back(a);
        else a->getptr().clear();
    }
    return r;//returning the union relation
}
Relation *difference(Relation *R1, Relation *R2)//fucntion to find the difference of two relations 
{
    Relation *r = new Relation;
    int j = 0;
    //checking if the relations are union compatible
    if (R1->nattr != R2->nattr)
        cout << "Relations are not union compatable\n";
    for (int i = 0; i < R1->nattr; i++)
    {
        for (j = 0; j < R2->nattr; j++)
        {
            if (R1->attrnames[i] == R2->attrnames[j])//checking for same names 
            {
                if ((((*(*((R1->recs).begin()))).getptr())[i])->type() != (((*(*((R2->recs).begin()))).getptr())[j])->type())//checking if the attributes are of same type
                {
                    cout << "Relations are not union compatable\n";
                    return r;
                }
               
                break;
            }
        }
        if (j == R2->nattr)//no such name found in R2
        {
            cout << "relations are not union compatible\n";
            return r;
        }
    }
    //if the relations are union compatible then we initialize the difference relation

    for (int i = 0; i < R1->nattr; i++)
    {
        r->attrnames.push_back(R1->attrnames[i]);
    }
    r->nattr = R1->nattr;
    r->nrecs = 0;
    int flag = 0, flag1 = 0;
    auto it = R1->recs.begin();
    auto it1 = R2->recs.begin();
    for (it = R1->recs.begin(); it != R1->recs.end(); it++)//for eeach record in R1 we check if the relation is present in R2
    {

        for (it1 = R2->recs.begin(); it1 != R2->recs.end(); it1++)
        {

            Record * b= new Record(*(*it1));
            for(int j=0;j<R2->nattr;j++)//making the order of atrributes same for R1 and R2
            {
                for(int i=0;i<R1->nattr;i++)
                {
                    if(R1->attrnames[i]==R2->attrnames[j])
                    {
                        b->getptr()[i]=(*it1)->getptr()[j];
                    }
                }
            }

            flag = 0;
            if (!((*(*it)) == b))
                flag = 1;
            if (!flag)
            {
                b->getptr().clear();
                break;
            }
            if(it1==R2->recs.end())
            {
                b->getptr().clear();
            }
        }
    
        if (it1 == R2->recs.end())//the given relation is not present in R2 hence we take it in the difference relation
        {
            Record *a = new Record(*(*it));
            r->recs.push_back(a);
            r->nrecs++;
        }
        
    }
    return r;//reutrning the difference relation
}


Relation *catersianproduct(Relation *R1, Relation *R2)//function to find the catersian product of two relations
{
    Relation *r = new Relation;
    //cheking if both realtions have no atrribute names in common
    for (int i = 0; i < R1->nattr; i++)
    {
        for (int j = 0; j < R2->nattr; j++)
        {
            if (R1->attrnames[i] == R2->attrnames[j])
            {
                cout << "Cartesian Product not possible as Relations have same attributes names\n";
                return r;
            }
        }
    }
    //if the realtions are cartesian product compatible then we initialize the cartesian product relation
    for (int i = 0; i < R1->nattr; i++)//adding names of relation R1 to the cartesian product 
    {
        r->attrnames.push_back(R1->attrnames[i]);
    }
    for (int i = 0; i < R2->nattr; i++)//adding names of relation R2 to the cartesian product 
    {
        r->attrnames.push_back(R2->attrnames[i]);
    }
    r->nrecs = (R1->nrecs) * (R2->nrecs);// |cartprod|=|R1|*|R2|
    r->nattr = (R1->nattr) + (R2->nattr);//number of attributes in the cartesian product is the sum of the number of attributes in R1 and R2
    auto it = R1->recs.begin();//used for interating over the records of R1
    auto it1 = R2->recs.begin();//used for iterating over the records of R2
    int j = 0, k = 0;
    for (it = R1->recs.begin(); it != R1->recs.end(); it++)//for each record in R1 we cobine it with all thr records in R2 and add the resultant record to the cartesian product relation
    {
        for (it1 = R2->recs.begin(); it1 != R2->recs.end(); it1++)
        {
            Record *a = new Record;
            for (int i = 0; i < R1->nattr; i++)
            {

                int type = (((*(*((R1->recs).begin()))).getptr())[i])->type();
                switch (type)//type checking for the attribute type
                {
                case 0:
                    a->get(((stringAttribute *)(((*it)->getptr())[i]))->get());
                    break;
                case 1:
                    a->get(((integerAttribute *)(((*it)->getptr())[i]))->get());
                    break;
                case 2:
                    a->get(((floatAttribute *)(((*it)->getptr())[i]))->get());
                    break;
                case 3:
                    a->get(((doubleAttribute *)(((*it)->getptr())[i]))->get());
                    break;
                }
            }
            for (int i = 0; i < R2->nattr; i++)
            {

                int type = (((*(*((R2->recs).begin()))).getptr())[i])->type();
                switch (type)//type checking for the attribute type
                {
                case 0:
                    a->get(((stringAttribute *)(((*it1)->getptr())[i]))->get());
                    break;
                case 1:
                    a->get(((integerAttribute *)(((*it1)->getptr())[i]))->get());
                    break;
                case 2:
                    a->get(((floatAttribute *)(((*it1)->getptr())[i]))->get());
                    break;
                case 3:
                    a->get(((doubleAttribute *)(((*it1)->getptr())[i]))->get());
                    break;
                }
            }
            r->recs.push_back(a);//adding the comined record to the cartesian product relation
        }
    }
    return r;
}

Relation *projection(Relation *R, list<string> projectattrs)//fucntion to select given columns from a realtion
{
    vector<int> indices;
    int i;
    Relation *r = new Relation;
    r->nrecs = R->nrecs;//number of records in the projection relation is same as the number of records in the given relation
    //projectattrs.sort();

    for (auto it = projectattrs.begin(); it != projectattrs.end(); it++)//getting which indices to keep
    {

        for (i = 0; i < R->nattr; i++)
        {
            if (R->attrnames[i] == *it)
            {
                indices.push_back(i);
                break;
            }
        }
    }

    r->nattr = indices.size();// the number of attributes in the projection is size of idices vector

    for (auto it = indices.begin(); it != indices.end(); it++)
    {
        r->attrnames.push_back(R->attrnames[*it]);
    }

    for (auto it = R->recs.begin(); it != R->recs.end(); it++)//for each record in the given relation we add the attributes at the indices in the indices vector to the projection relation
    {
        Record *a = new Record;

        for (auto it1 = indices.begin(); it1 != indices.end(); it1++)
        {
            int type = ((*it)->getptr())[*it1]->type();

            switch (type)//type checking for the attribute type
            
            {
            case 0:
                a->get(((stringAttribute *)(((*it)->getptr())[*it1]))->get());
                break;
            case 1:
                a->get(((integerAttribute *)(((*it)->getptr())[*it1]))->get());
                break;
            case 2:
                a->get(((floatAttribute *)(((*it)->getptr())[*it1]))->get());
                break;
            case 3:
                a->get(((doubleAttribute *)(((*it)->getptr())[*it1]))->get());
                break;
            }
        }
        r->recs.push_back(a);
    }
    return r;
}
Relation *runion(Relation *R1, DNFformula *f)//fucntion for selection based on a DNF formula
{
    Relation *r = new Relation;
    auto it = R1->recs.begin();
    auto it1 = f->ops.begin();
    auto it2 = (*it1).begin();
    r->nattr = R1->nattr;//initializing the number of attributes in the relation
    r->nrecs = 0;//initializing the number of records in the relation
    for (int i = 0; i < R1->nattr; i++)//adding the attribute names to the relation
    {

        r->attrnames.push_back(R1->attrnames[i]);
    }

    //for each record in the realtion we check if it satisfies atleast one pruduct term of the dnf formula
    for (it = R1->recs.begin(); it != R1->recs.end(); ++it)//this loop over the records of R1
    {     
        for (it1 = (f->ops).begin(); it1 != (f->ops).end(); ++it1)//this loop over the product terms of the DNF formula
        {
            for (it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)////this loop over the attributes of the product term
            {
                int flag = 0;
                string b = get<0>(*it2);
                for (int i = 0; i < R1->nattr; i++)//finding the name of the attribute in the record
                {
                    if (R1->attrnames[i] == b)
                    {
                        if (((*it)->getptr())[i]->type() == get<2>(*it2)->type())
                        {
                            switch (get<1>(*it2))
                            {
                            case '0':
                                if (*(((*it)->getptr())[i]) == *(get<2>(*it2)))
                                {
                                    flag = 1;//we make flag 1 if the rocrd satisfies oneterm in prduct term
                                }
                                    break;
                            case '1':
                                if (*(((*it)->getptr())[i]) != *(get<2>(*it2)))
                                    flag = 1;
                                     break;
                                     
                            case '2':
                                if (*(((*it)->getptr())[i]) < *(get<2>(*it2)))
                                    flag = 1;
                                    break;
                            case '3':
                                if (*(((*it)->getptr())[i]) <= *(get<2>(*it2)))
                                    flag = 1;
                                    break;
                            case '4':
                                if (*(((*it)->getptr())[i]) > *(get<2>(*it2)))
                                    flag = 1;
                                  
                                 break;
                            case '5':
                                if (*(((*it)->getptr())[i]) >= *(get<2>(*it2)))
                                    flag = 1;
                                  
                                    break;
                            }
                        }
                        break;
                    }
                }
                if (!flag)break;//this means that the record does not satisfy the product term              
            }
            if (it2==((*it1).end()))//if we reach to the end of the product term it means that the record satisfies the product term
            {        
                Record *a = new Record(**it);
                r->recs.push_back(a);
                r->nrecs = (r->nrecs) + 1;
                break;
            }
           
        }
    }
    return r;
}

Relation *difference(Relation *R1, string s1, string s2)//fucntion to rename an attribute in a relation
{

    for (int i = 0; i < R1->nattr; i++)//finding the index of the attribute to be renamed
    {
        if (R1->attrnames[i] == s1)
        {
            R1->attrnames[i] = s2;
            break;
        }
        
    }
    return R1;
}